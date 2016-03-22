import <Utilities\\Sequence.sl>;
import <Utilities\\Conversion.sl>;
import <Utilities\\Math.sl>;

//region Types

Point ::= (x: int(0), y: int(0));
Fpoint ::= (fx: float(0), fy: float(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), width: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

//endregion


//region Helpers======================================================================
//region Constructor-Functions-------------------------------------------------
point(a(0), b(0)) := (x: a, y: b);
fpoint(a(0), b(0)) := (fx: a, fy: b);
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

State ::= (darts: Fpoint(1), paused: bool(0)); //Fill in this struct with the game state members.

initialState := (darts: [], paused: false);

newState(I(0), S(0)) := 
	let
		newDart := PtoF(I.iClick.clPoint);
		newS := (darts: S.darts ++ [newDart], paused: S.paused);
		movedS := (darts: dartMove(S.darts, 7), paused: S.paused);
		movedNewS := (darts: dartMove(newS.darts, 7), paused: S.paused);
		p := subset("P", I.keys);
	in
		toggle(movedNewS, p) when I.iClick.clicked and not(S.paused)
	else 
		toggle(movedS, p) when not(S.paused)
	else
		toggle(newS, p) when I.iClick.clicked and S.paused
	else
		toggle(S, p);

sounds(I(0), S(0)) := ["ding"] when false else [];

images(S(0)) :=	[disc(point(500, 400), 15, dRed)] ++ join(drawDart(S.darts, 5));

//=============End=Easel=Functions=============================================
dartMove(f(0), vel(0)) :=
	let
		dx := 500.0 - f.fx;
		dy := 400.0 - f.fy;
		hyp := vel/sqrt(dx^2 + dy^2);
		newF := fpoint(f.fx + dx*hyp, f.fy + dy*hyp);
	in
		newF;

makeDart(S(0), I(0)) := (darts: S.darts ++ [PtoF(I.iClick.clPoint)], paused: S.paused);

drawDart(f(0), rad(0)) := 
	let
		p := FtoP(f);
		newdisc := disc(p, rad, dBlack);
	in
		[newdisc];

dartRemove(S) :=
	let
		deadDarts[i] := S.darts[i] when (sqrt((500.0 - S.darts[i].fx)^2 + (400.0 - S.darts[i].fy)^2) < 15);
	in
		(darts: takeAway(S.darts, deadDarts), paused: S.paused);
		
PtoF(p(0)) := fpoint(1.0*p.x, 1.0*p.y);
FtoP(f(0)) := point(floatToInt(f.fx), floatToInt(f.fy));
toggle(S(0), p(0)) := dartRemove((darts: S.darts, paused: not(S.paused))) when p else dartRemove(S);