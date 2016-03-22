import <Utilities\\Sequence.sl>;
import <Utilities\\Conversion.sl>;
import <Utilities\\Math.sl>;

/*A *direction* is 1 or -1, denoting up and down, respectively.

A *shot* is a point, representing the center of a shot on the screen.

The "move zone" is defined as the area between and including the
horizontal line through (0,770) and the horizontal line through (0,30).

A *pixel distance* is a natural number, indicating the number of pixels the
enemy may travel before turning around. This number may only be exceeded if
it is not a multiple of the enemy's current speed.

An *animation* is a list of sprites, which, when displayed in order, depict
some animation.

A *frame counter* is a natural number.

A *playback* is a pair (p, L), where L is an animation and p is a frame counter
in the range [0, size(L)). Playback (p, L) denotes an animation that is
currently on its (p+1)'th frame, called its "current frame."

#OVERVIEW:

In this game, the player controls a blue space ship, called the "hero."
The computer controls a red space ship, called the "enemy."

The hero and the enemy are collectively referred to as "ships."

Both ships will shoot small missiles of their respective colors at each other.
These missiles will be referred to as "shots."

The object of the game is for the hero to shoot the enemy as many
times as possible before the player's life runs out.

#STATE VARIABLES:

A *State* is an 8-tuple (gOver, pStat, eStat, shotTimer, pShots, eShots, score, playList), where
the following are true:

	gOver is a natural number in the range [0,20]. A gOver of 0 means that the game is not over,
	a gOver of 20 means the game is over, and any other gOver means that the game over animation
	is in its gOver'th frame.
	gOver's initial value is 0.

	pStat is a triple (pVert, pLife, cooldown) where the following are true:

		pVert is the hero's y-coordinate. Its initial value is 500.

		pLife is the remaining number of hits the hero may take before the game ends.
		Its inital value is 5.

		cooldown is the remaining number of frames before the hero may next fire a
		shot. Its initial value is 0.

	eStat is a 4-tuple (eVert, eDirec, eDist) where the following are true:
		
		eVert is the enemy's y-coordinate. Its initial value is 500.
		
		eDirec is the direction in which the enemy will next move. Its initial value
		is 1.

		If traveling eDist pixels in eDirec would not take the enemy more than eSpeed
		pixels out of the move zone, then eDist is the minimum number of pixels
		the enemy may travel before changing direction. Its initial value is 120.

	shotTimer is the number of frames before the enemy will fire another shot.
		Its initial value is 160.
	
	pShots is the current list of player shots. Its initial value is [].

	eShots is the current list of enemy shots. Its initial value is [].

	score is the number of points the player has accumulated. Its initial value
	is 0.

	playList is the list of playbacks to be animated on the screen. Its initial
	value is [].

#DEPENDENT VARIABLES:

level() is a value controlling the enemy's speed and the rate at which the
enemy shoots. It is equal to the minimum value of score//50 and 6.

eSpeed() is the enemy's rate of movement in pixels per frame. It is equal to
5 + level().

#CONSTANTS

shipRad is the radius of each ship, in pixels. It is equal to 25.

shotRad is the radius of each shot, in pixels. It is equal to 12.

pSpeed is the hero's maximum rate of movement, in pixels per frame.
It is equal to 10.

shotSpeed is the rate of movement of each shot, in pixels per frame.
It is equal to 32.

eColor is the color of the enemy and its shots. It is equal to dRed.

pColor is the color of the hero and its shots. It is equal to dBlue.

#MOVEMENT OF THE SHIPS:

The hero is initially centered at (75,500) on the left side of the screen.

The enemy is initially centered at (925,500) on the right side of the screen.

Both ships have a fixed horizontal position.

The hero will move vertically until it is horizontally level with the cursor,
or it reaches the edge of the move zone in this attempt. The hero is limited
to a speed of pSpeed pixels per frame (p/f), but may move less at a time
if the cursor or an edge of the move zone is less than pSpeed pixels away.

The enemy will move vertically in eDirec until it covers eDist pixels
or passes the edge of the move zone. When either of these conditions is met,
eDirec is reversed, and eDist is set to a psuedo-random natural number in the range [200,1000].

#COMBAT AND SCORING:

When a shot is fired, it appears next to the ship which fired it,
and will travel horizontally towards the ship's opponent
at a rate of shotSpeed p/f.

A shot is said to intersect a ship if its center comes within 37 pixels of that ship's center.

If a shot intersects its shooter's opponent, it is said to "hit" the
opponent. When a shot hits its shooter's opponent, it plays an animation
resembling the shot exploding.

If a shot hits its shooter's opponent, or reaches the edge of the screen,
and is removed from the game.

If the enemy is hit by a player shot, the score increases by 10. For every 50
points, the enemy's level will increase, to a maximum of 6.

If the hero is hit by a enemy shot, the player's life decreases by 1.

The hero will fire a shot when the mouse is clicked or the spacebar is
pressed. Whenever a shot is fired, a 20-frame "cooldown" is incurred.
This cooldown decreases by 1 every frame until it hits 0, and must be
zero before another shot can be fired.

The enemy will fire a shot whenever shotTimer hits zero, and will then reset
the shot timer to a new value in the range [30-3*level(),80-10*level()).

#SCOREBOARD:

pLife, score, and level() will be displayed---in that order---across the
bottom of the screen, respectively preceeded by the strings "Life:", "Score:",
and "Level:". The sprite consisting of these images is called the "scoreboard."

#GAME END:

When the player's health is less than or equal to zero, gOver will be set
to 1 and an explosion animation will play at the location of the player's ship.
Each subsequent frame, gOver will increment by 1. When gOver reaches 9, the game is over.

When the game is over, all ships and shots will be removed from the screen.
A giant "Game Over" message will display in the center of the screen.
A box labeled "Restart" will be displayed below this message.
The scoreboard will remain on the screen, but its values
will be fixed.

Clicking the "Restart" box will reset the game to its initial state.
*/

