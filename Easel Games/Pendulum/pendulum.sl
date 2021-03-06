import <Utilities/Sequence.sl>;
import <Utilities/Conversion.sl>;
import <Utilities/Math.sl>;

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
segment(e1(0), e2(0), c(0)) := (kind: "segment", vert1: e1, vert2: e2, iColor: c);
disc(ce(0), rad(0), c(0)) := (kind: "disc", center: ce, radius: rad, iColor: c);
//endregion----------------------------------------------------------------------

//region Colors----------------------------------------------------------------
dBlack := color(0, 0, 0);
dYellow := color(255, 255, 0);
//endregion----------------------------------------------------------------------
//endregion=============================================================================


//=================Easel=Functions=============================================

State ::= (angle: float(0), angleVelocity: float(0), angleAccel: float(0)); //Fill in this struct with the game state members.

initialState := (angle: pi/2, angleVelocity: 0.0, angleAccel: 0.0);

dt := 0.3;
length := 450;

anchor := point(500, 750);

newState(I(0), S(0)) := 
    let
        newAngle := S.angle + newAngleVelocity * dt;
        newAngleVelocity := S.angleVelocity + newAngleAccel * dt;
        newAngleAccel := -9.81 / length * sin(S.angle);
    in
    (angle: newAngle, angleVelocity: newAngleVelocity, angleAccel: newAngleAccel);

sounds(I(0), S(0)) := ["ding"] when I.iClick.clicked else [];

images(S(0)) := 
    let
        pendulum := pendulumLocation(S.angle);
    in
        [segment(anchor, pendulum, dBlack),
         disc(pendulum, 30, dYellow),
         disc(anchor, 5, dBlack)];

pendulumLocation(angle) := 
    let
        x := anchor.x + round(sin(angle) * length);
        y := anchor.y - round(cos(angle) * length);
    in
        point(x, y);

//=============End=Easel=Functions=============================================
