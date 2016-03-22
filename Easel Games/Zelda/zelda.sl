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
text(mes(1), cen(0), he(0), c(0)) := (kind: "text", center: cen, height: he, iColor: c, message: mes);
fTri(v1(0), v2(0), v3(0), c(0)) := (kind: "triangle", vert1: v1, vert2: v2, vert3: v3, iColor: c);
graphic(graphicFile(1), c(0), w(0), h(0)) := (kind: "graphic", source: graphicFile, height: h, width: w, center: c);
//----------------------------------------------------------------------

//region Types

State ::= (Hero: HERO(0));
HERO ::= (Position: Point(0), VelocityX: float(0), VelocityY: float(0), Direction: char(1));

//endregion

//=================Easel=Functions=============================================

initialState := (Hero: (Position: point(500, 400), VelocityX: 0.0, VelocityY: 0.0, Direction: "south"));

newState(I(0), S(0)) := 
	let
		run := 
				2.0 when some('R' = I.keys)
			else
				1.0;
	
		xVel := 
				-3.0 * run when some('A' = I.keys)
			else
				3.0 * run when some('D' = I.keys)
			else
				0.0;
				
		yVel := 
				-3.0 * run when some('S' = I.keys)
			else
				3.0 * run when some('W' = I.keys)
			else
				0.0;
				
		dir := 
				"west" when  xVel < 0
			else
				"east" when xVel > 0
			else
				"south" when  yVel < 0
			else
				"north" when yVel > 0
			else
				S.Hero.Direction;
				
		xPos := S.Hero.Position.x + xVel;
		yPos := S.Hero.Position.y + yVel;
		
	in
		(Hero: (Position: point(round(xPos), round(yPos)), VelocityX: xVel, VelocityY: yVel, Direction: dir));

sounds(I(0), S(0)) := ["ding"] when false else [];

imagePath := "..\\..\\..\\..\\Easel Games\\Zelda\\";

images(S(0)) := 
	let
		world := graphic(imagePath ++ "desert.png",  point(500, 400), 1000, 800);
		
		action := 
				"walk" when S.Hero.VelocityX /= 0 or S.Hero.VelocityY /= 0
		 	else
		 		"stand";
		 
		 hero := graphic(imagePath ++ action ++ S.Hero.Direction ++ ".gif",  S.Hero.Position, 0, 0);
		 
		 instructions := text("WASD to move\nR to run", point(100, 100), 16, color(0, 0, 0));
	in
		[world, hero, instructions];

//=============End=Easel=Functions=============================================