//region Types

Point ::= (x: int(0), y: int(0));

Color ::= (red: int(0), green: int(0), blue: int(0));

Image ::= (kind: char(1), iColor: Color(0), vert1: Point(0), vert2: Point(0), vert3: Point(0), center: Point(0),
		   radius: int(0), height: int(0), width: int(0), message: char(1), source: char(1));

Click ::= (clicked: bool(0), clPoint: Point(0));

Input ::= (iClick: Click(0), keys: char(1));

Playback ::= (frame: int(0), anim: Animation(0));

Animation ::= (images: Image(2));

PStat ::= (pLife: int(0), pVert: int(0), cooldown: int(0));

EStat ::= (eVert: int(0), eDirec: int(0), eDist: int(0));

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
playback(f(0), A(0)) := (frame: f, anim: A);
animation(i(2)) := (images: i);
pStat(l(0), v(0), c(0)) := (pLife: l, pVert: v, cooldown: c);
eStat(v(0), drc(0), dst(0)) := (eVert: v, eDirec: drc, eDist: dst);
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

//region constants-------------------------------------------------------------
shipRad:= 25;
shotRad:= 12;
pSpeed:= 10;
shotSpeed:= 32;
eColor:= dRed;
pColor:= dBlue;
back:= "..\\..\\..\\..\\Easel Games\\Space Battle\\background.jpg";
eSprite:= "..\\..\\..\\..\\Easel Games\\Space Battle\\enemy.png";
pSprite:= "..\\..\\..\\..\\Easel Games\\Space Battle\\hero.png";
eShotSprite:= "..\\..\\..\\..\\Easel Games\\Space Battle\\eShot.png";
pShotSprite:= "..\\..\\..\\..\\Easel Games\\Space Battle\\pShot.png";
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
//endregion----------------------------------------------------------------------
//endregion=============================================================================


//=================Easel=Functions=============================================

//region Dependent Variables--------------------------------------------------

// If x is an integer, level(x) is the minimum value of floor(x/50) and 6.
level: int(0) -> int(0);
level(x(0)):= min(floor(x/50),6);

// If x is an integer, eSpeed(x) is 2*level(x) plus 10.
eSpeed: int(0) -> int(0);
eSpeed(x(0)):= 2*level(x) + 10;

//endregion----------------------------------------------------------------------

//region IMAGE FUNCTIONS------------------------------------------------------

// if c is a point, player(c) the 55*33 image of the player ship, centered at c.
player: Point(0) -> Image(1);
player(c(0)):= [graphic(pSprite, c, 55,33)];

// if c is a point, enemy(c) the 55*33 image of the enemy ship, centered at c.
enemy: Point(0) -> Image(1);
enemy(c(0)):= [graphic(eSprite, c, 55,33)];

