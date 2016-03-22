import <Utilities\\Sequence.sl>;
import <Utilities\\Conversion.sl>;
import <Utilities\\Math.sl>;

Point ::= (x: int(0), y: int(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), width: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

State ::= (time: int(0), playerPos: Point(0), lastBombDrop: int(0), remainingBullets: int(0), bombs: BOMB(1), animations: ANIMATION(1));

//region My Types--------------------

ANIMATION ::= (frames: char(2), animationCenter: Point(0), rate: int(0), loop: bool(0), startTime: int(0));
getStartTime(inAni(0)) := inAni.startTime;


BOMB ::= (bombPosition: Point(0), bombVelocity: float(0), bombAcceleration: float(0));
newBomb(posX(0), posY(0), vel(0), acc(0)) := (bombPosition: point(posX, posY), bombVelocity: vel, bombAcceleration: acc);

//endregion----------------------------------

//-------------------------------------------------------------------------------------------
//Helpers
point(a(0), b(0)) := (x: a, y: b);
color(r(0), g(0), b(0)) := (red: r, green: g, blue: b);
click(cl(0), p(0)) := (clicked: cl, clPoint: p);
input(cl(0), k(1)) := (iClick: cl, keys: k);
segment(e1(0), e2(0), c(0)) := (kind: "segment", vert1: e1, vert2: e2, iColor: c);
circle(ce(0), rad(0), c(0)) := (kind: "circle", center: ce, radius: rad, iColor: c);
text(mes(1), cen(0), he(0), c(0)) := (kind: "text", center: cen, height: he, iColor: c, message: mes);
disc(ce(0), rad(0), c(0)) := (kind: "disc", center: ce, radius: rad, iColor: c);
fTri(v1(0), v2(0), v3(0), c(0)) := (kind: "triangle", vert1: v1, vert2: v2, vert3: v3, iColor: c);
graphic(graphicFile(1), c(0), w(0), h(0)) := (kind: "graphic", source: graphicFile, radius: 0, height: h, width: w, center: c);

originPoint := point(0,0);
//----------------------------------------------------------------------
//Colors
dBlack := color(0, 0, 0);
dRed := color(255, 0, 0);
dOrange := color(255, 128, 0);
dYellow := color(255, 255, 0);
dGreen := color(0, 255, 0);
dBlue := color(0, 0, 255);
dIndigo := color(70, 0, 130);
dViolet := color(148, 0, 211);
//---------


//=================Easel Functions=======================================================
initialState := (playerPos: (x: 0, y: 400), bombs:[], animations: []);

newState(I(0), S(0)) := 
	let
		xDiff := -3 when some(I.keys = 'A') else 3 when some(I.keys = 'D') else 0;
		yDiff := -5 when some(I.keys = 'S') else 5 when some(I.keys = 'W') else 0;
		
		newBombs := 
				S.bombs when S.time < (S.lastBombDrop + BombRecharge) 
			else
				S.bombs ++ [newBomb(S.playerPos.x, S.playerPos.y - 60, -5.0, -9.8)] when some(I.keys = 'B')
			else 
				S.bombs;
				
		newBombDropTime := S.time when size(newBombs) > size(S.bombs) else S.lastBombDrop;
		
		movedBombs := updateBombs(S, newBombs);
		
		newExplosions := bombExplosions(S, newBombs);
		
		newAnimations := removeExpiredAnimations(S, S.animations) ++ newExplosions;
	in
		(time: S.time + 1, lastBombDrop: newBombDropTime, playerPos: (x: S.playerPos.x + 5 + xDiff, y: S.playerPos.y + yDiff), bombs: movedBombs, animations: newAnimations);

sounds(I(0), S(0)) := 
	let
		music := ["C:\\Tortoise SVN\\Easel\\Easel Games\\Plane Game\\Sounds\\mp.wav"] when (S.time mod (38 * 30 - 15)) = 2 else [];
		bang := [imagePath ++ "shoot.wav"] when some((S.time) = getStartTime(S.animations)) else [];
		ding := ["ding"] when I.iClick.clicked else [];
	in
		music ++ bang ++ ding;

images(S(0)) := backgroundTiles(S) ++ bombImages(S) ++ playerImage(S) ++ renderAnimation(S) ++ drawAmmo(S) ++ timeImage(S) ;//, graphic(imagePath ++ "player.png", S.playerPos, 0, 0)];

//=============End=Easel Functions=======================================================

BombRecharge := 60;

imagePath := "..\\..\\..\\..\\Easel Games\\Plane Game\\";

drawingPosition(S(0), thingX(0)) := thingX - S.playerPos.x + 500;

//backgroundTiles(S(0))[i] := graphic(imagePath ++ "tile" ++ intToString(i) ++ ".png", point(drawingPosition(S, ((i - 1) * 1000)), 400), 1000, 800) foreach i within 1 ... 12;
backgroundTiles(S(0)) := [graphic(imagePath ++ "tile" ++ intToString(((S.playerPos.x / 1000) mod 12) + 1) ++ ".png", point(drawingPosition(S, ((S.playerPos.x / 1000) mod 12) * 1000 + (12000 * (S.playerPos.x / 12000))), 400), 1000, 800),
							  graphic(imagePath ++ "tile" ++ intToString((((S.playerPos.x + 1000) / 1000) mod 12) + 1) ++ ".png", point(drawingPosition(S, (((S.playerPos.x + 1000) / 1000) mod 12) * 1000 + (12000 * ((S.playerPos.x + 1000) / 12000))), 400), 1000, 800)]; 

playerImage(S(0)) := [graphic(imagePath ++ "player.png", point(500, S.playerPos.y), 150, 67)];
bombImages(S(0))[i] := graphic(imagePath ++ "bomb.png", point(drawingPosition(S, S.bombs[i].bombPosition.x), S.bombs[i].bombPosition.y), 20, 52);
timeImage(S(0)) := [text("Game Time: " ++ intToString(S.time / 30), point(900, 750), 18, dRed)];

drawAmmo(S(0)) := 
		[graphic(imagePath ++ "bomb.png", point(20, 750), 20, 52), text("Bomb Ready!", point(100, 750), 18, dRed)] when S.time >= (S.lastBombDrop + BombRecharge) 
	else
		[];

explosionFiles[i] := imagePath ++ "Explosion\\frame" ++ intToString(i) ++ ".png" foreach i within 1 ... 17;

makeExplosion(S(0), inX(0), inY(0)) :=
		(frames: explosionFiles, animationCenter: point(inX, inY), rate: 2, loop: false, startTime: S.time + 1);

updateBombs(S(0), inBombs(1))[i] := 
	let
		movedBomb := newBomb(inBombs[i].bombPosition.x, round(inBombs[i].bombPosition.y + inBombs[i].bombVelocity), inBombs[i].bombVelocity, inBombs[i].bombAcceleration);
	in
		movedBomb when drawingPosition(S, inBombs[i].bombPosition.x) > 0 and drawingPosition(S, inBombs[i].bombPosition.x) < 1000 and inBombs[i].bombPosition.y > 100;

bombExplosions(S(0), inBombs(1))[i] := 
	let
		movedBomb := newBomb(inBombs[i].bombPosition.x, round(inBombs[i].bombPosition.y + inBombs[i].bombVelocity), inBombs[i].bombVelocity, inBombs[i].bombAcceleration);
	in
		makeExplosion(S, inBombs[i].bombPosition.x, inBombs[i].bombPosition.y) when not(drawingPosition(S, inBombs[i].bombPosition.x) > 0 and drawingPosition(S, inBombs[i].bombPosition.x) < 1000 and inBombs[i].bombPosition.y > 100);

renderAnimation(S(0))[i] :=
	let
		inAni := S.animations[i];
	
		currentFrame := inAni.frames[(((S.time - inAni.startTime) / inAni.rate) mod size(inAni.frames)) + 1];
	in
		graphic(currentFrame, point(drawingPosition(S, inAni.animationCenter.x), inAni.animationCenter.y), 0, 0);
		
removeExpiredAnimations(S(0), inAnimations(1))[i] :=
	inAnimations[i] when inAnimations[i].loop or (((S.time - inAnimations[i].startTime) / inAnimations[i].rate) < (size(inAnimations[i].frames) - 1));
