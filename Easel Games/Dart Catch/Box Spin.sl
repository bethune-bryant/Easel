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
//endregion----------------------------------------------------------------------

originPoint := point(0,0);

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

//endregion=============================================================================


//=================Easel=Functions=============================================

State ::= (length: int(0), angle: float(0)); //Fill in this struct with the game state members.

initialState := (length: 10, angle: pi/4);

newState(I(0), S(0)) := 
	let 
		reset := subset("X", I.keys);
		rotatedBox := handleRot(S, I);
		scaledBox := handleScale(rotatedBox, I);
	in
		scaledBox when not reset else initialState;

sounds(I(0), S(0)) := ["ding"] when I.iClick.clicked else [];

images(S(0)) := drawBox(buildBox(S.length, S.angle));

//=============End=Easel=Functions=============================================
buildState(l(0), a(0)) := (length: l, angle: a);

handleRot(S(0), I(0)) :=
	let
		noreset := not(subset("X", I.keys));
		a := subset("A", I.keys);
		d := subset("D", I.keys);
	in 
		buildState(S.length, S.angle + pi/32) when a and not(d) and noreset 
	else 
		buildState(S.length, S.angle - pi/32) when d and not(a) and noreset
	else
		S;

handleScale(S(0), I(0)) :=
	let
		noreset := not(subset("X", I.keys));
		w := subset("W", I.keys);
		s := subset("S", I.keys);
		tooBig := S.length >= 500;
		tooSmall := S.length <= 10;
	in 
		buildState(S.length + 4, S.angle) when w and not(s) and not(tooBig) and noreset
	else
		buildState(S.length - 4, S.angle) when s and not(w) and not(tooSmall) and noreset
	else
		S;

buildBox(length(0), angle(0)) :=
	let
		armLength := sqrt(length^2/2);
		rotations := [0.0, pi/2, pi, 3*pi/2];
		center := point(500, 400);
		xPoints[i] := floatToInt(cos(angle + i) * armLength + 500) foreach i within rotations;
		yPoints[i] := floatToInt(sin(angle + i) * armLength + 400) foreach i within rotations;
	in
		point(xPoints, yPoints);
		
drawBox(points(1)) := 
	let 
		seg1to2 := segment(points[1], points[2], dBlue);
		seg2to3 := segment(points[2], points[3], dBlue);
		seg3to4 := segment(points[3], points[4], dBlue);
		seg4to1 := segment(points[4], points[1], dBlue);
	in
		[seg1to2, seg2to3, seg3to4, seg4to1];