// if p and e are lists of shots, then shotSprites(p, e) is a sprite consisting of the 24*16
// images of all shots in e and p.
shotSprites: Point(1) * Point(1) -> Image(1);
shotSprites(e(1), p(1)):= graphic(eShotSprite, e, 24, 16) ++ graphic(pShotSprite,p, 24,16);

//TEXT

// overMessage is a list whose only member is a black text image of height 50 and message
//"Game Over!", centered at (500,400).
overMessage:= [text("Game Over!", point(500,400), 50, dBlue)];

// restarter is a sprite depicting a hollow, black, 160*60 box labeled
// "Restart", whose top-left corner is at (420, 280), and whose black text is
// 25-pt and centered at (500,250).
restarter:=
	let
		tL := point(420, 280);
		tR := point(580, 280);
		bR := point(580, 220);
		bL := point(420, 220);
		txt := text("Restart", point(500,250), 25, dBlack);
	in
		restartBox(tL,tR,bR,bL) ++ [txt];

// If tL, tR, bR, and bL are points, restartBox(tL, tR, bR, bL) is a list of two filled,
// blue triangles forming a filled rectangle whose corners are tL, tR, bR, and bL.
restartBox: Point(0) * Point(0) * Point(0) * Point(0) -> Image(1);
restartBox(tL(0), tR(0), bR(0), bL(0)):=
	let
		top := fTri(tL, tR, bL, dBlue);
		bot := fTri(bL, tR, bR, dBlue);
	in
		[top, bot];

// If l and s are integers, then scoreBoard(l, s) is a sprite located at the bottom
// of the screen, indicating the values of l, the s, and level(s).
scoreBoard: int(0) * int(0) -> Image(1);
scoreBoard(l(0), s(0)):=
	lifeCounter(l) ++ scoreCounter(s) ++ levelCounter(level(s));

// If l is an integer, lifeCounter(l) is a sprite consisting of the green, 20-pt text
// "Life:" centered at (200,50) and the green, 20-pt text intToString(l), centered at
// (250, 50).
lifeCounter: int(0) -> Image(1);
lifeCounter(l(0)):=
	let
		label := text("Life:", point(200, 50), 20, dGreen);
		num := text(intToString(l), point(250,50), 20, dGreen);
	in
		[label, num];

// If s is an integer, scoreCounter(s) is a sprite consisting of the green, 20-pt text
// "Score:" centered at (450,50) and the green, 20-pt text intToString(s), centered at
// (550,50).
scoreCounter: int(0) -> Image(1);
scoreCounter(s(0)):=
	let
		label := text("Score:", point(450,50), 20, dBlack);
		num := text(intToString(s), point(550,50), 20, dBlack);
	in
		[label, num];

// If l is an integer, levelCounter(l) is a sprite consisting of the green, 20-pt text
// "Level:" centered at (750,50) and the green, 20-pt text intToString(l), centered at
// (800,50).
levelCounter: int(0) -> Image(1);
levelCounter(l(0)):=
	let
		label := text("Level:", point(750,50), 20, dGreen);
		num := text(intToString(l), point(800,50), 20, dGreen);
	in
		[label, num];

//ANIMATIONS

// If p is a playback, then animate(p) is the member of p's animation in position p.frame
animate: Playback(0) -> Image(1);
animate(p(0)):= p.anim.images[p.frame];

// If p is a playback, then notFinal(p) means that p.frame + 1 is less than the
// length of p's animation. In other words, the playback's animation has not yet
// reached its final frame.
notFinal: Playback(0) -> bool(0);
notFinal(p(0)):= true when (p.frame) <  size(p.anim.images) else false;

// If p is a playback (f,a), then nxt(p) is (f+1,a) if p has not reached its final frame.
nxt: Playback(0) -> Playback(0);
nxt(p(0)):= playback(p.frame+1, p.anim) when notFinal(p);

// If S is a state, then newAnims(S) is the set of playbacks depicting new, eColor explosion
// animations at the location of every shot that hit the player this frame, and new, pColor
// explosion animations at the location of every shot that hit the enemy this frame.
newAnims: State(0) -> Playback(1);
newAnims(S(0)):=
	let
		e := pHits(S.eShots, S.player.pVert);
		p := eHits(S.pShots, S.enemy.eVert);
		end := [playback(1,deathAnim(pCenter(S.player.pVert)))] when S.gOver = 1 else [];
	in
		playback(1,explosion(e, eColor)) ++ playback(1,explosion(p, pColor)) ++ end;

