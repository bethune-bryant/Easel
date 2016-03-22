import <Utilities\\Math.sl>;

Point ::= (x: int(0), y: int(0));
Color ::= (red: int(0), green: int(0), blue: int(0));
Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), width: int(0), message: char(1), source: char(1));
Click ::= (clicked: bool(0), clPoint: Point(0));
Input ::= (iClick: Click(0), keys: char(1));

//Constructor-Functions-------------------------------------------------
point(a(0), b(0)) := (x: a, y: b);
color(r(0), g(0), b(0)) := (red: r, green: g, blue: b);
fTri(v1(0), v2(0), v3(0), c(0)) := (kind: "triangle", vert1: v1, vert2: v2, vert3: v3, iColor: c);
graphic(graphicFile(1), c(0), w(0), h(0)) := (kind: "graphic", source: graphicFile, height: h, width: w, center: c);
//----------------------------------------------------------------------

//region Types

State ::= (Mario: MARIO(0));
MARIO ::= (Position: Point(0), VelocityX: float(0), VelocityY: float(0), Direction: char(1));

imagePath := "..\\..\\..\\..\\Easel Games\\Mario\\";

sounds(I(0), S(0)) := ["ding"] when I.iClick.clicked else [];

//endregion

//=================Easel=Functions=============================================

initialState := (Mario: (Position: point(500, 0), VelocityX: 0.0, VelocityY: 0.0, Direction: "right"));

newState(I(0), S(0)) := 
	let
		xVel := 
				-5.0 when some('A' = I.keys)
			else
				5.0 when some('D' = I.keys)
			else
				0.0;
				
		yVel := 
				5.0 when some('W' = I.keys) and S.Mario.Position.y = 0
			else
				S.Mario.VelocityY - 0.25;
				
		dir := 
				"left" when  xVel < 0
			else
				"right" when xVel > 0
			else
				S.Mario.Direction;
				
		xPos := S.Mario.Position.x + xVel;
		yPos := max(round(S.Mario.Position.y + yVel), 0);
	in
		(Mario: (Position: point(round(xPos), yPos), VelocityX: xVel, VelocityY: yVel, Direction: dir));

images(S(0)) := 
	let
		grassColor := color(74, 163, 41);
		skyColor := color(174, 238, 238);
		
		groundPic := [fTri(point(0, 0), point(1000, 0), point(0, 100), grassColor), fTri(point(1000, 100), point(1000, 0), point(0, 100), grassColor)];
		skyPic := [fTri(point(0, 100), point(1000, 100), point(0, 800), skyColor), fTri(point(1000, 800), point(1000, 100), point(0, 800), skyColor)];
		world := groundPic ++ skyPic;
		
		action := 
				"jump" when S.Mario.Position.y > 0
		 	else
		 		"walk" when S.Mario.VelocityX /= 0
		 	else
		 		"stand";
		 
		 mario := [graphic(imagePath ++ action ++ S.Mario.Direction ++ ".gif",  point(S.Mario.Position.x, S.Mario.Position.y + 100 + 13), 70, 70)];
	in
		world ++ mario;

//=============End=Easel=Functions=============================================

