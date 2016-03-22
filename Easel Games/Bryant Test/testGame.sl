import <Utilities/Sequence.sl>;
import <Utilities/Conversion.sl>;
import <Utilities/Math.sl>;


Point ::= (x: int(0), y: int(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

State ::= (balls: Ball(1));

Ball ::= (ballCenter: Point(0), ballRad: int(0), bxv: float(0), byv: float(0));

//----------------------------------------------------------------------
//Colors
dBlack := newColor(0, 0, 0);
dRed := newColor(255, 0, 0);
dOrange := newColor(255, 128, 0);
dYellow := newColor(255, 255, 0);
dGreen := newColor(0, 255, 0);
dBlue := newColor(0, 0, 255);
dIndigo := newColor(70, 0, 130);
dViolet := newColor(148, 0, 211);

//Constructors
newPoint(a(0), b(0)) := (x: a, y: b);
newColor(r(0), g(0), b(0)) := (red: r, green: g, blue: b);
newClick(cl(0), p(0)) := (clicked: cl, clPoint: p);
newInput(cl(0), k(1)) := (iClick: cl, keys: k);
newSeg(e1(0), e2(0), c(0)) := (kind: "segment", vert1: e1, vert2: e2, iColor: c, vert3: originPoint, center: originPoint);
newCirc(ce(0), rad(0), c(0)) := (kind: "circle", center: ce, radius: rad, iColor: c, vert1: originPoint, vert2: originPoint, vert3: originPoint);
newText(mes(1), cen(0), he(0), c(0)) := (kind: "text", center: cen, height: he, iColor: c, message: mes, vert1: originPoint, vert2: originPoint, vert3: originPoint);
newDisc(ce(0), rad(0), c(0)) := (kind: "disc", center: ce, radius: rad, iColor: c, vert1: originPoint, vert2: originPoint, vert3: originPoint);
newGraphic(ce(0), file(1)) := (kind: "graphic", center: ce, source: file, iColor: dViolet, vert1: originPoint, vert2: originPoint, vert3: originPoint);
newBall(c(0), r(0), x(0), y(0)) := (ballCenter: c, ballRad: r, bxv: x, byv: y);
buildState(ba(1)) := (balls: ba);


//Border lines and other static stuff
topLeft := newPoint(400, 0);
topRight := newPoint(1000, 0);
bottomLeft := newPoint(400, 1000);
bottomRight := newPoint(1000, 1000);
originPoint := newPoint(0,0);

ballStart := [newBall(newPoint(900,600), 15, 4.0, -6.0), newBall(newPoint(100,500), 10, 7.0, -9.0), newBall(newPoint(600,200), 8, 8.0, 2.0), newBall(newPoint(700,200), 20, -4.0, 6.0)];

//ballStart[i] := newBall(newPoint(i,500), 10, 4.0, -6.0) foreach i within (10 ... 20) * 15;

xFlip(B(0)) := 
	let
		xV := -1.0 * B.bxv;
		yV := B.byv;
	in
		newBall(B.ballCenter, B.ballRad, xV, yV);
		
yFlip(B(0)) := 
	let
		yV := -1.0 * B.byv;
		xV := B.bxv;
	in
		newBall(B.ballCenter, B.ballRad, xV, yV);

ballRight(ball(0)) := ball.ballCenter.x + ball.ballRad;
ballLeft(ball(0)) := ball.ballCenter.x - ball.ballRad;
ballTop(ball(0)) := ball.ballCenter.y + ball.ballRad;
ballBottom(ball(0)) := ball.ballCenter.y - ball.ballRad;

checkVerticalBoundaries(ball(0)) := ballTop(ball) >= 800 or ballBottom(ball) <= 0;
		
checkHorizontalBoundaries(ball(0)) := ballRight(ball) >= 1000 or ballLeft(ball) <= 0;

ballMove(B(0),otherBalls(1)) := 
	let
		xBall := xFlip(B) when checkHorizontalBoundaries(B) else B;
		yBall := yFlip(xBall) when checkVerticalBoundaries(xBall) else xBall;
	in
		newBall(newPoint(floatToInt(B.ballCenter.x + yBall.bxv), floatToInt(B.ballCenter.y + yBall.byv)), B.ballRad, yBall.bxv, yBall.byv);

mySign(x(0)) := 1 when x >= 0 else -1;

speedUp(B(0)) := newBall(B.ballCenter, B.ballRad, B.bxv + mySign(floatToInt(B.bxv)), B.byv + mySign(floatToInt(B.byv)));

slowDown(B(0)) := newBall(B.ballCenter, B.ballRad, B.bxv - mySign(floatToInt(B.bxv)), B.byv - mySign(floatToInt(B.byv)));
		
ballImg(B(0)) := newGraphic(B.ballCenter, "C:\\Tortoise SVN\\Easel\\Easel Games\\Craps\\dice_and_dominoes_free_preview3.png");

initialState := buildState(ballStart);

newState(I(0), S(0)) := 
	let
		newPos[i] := ballMove(S.balls[i], drop(S.balls, i));
	in
		S when some(I.keys = 'P')
	else
		buildState(speedUp(newPos)) when some(I.keys = 'W')
	else
		buildState(slowDown(newPos)) when some(I.keys = 'S')
	else
		buildState(newPos);

images(S(0)) := [newDisc(newPoint(500, 400), 641, dBlack)] ++ ballImg(S.balls);

sounds(I(0), S(0)) := 
		[] when some(I.keys = 'P')
	else
		["ding"] when some(checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls))
	else
		[];

