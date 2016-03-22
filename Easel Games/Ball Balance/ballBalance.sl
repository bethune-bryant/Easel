import <Utilities\\Sequence.sl>;
import <Utilities\\Conversion.sl>;
import <Utilities\\Math.sl>;

Point ::= (x: int(0), y: int(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), width: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

State ::= (time: int(0), position: Point(0), xVelocity: float(0), yVelocity: float(0), angle: float(0), isDead: bool(0), highScore: int(0)); //Fill in this struct with the game state members.

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

initialState := (time: 0, position: point(barCenter.x, barCenter.y + ballRadius), xVelocity: 0.0, yVelocity: 0.0, angle: 0.0);

gravity := -0.25;

newState(I(0), S(0)) := 
	let
		newAngle := 
			S.angle - 0.1 when some(I.keys = 'D')
		else
			S.angle + 0.1 when some(I.keys = 'A')
		else
			S.angle;
			
		limitedAngle := min(max(-pi/2, newAngle), pi/2);
		
		ballPosition := point(round(S.position.x + S.xVelocity), round(S.position.y + S.yVelocity));
		
		newYVel := S.yVelocity + gravity;
		newXVel := S.xVelocity;
		
		newTime := S.time + 1;
				
		died := (ballPosition.y - ballRadius) <= 0;
	in
		(time: newTime, position: ballPosition, xVelocity: newXVel, yVelocity: newYVel, angle: limitedAngle, isDead: died, highScore: max(newTime, S.highScore)) when not S.isDead
	else
		S;

sounds(I(0), S(0)) := ["ding"] when I.iClick.clicked else [];

barCenter := point(500, 400);
barLength := 200;
barColor := dBlack;
ballRadius := 15;
ballColor := dRed;

barRightPoint(angle(0)) := 
	point(round(barCenter.x + cos(angle) * barLength / 2), round(barCenter.y + sin(angle) * barLength / 2)); 
	
barLeftPoint(angle(0)) := 
	point(round(barCenter.x + cos(pi + angle) * barLength / 2), round(barCenter.y + sin(pi + angle) * barLength / 2)); 

images(S(0)) := 
	let
		time := text("Time: " ++ Conversion::intToString(S.time / 30), point(800, 600), 16, dBlue);
		highScore := text("HighScore: " ++ Conversion::intToString(S.highScore / 30), point(800, 625), 16, dBlue);
		
		bar := segment(barRightPoint(S.angle), barLeftPoint(S.angle), barColor);
		ball := disc(S.position, ballRadius, ballColor);
		
		resetButton := 
				[] when not S.isDead
			else
				[disc(point(200, 600), 50, dRed), text("Click to\n Reset!", point(200, 600), 12, dWhite)];
	in
		resetButton ++ [highScore, time, bar, ball];

//=============End=Easel=Functions=============================================
		