// If p is a point and c is a color, then explosion(p,c) is an animation of a
// collection of four discs of color c. The discs start at point p with radius
// 8. Every frame of the animation,  each disk moves 4 pixels horizontally and
// 4 pixels vertically in separate diagonal directions, and the radius of each
// decreases by 1 every two frames. The animation lasts 9 frames, including
// the initial frame.
explosion: Point(0) * Color(0) -> Animation(0);
explosion(p(0),c(0)):= animation([[disc(p, 8, c)]] ++ spreader(range(1, 9, 1), p, c));

// if p is a point, c is a color, and i is a natural number in the range [1,9], then
// spreader(i,p,c) is the i+1'th frame of explosion(p,c).
spreader: int(0) * Point(0) * Color(0) -> Image(1);
spreader(i(0),p(0),c(0)):=
	let
		tL := point(p.x - 4*i, p.y + 4*i);
		tR := point(p.x + 4*i, p.y + 4*i);
		bR := point(p.x + 4*i, p.y - 4*i);
		bL := point(p.x - 4*i, p.y - 4*i);
	in
		disc([tL, tR, bR, bL], 8-floor(i/2), c);

// If p is a point, then deathAnim(p) is an animation of a collection of four discs of color
// pColor. The discs start at point p with radius 20. Every frame of the animation, 
// each disk moves 6 pixels horizontally and 6 pixels vertically in separate diagonal
// directions, and the radius of each decreases by 1 every frame. The animation lasts 16
// frames, including the initial frame.
deathAnim: Point(0) -> Animation(0);
deathAnim(p(0)):= animation([[disc(p, 20, pColor)]] ++ deathSpreader(range(1, 16, 1), p));

// if p is a point and i is a natural number in the range [1,9], then
// deathSpreader(i,p) is the i+1'th frame of deathAnim(p).
deathSpreader: int(0) * Point(0) -> Image(1);
deathSpreader(i(0),p(0)):=
	let
		tL := point(p.x - 6*i, p.y + 6*i);
		tR := point(p.x + 6*i, p.y + 6*i);
		bR := point(p.x + 6*i, p.y - 6*i);
		bL := point(p.x - 6*i, p.y - 6*i);
	in
		disc([tL, tR, bR, bL], 20-i, pColor);

//endregion--------------------------------------------------------------------

//region Ship Functions--------------------

// If p is the hero's current PStat. s is a list of enemy shots, and I
// is the current input, then heroUpdate(p, s, I) is the new pStat.
heroUpdate: PStat(0) * Point(1) * Input(0) -> PStat(0);
heroUpdate(p(0), s(1), I(0)):=
	let
		newLife:= p.pLife - size(pHits(s, p.pVert));
		newVert:= pVertCalc(p, I.iClick.clPoint);
		newCD:= cool(p.cooldown, I);
	in
		pStat(newLife, newVert, newCD);


// if p is a pStat and m is a point, then pVertCalc(p, m) is moveHero(h,d,m), where h is p.pVert,
// d is mouseDirec(pCenter(p.pVert), m).
pVertCalc(p(0), m(0)):=
	let
		h := p.pVert;
		d := mouseDirec(pCenter(p.pVert), m);
	in
		moveHero(h,d,m);

// If h is the hero's current vertical level, d is a direction, m is the current location
// of the cursor, and the cursor is in direction d from the hero, then
// moveHero(h, d, m) is the hero's new vertical level.
//If d is 0, moveHero(h, d, m) is h.
moveHero: int(0) * int(0) * Point(0) -> int(0);
moveHero(h(0), d(0), m(0)):= h when d = 0
	else
		moveNear(h, d, m) when cursorNear(pCenter(h), m)
	else
		moveFar(h, d);
		
// If p1 and p2 are points, then cursorNear(p1, p2) means that the vertical distance 
// between p1 and p2 is in the interval (-pSpeed, pSpeed).
cursorNear: Point(0) * Point(0) -> bool(0);
cursorNear(p1(0),p2(0)):=
	let
		dist := p2.y - p1.y;
	in
		-pSpeed < dist and dist < pSpeed;

// If h is the hero's current vertical level and d is a direction, then moveFar(h, d) is
// h moved pSpeed pixels in direction d, or moved to the edge of the move zone
// in direction d, whichever is closer.
moveFar: int(0) * int(0) -> int(0);
moveFar(h(0), d(0)):= 400+370*d when nearEdge(pCenter(h), d) else h + d*pSpeed;

