import <Utilities\\Sequence.sl>;
import <Utilities\\Conversion.sl>;
import <Utilities\\Math.sl>;

Point ::= (x: int(0), y: int(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), width: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

Box ::= (p1: Point(0), p2: Point(0), p3: Point(0), p4: Point(0), angle: float(0));

Dart ::= (d1: Point(0), d2: Point(0), d3: Point(0), velocity: float(0));

State ::= (time: int(0), catcher: Box(0), darts: Dart(1), score: int(0), sAnim: Image(1)); //Fill in this struct with the game state members.

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
buildState(b(0), d(1), s(0), a(1), t(0)) := (time: t, catcher: b, darts: d, score: s, sAnim: a);
box(a(0), b(0), c(0), d(0), ang(0)) := (p1: a, p2: b, p3: c, p4: d, angle: ang);
dart(a(0), b(0), c(0), v(0)) := (d1: a, d2: b, d3: c, velocity: v);

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
//----------------------------------------------------------------------

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

//endregion

//region box start
boxSize := 25;
len := 35;
boxTL := point(floatToInt(500 - cos(Math::pi * 0.75) * len), floatToInt(400 + sin(Math::pi * 0.75) * len));//point(500 - boxSize, 400 + boxSize);
boxTR := point(floatToInt(500 + cos(Math::pi * 0.75) * len), floatToInt(400 + sin(Math::pi * 0.75) * len));//point(500 + boxSize, 400 + boxSize);
boxBL := point(floatToInt(500 - cos(Math::pi * 0.75) * len), floatToInt(400 - sin(Math::pi * 0.75) * len));//point(500 - boxSize, 400 - boxSize);
boxBR := point(floatToInt(500 + cos(Math::pi * 0.75) * len), floatToInt(400 - sin(Math::pi * 0.75) * len));//point(500 + boxSize, 400 - boxSize);

boxStart := buildBox(0, Math::pi/4);//box(boxTL, boxTR, boxBL, boxBR);
dartStart := dart(point(-500, 0), point(-500, 0), point(-500, 0), 0.0);
boxL := segment(boxTL, boxBL, dOrange);
boxR := segment(boxTR, boxBR, dOrange);
boxB := segment(boxBL, boxBR, dOrange);

//endregion

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
		box(TL, TR, BL, BR, newAngle); 

rotate(B(0), A(0)) := buildBox(B.angle, A);

//region dart
makeDart(time(0), angle(0)) := 
	let
		width := 2;
		length := 3;
		origin := point(-1, -1);
		wall := time mod 4;
		position := abs(floatToInt(angle * 574336.01258 + time)) mod 600;
		nose :=	point(position + 200, 700) when wall = 0
		else
			point(position + 200, 100) when wall = 1
		else
			point(800, position + 100) when wall = 2
		else
			point(200, position + 100) when wall = 3
		else
			origin;
			
		fin1 :=	point(nose.x - width, nose.y + length) when wall = 0
		else
			point(nose.x - width, nose.y - length) when wall = 1
		else
			point(nose.x + length, nose.y + width) when wall = 2
		else
			point(nose.x - length, nose.y + width) when wall = 3
		else
			origin;
			
		fin2 :=	point(nose.x + width, nose.y + length) when wall = 0
		else
			point(nose.x + width, nose.y - length) when wall = 1
		else
			point(nose.x + length, nose.y - width) when wall = 2
		else
			point(nose.x - length, nose.y - width) when wall = 3
		else
			origin;
	in
		[dart(nose, fin1, fin2, 0.01)];
		
dartMove(D(0)) := 
	let
		origin := point(500,400);
		deltaX := D.d1.x - origin.x;
		deltaY := D.d1.y - origin.y;
	in
		[1,0] when deltaY = 0 else [0,1] when deltaX = 0 else normalize([deltaX / deltaY, deltaY / deltaX]);

normalize(V(1))[i] := 
	let 
		vNorm := sqrt(sum(V^2));
	in
		V[i] / vNorm foreach i within 1 ... size(V);
//endregion
		
//=============================================================================

//=================Easel=Functions=============================================

initialState := buildState(boxStart, [dartStart], 0, staticImages, 0);
//buildState(b, d, s, a, t) := (time: t, catcher: b, darts: d, score: s, sAnim: a);
newState(I(0), S(0)) := 
	let
		angle:= 32.0;
		rotateLeft := rotate(S.catcher, Math::pi / angle);
		rotateRight := rotate(S.catcher, Math::pi / angle * (-1));
	in
		buildState(rotateLeft, S.darts, 0, staticImages, S.time + 1) when equalList(I.keys, "A")
	else
		buildState(rotateRight, S.darts, 0, staticImages, S.time + 1) when equalList(I.keys, "D")
	else
		buildState(S.catcher, S.darts ++ makeDart(S.time, S.catcher.angle), 0, staticImages, S.time + 1) when S.time mod 80 = 3
	else
		buildState(S.catcher, S.darts, 0, staticImages, S.time + 1);

sounds(I(0), S(0)) := ["ding"] when I.iClick.clicked else [];

images(S(0)) := boxImg(S.catcher) ++ join(dartImg(S.darts)) ++ staticImages ++ [text("Time: " ++ Conversion::intToString(S.time / 30), point(900, 600), 15, dBlue)];

//=============End=Easel=Functions=============================================

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
		
dartImg(D(0)) := 
	let
		c := disc(D.d1, 5, dBlack);
	in
		[c];
//endregion
