import <Utilities\\Sequence.sl>;
import <Utilities\\Conversion.sl>;
import <Utilities\\Math.sl>;

//region Types

Point ::= (x: int(0), y: int(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), width: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

Dart ::= (loc: Point(0), dangle: float(1), vel: float(0));
Box ::= (p1: Point(0), p2: Point(0), p3: Point(0), p4: Point(0), angle: float(0));
State ::= (time: int(0), box: Box(0), darts: Dart(1), score: int(0));

//endregion


//region Helpers======================================================================
//region Constructor-Functions-------------------------------------------------
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

dart(p(0), a(1), v(0)) := (loc: p, dangle: dAngle(p), vel: v);
box(p(1), a(0)) := (p1: p[1], p2: p[2], p3: p[3], p4: p[4], angle: a);
buildState(b(0), d(1), t(0), s(0)) := (time: t, box: b, darts: d, score: s);
//endregion----------------------------------------------------------------------

originPoint := point(500,400);
PI := Math::pi;

//region static images
borderTL := point(200, 700);
borderTR := point(800, 700);
borderBL := point(200, 100);
borderBR := point(800, 100);

borderTop := segment(borderTL, borderTR, dBlack);
borderLeft := segment(borderTL, borderBL, dBlack);
borderRight := segment(borderBR, borderTR, dBlack);
borderBot := segment(borderBL, borderBR, dBlack);

staticImages := [borderTop, borderLeft, borderRight, borderBot];
deadImage := [text("Loser.", originPoint, 50, dRed)];
//boxStart := box([originPoint, originPoint, originPoint, originPoint], 0.0);
dartStart := [dart(originPoint, dAngle(borderBR), 1.0)];
/*dartStart := [dart(point(250, 100), dAngle(point(250, 100)), 5.0),
			dart(point(550, 100), dAngle(point(550, 100)), 5.0),
			dart(point(250, 700), dAngle(point(250, 700)), 5.0),
			dart(point(500, 700), dAngle(point(500, 700)), 5.0),
			dart(point(200, 100), dAngle(point(200, 100)), 5.0),
			dart(point(200, 600), dAngle(point(200, 600)), 5.0),
			dart(point(800, 430), dAngle(point(800, 430)), 5.0),
			dart(point(800, 100), dAngle(point(800, 100)), 5.0)];*/
//endregion

//region Colors----------------------------------------------------------------
dBlack := color(0, 0, 0);
dRed := color(255, 0, 0);
dOrange := color(255, 128, 0);
dYellow := color(255, 255, 0);
dGreen := color(0, 255, 0);
dBlue := color(0, 0, 255);
dIndigo := color(70, 0, 130);
dViolet := color(148, 0, 211);
dWhite := color(255, 255, 255);
//endregion----------------------------------------------------------------------

//region Random----------------------------------------------------------------
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
//endregion----------------------------------------------------------------------
//endregion=============================================================================


//=================Easel=Functions=============================================

initialState := buildState(boxStart, dartStart, 0, 0);

newState(I(0), S(0)) := 
	let
		angle:= 32.0;
		rotateLeft := rotate(S.box, Math::pi / angle);
		rotateRight := rotate(S.box, Math::pi / angle * (-1));
		newDarts := dartMove(S.darts);
		deathDarts := inCenter(S.darts);
		collided := some(dartCollide(S.darts, S.box.p1, S.box.p4));
		alive := S.time >= 0;
	in
		buildState(boxStart, dartStart, -5, -10) when collided
	else
		buildState(S.box, newDarts ++ makeDart(S.time, floatToInt(S.box.angle)), S.time + 1, S.score) when timeHelper(S.time, 150) and alive
	else
		buildState(rotateLeft, newDarts, S.time + 1, S.score) when equalList(I.keys, "A") and alive
	else
		buildState(rotateRight, newDarts, S.time + 1, S.score) when equalList(I.keys, "D") and alive
	else
		initialState when equalList(I.keys, "X")
	else
		buildState(S.box, newDarts, S.time + 1, S.score) when none(deathDarts) and alive
	else
		removeDarts(S) when alive
	else
		S;

sounds(I(0), S(0)) := ["ding"] when I.iClick.clicked else [];

images(S(0)) := staticImages ++ drawDart(S.darts) ++ boxImg(S.box) ++ [text("Score: " ++ Conversion::intToString(S.score), point(900, 385), 20, dBlue), text("Time: " ++ Conversion::intToString(S.time/30), point(900, 415), 20, dBlue)] when S.time >= 0
	else
		staticImages ++ deadImage;

//=============End=Easel=Functions=============================================

//region box handling
boxSize := 25;
len := 35;
boxTL := point(floatToInt(500 - cos(Math::pi * 0.75) * len), floatToInt(400 + sin(Math::pi * 0.75) * len));//point(500 - boxSize, 400 + boxSize);
boxTR := point(floatToInt(500 + cos(Math::pi * 0.75) * len), floatToInt(400 + sin(Math::pi * 0.75) * len));//point(500 + boxSize, 400 + boxSize);
boxBL := point(floatToInt(500 - cos(Math::pi * 0.75) * len), floatToInt(400 - sin(Math::pi * 0.75) * len));//point(500 - boxSize, 400 - boxSize);
boxBR := point(floatToInt(500 + cos(Math::pi * 0.75) * len), floatToInt(400 - sin(Math::pi * 0.75) * len));//point(500 + boxSize, 400 - boxSize);

boxStart := buildBox(0, Math::pi/4);//box(boxTL, boxTR, boxBL, boxBR);
boxL := segment(boxTL, boxBL, dOrange);
boxR := segment(boxTR, boxBR, dOrange);
boxB := segment(boxBL, boxBR, dOrange);

rotate(B(0), A(0)) := buildBox(B.angle, A);

buildBox(oA(0), A(0)) :=
	let
		origin := point(500, 400);
		newAngle := oA + A;
		length := 30;
		TL := point(floatToInt(origin.x + cos(newAngle) * length), floatToInt(origin.y + sin(newAngle) * length));
		TR := point(floatToInt(origin.x + cos(newAngle + Math::pi / 2) * length), floatToInt(origin.y + sin(newAngle + Math::pi / 2) * length));
		BL := point(floatToInt(origin.x + cos(newAngle + Math::pi) * length), floatToInt(origin.y + sin(newAngle + Math::pi) * length));
		BR := point(floatToInt(origin.x + cos(newAngle + 3 * Math::pi / 2) * length), floatToInt(origin.y + sin(newAngle + 3 * Math::pi / 2) * length));
	in
		box([TL, TR, BL, BR], newAngle);
//endregion

//region dart handling
makeDart(time(0), angle(0)) := 
	let
		vel := 3.0;
		derp := floatToInt(abs(randSeq(time + angle, 2)) * 600);
		wall := derp[1] mod 4;
		position := derp[2] mod 600;
		nose :=	point(position + 200, 700) when wall = 0
		else
			point(position + 200, 100) when wall = 1
		else
			point(800, position + 100) when wall = 2
		else
			point(200, position + 100) when wall = 3
		else
			originPoint; 
	in
		[dart(nose, dAngle(nose), vel)];

timeHelper(t(0), val(0)) := 
	let
		rem := t mod val when t <= 150 else t mod val / 2 + 1 when t <= 300 else t mod val / 4 + 1;
	in
		rem = 1;

dAngle(P(0)) :=
	let
		dX := intToFloat(originPoint.x - P.x);
		dY := intToFloat(originPoint.y - P.y);
		xAng := atan(dX / dY) when dY > 0 else -atan(dX / dY) when dY < 0 else -1 when dX < 0 else 1;
		yAng := atan(dY / dX) when dX > 0 else -atan(dY / dX) when dX < 0 else -1 when dY < 0 else 1;
	in		
		//[dX, dY, atan(dX / dY), atan(dY / dX)];	
		//[dX,dY];
		[xAng, yAng];
		
dartMove(D(0)) := 
	let
		newX := floatToInt(D.loc.x + D.vel * D.dangle[1]);
		newY := floatToInt(D.loc.y + D.vel * D.dangle[2]);
		newL := point(newX, newY);
	in
		dart(newL, D.dangle, D.vel);
		
inCenter(D(0)) :=
	let
		tol := 7;
		x := (D.loc.x < (originPoint.x + tol)) and (D.loc.x > (originPoint.x - tol));
		y := (D.loc.y < (originPoint.y + tol)) and (D.loc.y > (originPoint.y - tol));
	in
		x and y;

removeDarts(S(0)) :=
	let
		deadDarts[i] := S.darts[i] when inCenter(S.darts)[i] foreach i within 1 ... size(S.darts); 
		liveDarts := takeAway(S.darts, deadDarts);
	in
		buildState(S.box, liveDarts, S.time + 1, S.score + size(deadDarts));

dartCollide(dart(0), left(0), right(0)) :=
	let
		yrange := dart.loc.y - 3 ... dart.loc.y + 3;
		xrange := dart.loc.x - 3 ... dart.loc.x + 3;
		slope := line(left, right)[1];
		yInt := line(left, right)[2];
	in
		 some(yrange = slope * xrange + yInt) when not(undef(left,right)) else some(xrange = left.x);
pt1 := point(521, 400);
pt2 := point(500, 421);
dt1 := dart(pt1, dAngle(pt1), 1.0);
dt2 := dart(pt2, dAngle(pt2), 1.0);
undef(p1(0), p2(0)) := p1.x = p2.x;
line(p1(0), p2(0)) := 
	let
		y1 := p1.y;
		y2 := p2.y;
		x1 := p1.x;
		x2 := p2.x;
		slope := (y1 - y2) / (x1 - x2) when (x1 /= x2) else 0;
		yInt := -slope * x1 + y1;
	in
		[slope, yInt];

//endregion

//region image handling

boxImg(B(0)) := 
	let
		origin := point(500, 400);
		c := disc(origin, 5, dBlue);
		boxL := segment(B.p1, B.p2, dGreen);
		boxR := segment(B.p2, B.p3, dGreen);
		boxB := segment(B.p3, B.p4, dGreen);
		boxNO := segment(B.p1, B.p4, dOrange);
		box1 := segment(B.p1, origin, dOrange);
		box2 := segment(B.p2, origin, dOrange);
		box3 := segment(B.p3, origin, dOrange);
		box4 := segment(B.p4, origin, dOrange);
	in
		[boxL, boxR, boxB, boxNO];


drawDart(D(0)) := disc(D.loc, 5, dIndigo);

//endregion

