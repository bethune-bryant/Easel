import <Utilities/Sequence.sl>;
import <Utilities/Conversion.sl>;
import <Utilities/Math.sl>;


Point ::= (x: int(0), y: int(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

Ball ::= (xV: float(0), yV: float(0), bRad: int(0), bCenter: Point(0));
Paddle ::= (pPoints: Point(1));
Brick ::= (bPoints: Point(1));
State ::= (sBall: Ball(0), sPaddle: Paddle(0), bricks: Brick(1), clear: bool(0), dead: bool(0));
//-------------------------------------------------------------------------------------------
//Helpers
point(a(0), b(0)) := (x: a, y: b);
color(r(0), g(0), b(0)) := (red: r, green: g, blue: b);
click(cl(0), p(0)) := (clicked: cl, clPoint: p);
input(cl(0), k(1)) := (iClick: cl, keys: k);
segment(e1(0), e2(0), c(0)) := (kind: "segment", vert1: e1, vert2: e2, vert3: originPoint, iColor: c, center: originPoint);
circle(ce(0), rad(0), c(0)) := (kind: "circle", center: ce, radius: rad, iColor: c, vert1: originPoint, vert2: originPoint, vert3: originPoint);
text(mes(1), cen(0), he(0), c(0)) := (kind: "text", center: cen, height: he, iColor: c, message: mes, vert1: originPoint, vert2: originPoint, vert3: originPoint);
disc(ce(0), rad(0), c(0)) := (kind: "disc", center: ce, radius: rad, iColor: c, vert1: originPoint, vert2: originPoint, vert3: originPoint);
fTri(v1(0), v2(0), v3(0), c(0)) := (kind: "triangle", vert1: v1, vert2: v2, vert3: v3, iColor: c, center: originPoint);

graphic(graphicFile(1), c(0), width(0), h(0)) := (kind: "graphic", source: graphicFile, radius: width, height: h, vert1: originPoint, vert2: originPoint, vert3: originPoint, iColor: dBlack, center: c);

ball(c(0), r(0), x(0), y(0)) := (bCenter: c, bRad: r, xV: x, yV: y);
brick(b(1)) := (bPoints: b);
paddle(b(1)) := (pPoints: b);

buildState(ba(0), p(0), br(1), c(0), d(0)) := (sBall: ba, bricks: br, sPaddle: p, clear: c, dead: d);

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

//-------------------
//Static points and stuff
boardTL := point(400, 800);
boardTR := point(1000, 800);
boardBL := point(400, 0);
boardBR := point(1000, 0);

pTL := point(675, 100);
pTR := point(725, 100);
pBL := point(675, 75);
pBR := point(725, 75);

resetTL := point(0, 800);
resetTR := point(200, 800);
resetBL := point(0, 700);
resetBR := point(200, 700);

brick1TL := point(401, 800);
brick1TR := point(499, 800);
brick1BL := point(400, 750);
brick1BR := point(499, 750);
brick1 := brick([brick1TL, brick1TR, brick1BL, brick1BR]);

brick2TL := point(501, 800);
brick2TR := point(599, 800);
brick2BL := point(501, 750);
brick2BR := point(599, 750);
brick2 := brick([brick2TL, brick2TR, brick2BL, brick2BR]);

brick3TL := point(601, 800);
brick3TR := point(699, 800);
brick3BL := point(601, 750);
brick3BR := point(699, 750);
brick3 := brick([brick3TL, brick3TR, brick3BL, brick3BR]);

brick4TL := point(701, 800);
brick4TR := point(799, 800);
brick4BL := point(701, 750);
brick4BR := point(799, 750);
brick4 := brick([brick4TL, brick4TR, brick4BL, brick4BR]);

brick5TL := point(801, 800);
brick5TR := point(899, 800);
brick5BL := point(801, 750);
brick5BR := point(899, 750);
brick5 := brick([brick5TL, brick5TR, brick5BL, brick5BR]);

brick6TL := point(401, 700);
brick6TR := point(499, 700);
brick6BL := point(400, 650);
brick6BR := point(499, 650);
brick6 := brick([brick6TL, brick6TR, brick6BL, brick6BR]);

brick7TL := point(501, 700);
brick7TR := point(599, 700);
brick7BL := point(501, 650);
brick7BR := point(599, 650);
brick7 := brick([brick7TL, brick7TR, brick7BL, brick7BR]);

brick8TL := point(601, 700);
brick8TR := point(699, 700);
brick8BL := point(601, 650);
brick8BR := point(699, 650);
brick8 := brick([brick8TL, brick8TR, brick8BL, brick8BR]);

brick9TL := point(701, 700);
brick9TR := point(799, 700);
brick9BL := point(701, 650);
brick9BR := point(799, 650);
brick9 := brick([brick9TL, brick9TR, brick9BL, brick9BR]);

brick10TL := point(801, 700);
brick10TR := point(899, 700);
brick10BL := point(801, 650);
brick10BR := point(899, 650);
brick10 := brick([brick10TL, brick10TR, brick10BL, brick10BR]);

brick11TL := point(401, 600);
brick11TR := point(499, 600);
brick11BL := point(400, 550);
brick11BR := point(499, 550);
brick11 := brick([brick11TL, brick11TR, brick11BL, brick11BR]);

brick12TL := point(501, 600);
brick12TR := point(599, 600);
brick12BL := point(501, 550);
brick12BR := point(599, 550);
brick12 := brick([brick12TL, brick12TR, brick12BL, brick12BR]);

brick13TL := point(601, 600);
brick13TR := point(699, 600);
brick13BL := point(601, 550);
brick13BR := point(699, 550);
brick13 := brick([brick13TL, brick13TR, brick13BL, brick13BR]);

brick14TL := point(701, 600);
brick14TR := point(799, 600);
brick14BL := point(701, 550);
brick14BR := point(799, 550);
brick14 := brick([brick14TL, brick14TR, brick14BL, brick14BR]);

brick15TL := point(801, 600);
brick15TR := point(899, 600);
brick15BL := point(801, 550);
brick15BR := point(899, 550);
brick15 := brick([brick15TL, brick15TR, brick15BL, brick15BR]);

originPoint := point(-1000,-800);
//cballStart := ball(point(800, 750), 25, 0.0, -0.0);//corner
//vballStart := ball(point(750, 750), 25, 0.0, -0.0);//vertical
//hballStart := ball(point(800, 775), 20, 0.0, -0.0);//horizontal
ballStart := ball(point(700, 200), 20, 10.0, 6.0);
paddleStart := paddle([pTL, pTR, pBL, pBR]);
brickStart := [brick1, brick2, brick3, brick4, brick5, brick6, brick7, brick8, brick9, brick10, brick11, brick12, brick13, brick14, brick15];

//------------
//static images
topBorder := segment(boardTL, boardTR, dBlack);
leftBorder := segment(boardTL, boardBL, dBlack);
rightBorder := segment(boardTR, boardBR, dBlack);
botBorder := segment(boardBL, boardBR, dBlack);

rtBorder := segment(resetTL, resetTR, dGreen);
rlBorder := segment(resetTL, resetBL, dGreen);
rrBorder := segment(resetTR, resetBR, dGreen);
rbBorder := segment(resetBL, resetBR, dGreen);

//-------------
//Main work
staticImgs := [topBorder, leftBorder, rightBorder, botBorder, rtBorder, rlBorder, rrBorder, rbBorder];

initialState := buildState(ballStart, paddleStart, brickStart, false, false);

newState(I(0), S(0)) := 
	let
		ballMove := motionHelper(S); 
		paddleMoveL := paddleHelper(ballMove, false);
		paddleMoveR := paddleHelper(ballMove, true);
	in
		paddleMoveR when equalList(I.keys, "D")
	else
		paddleMoveL when equalList(I.keys, "A")
	else	
		ballMove;// when not(I.keys = "d" or I.keys = "a")

sounds(I(0), S(0)) := ["bang"] when size(motionHelper(S).bricks) < size(S.bricks) else [];

images(S(0)) := staticImgs ++ ballImg(S.sBall) ++ padImg(S.sPaddle) ++ join(brImg(S.bricks));

paddleHelper(S(0), flag(0)) := 
	let
		nextPaddle := paddleMove(S.sPaddle, flag);
	in
		buildState(S.sBall, nextPaddle, S.bricks, S.clear, S.dead);

motionHelper(S(0)) :=
	let
		tempB := S.sBall;
		deadBricksH := indexesOf(brickCollide(tempB,S.bricks), "bvh");
		deadBricks2 := deadBricksH[1] when size(deadBricksH[1]) > 0 
				else deadBricksH[2] when size(deadBricksH[2]) > 0
				else deadBricksH[3] when size(deadBricksH[3]) > 0
				else [];
		deadBricks := S.bricks[deadBricks2];
		
		nextBall := yFlip(xFlip(tempB)) when (vWallCollide(tempB) and hWallCollide(tempB))
		else
			xFlip(tempB) when vWallCollide(tempB) or brickBool(brickCollide(tempB,S.bricks)) = 'h' or pCollide(tempB,S.sPaddle) = 'h'
		else
			yFlip(tempB) when hWallCollide(tempB) or brickBool(brickCollide(tempB,S.bricks)) = 'v' or pCollide(tempB,S.sPaddle) = 'v'
		else
			yFlip(xFlip(tempB)) when brickBool(brickCollide(tempB,S.bricks)) = 'b' or pCollide(tempB,S.sPaddle) = 'b'
		else
			tempB;
	in
		buildState(ballMove(nextBall), S.sPaddle, takeAway(S.bricks, deadBricks), S.clear, S.dead);
		//deadBricks;

//-----------------------------
//region Motion and collision handling

//The next position of the ball, which is its current 'plus' its x and y velocities.
ballMove(B(0)) := 
	let
		nextX := floatToInt(B.bCenter.x + B.xV);
		nextY := floatToInt(B.bCenter.y + B.yV);
		nextCenter := point(nextX, nextY);
	in
		ball(nextCenter, B.bRad, B.xV, B.yV);

xFlip(B(0)) := ball(B.bCenter, B.bRad, -1.0*B.xV, B.yV);
yFlip(B(0)) := ball(B.bCenter, B.bRad, B.xV, -1.0*B.yV);

between(bot(0), top(0), val(0)) := val <= top and val >= bot;


//Detects a purely vertical collision between a ball and a box
vCollision(B(0), L(1)) := 
	let
		box := ballBox(B);
		bTop := box[1].y;
		bBot := box[4].y;
		bLeft := box[3].x;
		bRight := box[2].x;		
		
		rTop := L[1].y;
		rBot := L[4].y;
		rLeft := L[3].x;
		rRight := L[2].x;
	in
		((bTop >= rBot and bBot < rBot) or (bBot <= rTop and bTop > rTop)) and some(between(rLeft, rRight, bLeft...bRight));
	
//Detects a purely horiontal collision between a ball and a box
hCollision(B(0), L(1)) := 
	let
		box := ballBox(B);
		bTop := box[1].y;
		bBot := box[4].y;
		bLeft := box[3].x;
		bRight := box[2].x;		
		
		rTop := L[1].y;
		rBot := L[4].y;
		rLeft := L[3].x;
		rRight := L[2].x;
	in
		((bRight >= rLeft and bLeft < rLeft) or (bLeft <= rRight and bRight > rRight)) and some(between(rBot, rTop, bBot...bTop));

//Detects a corner collision between a ball and a box	
cornerCollision(B(0), L(1)) := 	vCollision(B,L) and hCollision(B,L);

//The four points that correspond to a rectangle surrounding the ball, in order of
//top left, top right, bottom left, bottom right.
ballBox(B(0)) := 
	let
		TL := point((B.bCenter.x - B.bRad), (B.bCenter.y + B.bRad));
		TR := point((B.bCenter.x + B.bRad), (B.bCenter.y + B.bRad));
		BL := point((B.bCenter.x - B.bRad), (B.bCenter.y - B.bRad));
		BR := point((B.bCenter.x + B.bRad), (B.bCenter.y - B.bRad));
	in
		[TL, TR, BL, BR];

//There is a collision between the ball and a vertical wall if
//either the current ball is outside or on the wall, or it will be outside the wall
//in the next frame
vWallCollide(B(0)) := 
	let
		box := ballBox(B);
		nBox := ballBox(ballMove(B));
	in
		((box[1].x <= 400) or (box[2].x >= 1000)
		or		
		(nBox[1].x < 400) or (nBox[2].x > 1000));
		
//There is a collision between the ball and a horizontal wall if
//either the current ball is outside or on the wall, or it will be outside the wall
//in the next frame
hWallCollide(B(0)) := 
	let
		box := ballBox(B);
		nBox := ballBox(ballMove(B));
	in
		((box[3].y <= 0) or (box[2].y >= 800)
		or		
		(nBox[3].y < 0) or (nBox[2].y > 800));
		
//Determines collisions between a ball (and its next position) and a brick		
brickCollide(B(0), R(0)) :=
	let
		box := ballBox(B);
		nBox := ballBox(ballMove(B));
		hc := (hCollision(ballMove(B), R.bPoints) or hCollision(B, R.bPoints));
		vc := (vCollision(ballMove(B), R.bPoints) or vCollision(B, R.bPoints));
		cc := (cornerCollision(ballMove(B), R.bPoints) or cornerCollision(B, R.bPoints));
	in
		'b' when cc
	else
		'v' when vc
	else
		'h' when hc
	else
		'n';
		
brickBool(L(1)) := 
		'b' when some('b'=L) or (some('h'=L) and some('v'=L))
	else
		'v' when none('b'=L) and none('h'=L) and some('v'=L)
	else
		'h' when none('b'=L) and none('v'=L) and some('h'=L)
	else
		'n';
		
paddleMove(P(0), flag(0)) := 
	let
		val := 5;
		x1 := P.pPoints[1].x + val when (flag and not(outOfBoundsR)) else P.pPoints[1].x - val when (not(flag) and not(outOfBoundsL)) else P.pPoints[1].x;
		y1 := P.pPoints[1].y;
		x2 := P.pPoints[2].x + val when (flag and not(outOfBoundsR)) else P.pPoints[2].x - val when (not(flag) and not(outOfBoundsL)) else P.pPoints[2].x;
		y2 := P.pPoints[2].y;
		x3 := P.pPoints[3].x + val when (flag and not(outOfBoundsR)) else P.pPoints[3].x - val when (not(flag) and not(outOfBoundsL)) else P.pPoints[3].x;
		y3 := P.pPoints[3].y;
		x4 := P.pPoints[4].x + val when (flag and not(outOfBoundsR)) else P.pPoints[4].x - val when (not(flag) and not(outOfBoundsL)) else P.pPoints[4].x;
		y4 := P.pPoints[4].y;
		
		TL := point(x1, y1);
		TR := point(x2, y2);
		BL := point(x3, y3);
		BR := point(x4, y4);
		outOfBoundsL := P.pPoints[1].x <= 400;
		outOfBoundsR := P.pPoints[2].x >= 1000;
	in
		paddle([TL, TR, BL, BR]);

//Determines collisions between a ball (and its next position) and a brick		
pCollide(B(0), P(0)) :=
	let
		box := ballBox(B);
		nBox := ballBox(ballMove(B));
		hc := (hCollision(ballMove(B), P.pPoints) or hCollision(B, P.pPoints));
		vc := (vCollision(ballMove(B), P.pPoints) or vCollision(B, P.pPoints));
		cc := (cornerCollision(ballMove(B), P.pPoints) or cornerCollision(B, P.pPoints));
	in
		'b' when cc
	else
		'v' when vc
	else
		'h' when hc
	else
		'n';
		
//endregion

//--------------
//Image handling

//Creates a 'disc' using the ball, B's, center, radius and the color indigo.
ballImg(B(0)) := [graphic("C:\\Tortoise SVN\\Easel\\Easel Games\\ball.png", B.bCenter, B.bRad*2, B.bRad*2)]; //[disc(B.bCenter, B.bRad, dViolet)];

//Draws a filled box with color c from a list of four points, top left, top right, bottom left, bottom right.
boxImg(L(1), c(0)) := 
	let
		TL := L[1];
		TR := L[2];
		BL := L[3];
		BR := L[4];
	in
		[segment(TL, TR, dBlack), segment(TL, BL, dBlack), segment(BL, BR, dBlack), segment(TR, BR, dBlack), 
		fTri(TL, BR, BL, c), fTri(TL, TR, BR, c)];
		
//Draws a solid paddle with paddle color Blue
padImg(P(0)) := boxImg(P.pPoints, dBlue);

//Draws a solid brick with paddle color Orange
brImg(B(0)) := [graphic("C:\\Tortoise SVN\\Easel\\Easel Games\\Brick.png", point((B.bPoints[1].x + B.bPoints[2].x) / 2, (B.bPoints[1].y + B.bPoints[3].y) / 2), B.bPoints[2].x - B.bPoints[1].x, B.bPoints[3].y - B.bPoints[1].y)];


