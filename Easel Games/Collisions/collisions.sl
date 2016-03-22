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

randSeq(seed(0), count(0)) := abs(intToFloat(tail(tail(randHelp(seed, count, [])))) / N);

randNum(seed(0)) := head(randSeq(seed, 1));
//endregion----------------------------------------------------------------------
//endregion=============================================================================


//=================Easel=Functions=============================================

Object ::= (xCoord: float(0), yCoord: float(0), xVel: float(0), yVel: float(0), objSize: float(0));

State ::= (time: int(0), objects: Object(1)); //Fill in this struct with the game state members.

randomObjects(seed(0), count(0))[i] :=
	let
		rand := randSeq(seed, count * 5);
	
		obj := (xCoord: (rand[i] * 1000.0), yCoord: (rand[i + 1] * 800.0), xVel: (rand[i + 2] * 10.0), yVel: (rand[i + 3] * 10.0), objSize: (rand[i + 4] * 10.0 + 10));
	in
		obj foreach i within (0 ... ((size(rand) / 5) - 1)) * 5 + 1;

checkHorizontalBoundaries(inObj(0))
		
moveObject(inObj(0)) :=
	let
		newXVel := -inObj.xVel when inObj.
	(xCoord: inObj.xCoord + inObj.xVel, yCoord: inObj.yCoord + inObj.yVel, xVel: inObj.xVel, yVel: inObj.yVel, objSize: inObj.objSize);
		
initialState := (time: 0, objects: randomObjects(5423482, 10));

newState(I(0), S(0)) := (time: S.time + 1, objects: moveObject(S.objects));

sounds(I(0), S(0)) := ["ding"] when I.iClick.clicked else [];

images(S(0))[i] := disc(point(Math::round(S.objects[i].xCoord), Math::round(S.objects[i].yCoord)), Math::round(S.objects[i].objSize), dBlue);

//=============End=Easel=Functions=============================================