// If h is the hero's current vertical level, d is a direction, and m is the cursor's current
// location, then moveNear(h, d, m) is h moved to the vertical level of m, provided m
// is within the move zone.
// If m is not in the move zone, then moveNear(h,d,m) instead is h moved vertically
// to the move zone edge in direction d.
moveNear: int(0) * int(0) * Point(0) -> int(0);
moveNear(h(0),d(0),m(0)):= 400+370*d when m.y > 770 or m.y < 30 else m.y;

// If p1 and p2 are points, then mouseDirec(p1, p2) is the vertical direction from p1 to p2,
// or 0 if the two are level.
mouseDirec: Point(0) * Point(0) -> int(0);
mouseDirec(p1, p2):= 1 when p2.y > p1.y
	else -1 when p2.y < p1.y
	else 0;

// If p is a point and d is a direction, then nearEdge(p, d) means that p is less than
// pSpeed pixels from the move zone edge corresponding to d. For example,
// nearEdge(p, 1) means that p is less than pSpeed pixels from the top edge of the move zone.
nearEdge: Point(0) * int(0) -> bool(0);
nearEdge(p(0), d(0)):=
	abs(400+d*370 - p.y) < pSpeed;
	
// if e is the enemy's current eStat, s is the current score, and R is an integer, then
// moveEnemy(e,s,R) is the enemy's new eStat under R.
moveEnemy: EStat(0) * int(0) * int(0) -> EStat(0);
moveEnemy(e(0),s(0), R(0)):=
	let
		drc := newDirec(e);
		vert := newVert(e,s);
		dst := newDist(e,s,R);
	in
		eStat(vert, drc, dst);

// if e is the enemy's current eStat and s an integer, then newVert(e) is e.eVert moved eSpeed(s)
// pixels in e's new direction.
newVert: EStat(0) * int(0) -> int(0);
newVert(e(0), s(0)):=
	e.eVert + newDirec(e)*eSpeed(s);

// if e is the enemy's current eStat, then newDirec(e) is e.eDirec if the enemy does not need
// to reverse direction, and -e.eDirec otherwise.
newDirec: EStat(0) -> int(0);
newDirec(e(0)):=
	-e.eDirec when pathEnd(e) else e.eDirec;

// If e is the enemy's current eStat and s and R are integers, then newDist(e,s,R) is
// (R mod 800) + 200 if pathEnd(e), and the current eDist minus eSpeed(s) otherwise.
newDist: EStat(0) * int(0) * int(0) -> int(0);
newDist(e(0),s(0),R(0)):=
	R mod 800 + 200 when pathEnd(e) else e.eDist - eSpeed(s);

// if e is the enemy's current eStat, then pathEnd(e) means that the enemy is outside of the
// move zone or that e.eDist is less than or equal to zero.
pathEnd: EStat(0) -> bool(0);
pathEnd(e(0)):=
	e.eVert >= 770 or e.eVert <= 30 or e.eDist <= 0;

//endregion---------------------------------------

//region SHOT FUNCTIONS---------------------------

//If S is a state and I is an input, then, if the game is not over, pShotMaster(S,I) is the list
//of all onscreen player shots which do not intersect the enemy, moved shotSpeed pixels to
//the right. If a player shot has been fired this frame, a new player shot is appended to the
//above list.
//If S.gOver is greater than zero, pShotMaster(S,I) does not append a new player shot to the
// list.
pShotMaster(S(0),I(0)):=
	let
		shotList:= pShotMove(S.pShots, S.enemy.eVert);
	in
		pShooter(I,shotList,S.player.cooldown,S.player.pVert) when not(S.gOver>0) else shotList;

//If S is a state, then, if the game is not over, eShotMaster(S) is the list
//of all onscreen enemy shots which do not intersect the player, moved shotSpeed pixels to
//the left. If the shotTimer is 0, a new enemy shot is appended to the above list.
//If the game is over, eShotMaster(S) is instead S.eShots.
eShotMaster(S(0)):=
	let
		shotList:= eShotControl(S.eShots, S.player.pVert);
	in
		eShooter(shotList, S.shotTimer, S.enemy.eVert) when not(S.gOver>0) else S.eShots;

