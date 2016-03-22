import <Utilities/Sequence.sl>;
import <Utilities/Conversion.sl>;
import <Utilities/Math.sl>;

Point ::= (x: int(0), y: int(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), width: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

playerSize := 20;
enemySize := playerSize * 2;

screenWidth := 1000;
screenHeight := 800;
ENEMY ::= (position: Point(0), remainingTime: int(0));

State ::= (time: int(0), playerPosition: Point(0), enemies: ENEMY(1), isDead: bool(0)); //Fill in this struct with the game state members.

//Helpers======================================================================
//Constructor-Functions-------------------------------------------------
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
//----------------------------------------------------------------------
originPoint := point(0,0);
//Colors----------------------------------------------------------------
dBlack := color(0, 0, 0);
dRed := color(255, 0, 0);
dOrange := color(255, 128, 0);
dYellow := color(255, 255, 0);
dGreen := color(0, 255, 0);
dBlue := color(0, 0, 255);
dIndigo := color(70, 0, 130);
dViolet := color(148, 0, 211);
dWhite := color(255, 255, 255);
//----------------------------------------------------------------------
//=============================================================================

//=================Easel=Functions=============================================
playerStart := point(screenWidth / 2, screenHeight / 2);

initialState := (time: 0, isDead: false, playerPosition: playerStart, enemies: []);

newState(I(0), S(0)) := 
	let
		leftKey := none(I.keys = 'D') and some(I.keys = 'A');
		rightKey := some(I.keys = 'D') and none(I.keys = 'A');
		upKey := some(I.keys = 'W') and none(I.keys = 'S');
		downKey := none(I.keys = 'W') and some(I.keys = 'S');
		
		xDiff := 5 when rightKey else -5 when leftKey else 0;
		yDiff := 5 when upKey else -5 when downKey else 0;
		
		newX := max(min(S.playerPosition.x + xDiff, screenWidth), 0);
		newY := max(min(S.playerPosition.y + yDiff, screenHeight), 0);
		
		newPos := point(newX, newY);
		
		killEnemies[i] := S.enemies[i] when not squaresCollide(S.playerPosition, playerSize, S.enemies[i].position, enemySize);
		
		tickEnemies[i] := (position: killEnemies[i].position, remainingTime: killEnemies[i].remainingTime - 1);
		
		enemyTicks[i] := true when tickEnemies[i].remainingTime < 0;	
		
		died := S.isDead or some(enemyTicks);
	in
		S when S.isDead
	else
		(time: S.time + 1, isDead: died, playerPosition: newPos, enemies: makeNewEnemy(S) ++ tickEnemies);

sounds(I(0), S(0)) := 
	let
		newEnemySound := ["boing"] when size(makeNewEnemy(S)) > 0 and not S.isDead else [];
		killSound[i] := "bang" when squaresCollide(S.playerPosition, playerSize, S.enemies[i].position, enemySize) and not S.isDead;
		enemyTicks[i] := true when S.enemies[i].remainingTime <= 0;
		diedSound := ["clap"] when not S.isDead and some(enemyTicks) else [];
	in
		diedSound ++ newEnemySound ++ killSound;

makeNewEnemy(S(0)) :=
	let
		r := randSeq(((S.time * 2000) + (S.playerPosition.x * S.playerPosition.y) + 1 + size(S.enemies)) * 33, 3);
		
		newPosition := point(round(r[2] * (screenWidth - enemySize) + enemySize / 2.0), round(r[3] * (screenHeight - enemySize) + enemySize / 2.0));
		
		newEnemy := 
				[(position: newPosition, remainingTime: 300 - 1)] when head(r) < 0.035
			else
				[];
				
		maxEnemies := ((S.time / 30)) / 10 + 1;
	in
		[] when size(S.enemies) >= maxEnemies
	else
		newEnemy;

squaresCollide(center1(0), side1(0), center2(0), side2(0)) :=
	let
		left1 := center1.x - (side1 / 2);
		right1 := center1.x + (side1 / 2);
		bottom1 := center1.y - (side1 / 2);
		top1 := center1.y + (side1 / 2);
		
		left2 := center2.x - (side2 / 2);
		right2 := center2.x + (side2 / 2);
		bottom2 := center2.y - (side2 / 2);
		top2 := center2.y + (side2 / 2);
	in
		not(left1 > right2 or right1 < left2 or top1 < bottom2 or bottom1 > top2);

drawSquare(center(0), sideLength(0), color(0)) :=
	let
		topLeft := point(center.x - (sideLength / 2), center.y + (sideLength / 2));
		topRight := point(center.x + (sideLength / 2), center.y + (sideLength / 2));
		bottomLeft := point(center.x - (sideLength / 2), center.y - (sideLength / 2));
		bottomRight := point(center.x + (sideLength / 2), center.y - (sideLength / 2));
	in
		[fTri(topLeft, topRight, bottomLeft, color), fTri(bottomRight, topRight, bottomLeft, color)];

drawPlayer(S(0)) := drawSquare(S.playerPosition, playerSize, dBlue);

drawEnemy(enemy(0)) := drawSquare(enemy.position, enemySize, dViolet) ++ [text(Conversion::intToString((enemy.remainingTime + 1) / 30), enemy.position, 16, dWhite)];

images(S(0)) := 
	let
		time := text("Time: " ++ Conversion::intToString(S.time / 30), point(800, 750), 16, dBlue);
		
		player := drawPlayer(S);
	in
		join(drawEnemy(S.enemies)) ++ player ++ [time];

//=============End=Easel=Functions=============================================

//region Random

randHelp(seed(0), count(0), retval(1)) :=
	let
		P1 := 16807;
		N := 2147483647;
		
		nextNum :=(P1 * seed) mod N;
	in
		retval when count = -2
	else
		randHelp(nextNum, count - 1, retval ++ [seed]);

randSeq(seed(0), count(0)) := abs(intToFloat(tail(tail(randHelp(seed, count, [])))) / 2147483647);

randNum(seed(0)) := head(randSeq(seed, 1));

//endregion