// If I is an input, s is a list of shots, and c and v are integers, then pShooter(I, s, c,v)
// is s with the point (115,v) appended to it if the following are both true:
//		1. the mouse has been clicked
//      2. c is 0
// otherwise, pShooter(I,s,c,v) is s.
//pShooter: Input(0) * Point(1) * int(0) * int(0) -> Point(1);
pShooter(I(0), s(1), c(0), v(0)):=
	s ++ [point(115,v)] when I.iClick.clicked and cooled(c) else s;

// If s is a shot and e is an integer, pShotMove(s,e) is s moved shotSpeed pixels to the right
// if s.x is less than 1000 and s does not intersect a ship at eCenter(e).
//pShotmove: Point(0) * int(0) -> Point(0);
pShotMove(s(0),e(0)):=
	point(s.x+shotSpeed,s.y) when s.x < 1000 and not(intersect(s,eCenter(e)));
	

// If c is an integer and I is an inpute, then cool(c,I) is c-1 if c > 0, 20 if c is 0 and the
// mouse is clicked, and 0 otherwise.
cool: int(0) * Input -> int(0);
cool(c(0), I(0)):=
	c-1 when c>0 else 20 when I.iClick.clicked else 0;

// If c is an integer, then cooled(c) means c is 0.
cooled: int(0) -> bool(0);
cooled(c(0)):= c = 0;

// if s is a list of shots and t and v are integers, eShooter(s, t, v) is s with point(885,v)
// appended to it if t is 0, and s otherwise.
eShooter: Point(1) * int(0) * int(0) -> Point(1);
eShooter(s(1),t(0),v(0)):=
	s ++ [point(885,v)] when cooled(t) else s;

// If s is a shot and p is an integer, eShotControl(s,p) is s moved shotSpeed pixels to the left
// if s.x is greater than 0 and s does not intersect a ship at pCenter(p).
//eShotControl: Point(0) * int(0) -> Point(0);
eShotControl(s(0), p(0)):=
	point(s.x-shotSpeed, s.y) when s.x > 0 and not(intersect(s, pCenter(p)));

//endregion----------------------------------------------------------

//region COLLISION FUNCTIONS----------------------------------------

// pCenter(v) is the point (75,v)
pCenter(v(0)):= point(75,v);

// eCenter(v) is the point (925,v)
eCenter(v(0)):= point(925,v);

// If s is a shot and v is an integer, then pHits(s, v) is s if
// s would intersect a ship centered at pCenter(v).
//pHits: Point(0) * int(0) -> Point(0);
pHits(s(0), v(0)):=
	s when intersect(s, pCenter(v));

// If s is a shot and v is an integer, then eHits(s,v) is s if
// s would intersect a ship centered at eCenter(v).
//eHits: Point(0) * int(0) -> Point(0);
eHits(s(0), v(0)):=
	s when intersect(s, eCenter(v));

// If s is a list of shots and v is an integer, then eHits(s, v) is the list of all shots 
// in s that would intersect with a ship at eCenter(v).

// If p1 and p2 are points, then intersect(p1,p2) means that p1 and p2 are within
// (shipRad + shotRad) pixels of each other.
intersect: Point(0) * Point(0) -> bool(0);
intersect(p1(0),p2(0)):=
	dist(p1,p2) < shipRad + shotRad;

// If p1 and p2 are points, then dist(p1, p2) is the distand between p1 and p2, in pixels
dist: Point(0) * Point(0) -> int(0);
dist(p1(0), p2(0)):=
	floor(sqrt((p1.x - p2.x)^2 + (p1.y - p2.y)^2));

//endregion--------------------------------------------------

//region input functions------------------------------------
// If I is an input, then restartClicked(I) means that the left mouse button is depressed
// and the cursor is within the bounds of the restart box.
//restartClicked: Input(0) -> bool(0):
restartClicked(i(0)):=
	let
		vert:= 420 < i.iClick.clPoint.x and i.iClick.clPoint.x < 580;
		horiz:= 220 < i.iClick.clPoint.y and i.iClick.clPoint.y < 280;
		clicker:= i.iClick.clicked;
	in
		all([vert, horiz, clicker]);
//endregion----------------------------------------------------

//region Misc Functions----------------------------------------
// If t, s and R are integers, then timerUpdate(t,s, R) is t-1 if t is greater than 0, and
// randTimer(s,R) otherwise.
timerUpdate: int(0) * int(0) * int(0) -> int(0);
timerUpdate(t(0),s(0),R(0)):=
	t-1 when t>0 else randTimer(s,R);

// If s and R are integers, such that s is in the range [0,6], then randTimer(s, R) is
// R mod (H-L) + L, where H is 60-7*level(s), and L is 30-3*level(s).
randTimer: int(0) * int(0) -> int(0);
randTimer(s(0),R(0)):=
	let
		hiBound:= 60-7*level(s);
		loBound:= 30-3*level(s);
	in
		(R mod (hiBound-loBound)) + loBound;

// If S is a state, then randNum(S) is a natural number in the range [0,1000], calculated
// using various members of the state.
randNum: State -> int(0);
randNum(S):=
	floatToInt(randSeq(floatToInt(S.player.pVert*901 + S.score*32 +
			S.player.cooldown*13 + S.shotTimer*82 + S.enemy.eVert*124), 1)[1] * 1000);
//endregion---------------------------------------------------

State ::= (gOver: int(0), player: PStat(0), enemy: EStat(0), shotTimer: int(0),
	pShots: Point(1), eShots: Point(1), score: int(0), playList: Playback(1));

initialState := (gOver: 0, player: pStat(5,300,0), enemy: eStat(300,1,120), shotTimer: 160, pShots: [], eShots: [], score: 0, playList: []);

// If I is an input and S is a state, then newState(I, S) is overState(I,S) if the game is over
// in state S, and gameState(I,S) otherwise.
newState(I(0), S(0)) :=
	overState(I,S) when S.gOver = 20 else gameState(I,S);

// If I is an input and S is a state where the game is not over, then gameState(I,S) is the state
// resulting from input I in state S.
gameState(I(0),S(0)):=
	let
		newGOver:= S.gOver + 1 when S.player.pLife <= 0 and S.gOver < 20 else S.gOver;
		newPlayer:= heroUpdate(S.player, S.eShots, I) when S.player.pLife>0 else S.player;
		newEnemy:= moveEnemy(S.enemy, S.score, randNum(S));
		newTimer:= timerUpdate(S.shotTimer, S.score, randNum(S));
		newPShots:= pShotMaster(S,I);
		newEShots:= eShotMaster(S);
		newScore:= S.score + 10*size(eHits(S.pShots, S.enemy.eVert)) when S.gOver = 0 else S.score;
		newPlayList:= nxt(S.playList) ++ newAnims(S);
	in
		buildState(newGOver, newPlayer, newEnemy, newTimer, newPShots, newEShots, newScore, newPlayList);

// If I is an input and S is a state, then overState(I,S) is the initial state if the restart
// button has been clicked this frame, and S otherwise.
overState(I(0),S(0)):=
	initialState when restartClicked(I) else S;
	

buildState(g(0), p(0), e(0), t(0), pS(1), eS(1), sc(0), a(1)):=
	(gOver: g, player: p, enemy: e, shotTimer: t, pShots: pS, eShots: eS, score: sc, playList: a);

// If I is an input and S is a state, then sounds(I,S) is ["bang"] if the game is not over
// and a ship has been hit this frame, and the empty list otherwise.
sounds: Input(0) * State(0) -> char(2);
sounds(I(0), S(0)) :=
	let
		bang := ["bang"] when size(pHits(S.eShots, S.player.pVert)) > 0 else [];
		ding := ["ding"] when size(eHits(S.pShots, S.enemy.eVert)) > 0 else [];
	in
		(bang ++ ding) when not(S.gOver > 0) else [];

images(S(0)) := 
	let
		norm := gameImages(S);
		over := overImages when S.gOver = 20 else [];
	in
		norm ++ over;

// If S is a state, then gameImages(S) is the sprite depicting the background, the
// player, the enemy, the shots, and the scoreboard in state S.
gameImages(S(0)):=
	let
		b := [graphic(back, point(500,400), 1280, 800)];
		p := player(pCenter(S.player.pVert)) when S.gOver = 0 else [];
		e := enemy(eCenter(S.enemy.eVert));
		shots := shotSprites(S.eShots, S.pShots);
		board := scoreBoard(S.player.pLife, S.score);
		animations := join(animate(S.playList));
	in
		b ++ p ++ e ++ shots ++ board ++ animations;

// overImages is the sprite depicting the game over message, the
// restart box.
overImages:=
	overMessage ++ restarter;
//=============End=Easel=Functions=============================================
