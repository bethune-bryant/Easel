#ifndef _SEQUENCEL_GENERATED_main_H
#define _SEQUENCEL_GENERATED_main_H

#define SL_FLOAT_SIZE 8
#if SL_FLOAT_SIZE == 4
#define SL_FLOAT float
#else
#define SL_FLOAT double
#endif

#include <SequenceL/SequenceL.h>

struct _sl_Point_0;
struct _sl_Color_0;
struct _sl_Image_0;
struct _sl_Click_0;
struct _sl_Input_0;
struct _sl_State_0;
struct _sl_Ball_0;
//-----------------------------------------
// _sl_Point_0 struct definition
//------------------------------------------
struct _sl_Point_0
{
int x;
int y;


_sl_Point_0():x(0), y(0)
{
}

_sl_Point_0(Memflags _m):x(0), y(0)
{
}

_sl_Point_0(int _x, int _y):x(_x), y(_y)
{
}

void _initialize(Memflags _mfp)
{
x=0;
y=0;

}

void _delete_data(bool _parallel)
{

}

void _finished()
{

}

~_sl_Point_0()
{
_delete_data(true);
_finished();
}
void _Reference()
{

}

void _deFrag()
{

}

void _parallel_deFrag(int _ln)
{

}

void _fix_padding(_sl_Point_0& _old)
{

}

_sl_Point_0& operator=(const _sl_Point_0& _rhs)
{
x = _rhs.x;
y = _rhs.y;

return *this;
}

void _hard_copy(_sl_Point_0& _rhs, int _ln)
{
x = _rhs.x;
y = _rhs.y;
}

ostream& _toString(ostream& _stream) const
{
_stream<<"(";
_stream<<"x:"<<x<<","<<"y:"<<y;
_stream<<")";
return _stream;
}

string _toString() const
{
ostringstream _stream;
_toString(_stream);
return _stream.str();
}

};

//-----------------------------------------

//-----------------------------------------
// _sl_Color_0 struct definition
//------------------------------------------
struct _sl_Color_0
{
int red;
int green;
int blue;


_sl_Color_0():red(0), green(0), blue(0)
{
}

_sl_Color_0(Memflags _m):red(0), green(0), blue(0)
{
}

_sl_Color_0(int _red, int _green, int _blue):red(_red), green(_green), blue(_blue)
{
}

void _initialize(Memflags _mfp)
{
red=0;
green=0;
blue=0;

}

void _delete_data(bool _parallel)
{

}

void _finished()
{

}

~_sl_Color_0()
{
_delete_data(true);
_finished();
}
void _Reference()
{

}

void _deFrag()
{

}

void _parallel_deFrag(int _ln)
{

}

void _fix_padding(_sl_Color_0& _old)
{

}

_sl_Color_0& operator=(const _sl_Color_0& _rhs)
{
red = _rhs.red;
green = _rhs.green;
blue = _rhs.blue;

return *this;
}

void _hard_copy(_sl_Color_0& _rhs, int _ln)
{
red = _rhs.red;
green = _rhs.green;
blue = _rhs.blue;
}

ostream& _toString(ostream& _stream) const
{
_stream<<"(";
_stream<<"blue:"<<blue<<","<<"green:"<<green<<","<<"red:"<<red;
_stream<<")";
return _stream;
}

string _toString() const
{
ostringstream _stream;
_toString(_stream);
return _stream.str();
}

};

//-----------------------------------------

//-----------------------------------------
// _sl_Image_0 struct definition
//------------------------------------------
struct _sl_Image_0
{
int radius;
int height;
int width;
Sequence< char > kind;
Sequence< char > message;
Sequence< char > source;
SLStruct<_sl_Color_0> iColor;
SLStruct<_sl_Point_0> vert1;
SLStruct<_sl_Point_0> vert2;
SLStruct<_sl_Point_0> vert3;
SLStruct<_sl_Point_0> center;


_sl_Image_0():radius(0), height(0), width(0), kind(), message(), source(), iColor(false), vert1(false), vert2(false), vert3(false), center(false)
{
}

_sl_Image_0(Memflags _m):radius(0), height(0), width(0), kind(_m), message(_m), source(_m), iColor(false,_m), vert1(false,_m), vert2(false,_m), vert3(false,_m), center(false,_m)
{
}

_sl_Image_0(int _radius, int _height, int _width, Sequence< char > _kind, Sequence< char > _message, Sequence< char > _source, SLStruct<_sl_Color_0> _iColor, SLStruct<_sl_Point_0> _vert1, SLStruct<_sl_Point_0> _vert2, SLStruct<_sl_Point_0> _vert3, SLStruct<_sl_Point_0> _center):radius(_radius), height(_height), width(_width), kind(_kind), message(_message), source(_source), iColor(_iColor), vert1(_vert1), vert2(_vert2), vert3(_vert3), center(_center)
{
}

void _initialize(Memflags _mfp)
{
radius=0;
height=0;
width=0;
kind.initialize(_mfp);
message.initialize(_mfp);
source.initialize(_mfp);
iColor.initialize_empty(_mfp);
vert1.initialize_empty(_mfp);
vert2.initialize_empty(_mfp);
vert3.initialize_empty(_mfp);
center.initialize_empty(_mfp);

}

void _delete_data(bool _parallel)
{
kind.delete_data(_parallel);
message.delete_data(_parallel);
source.delete_data(_parallel);
iColor.delete_data(_parallel);
vert1.delete_data(_parallel);
vert2.delete_data(_parallel);
vert3.delete_data(_parallel);
center.delete_data(_parallel);

}

void _finished()
{
kind.finished();
message.finished();
source.finished();
iColor.finished();
vert1.finished();
vert2.finished();
vert3.finished();
center.finished();

}

~_sl_Image_0()
{
_delete_data(true);
_finished();
}
void _Reference()
{
kind.Reference();
message.Reference();
source.Reference();
iColor.Reference();
vert1.Reference();
vert2.Reference();
vert3.Reference();
center.Reference();

}

void _deFrag()
{
kind.deFrag();
message.deFrag();
source.deFrag();
iColor.deFrag();
vert1.deFrag();
vert2.deFrag();
vert3.deFrag();
center.deFrag();

}

void _parallel_deFrag(int _ln)
{
kind.parallel_deFrag(_ln);
message.parallel_deFrag(_ln);
source.parallel_deFrag(_ln);
iColor.parallel_deFrag(_ln);
vert1.parallel_deFrag(_ln);
vert2.parallel_deFrag(_ln);
vert3.parallel_deFrag(_ln);
center.parallel_deFrag(_ln);

}

void _fix_padding(_sl_Image_0& _old)
{
kind.fix_padding(_old.kind);
message.fix_padding(_old.message);
source.fix_padding(_old.source);

}

_sl_Image_0& operator=(const _sl_Image_0& _rhs)
{
kind = _rhs.kind;
iColor = _rhs.iColor;
vert1 = _rhs.vert1;
vert2 = _rhs.vert2;
vert3 = _rhs.vert3;
center = _rhs.center;
radius = _rhs.radius;
height = _rhs.height;
width = _rhs.width;
message = _rhs.message;
source = _rhs.source;

return *this;
}

void _hard_copy(_sl_Image_0& _rhs, int _ln)
{
kind.hard_copy(_rhs.kind, _ln);
iColor.hard_copy(_rhs.iColor, _ln);
vert1.hard_copy(_rhs.vert1, _ln);
vert2.hard_copy(_rhs.vert2, _ln);
vert3.hard_copy(_rhs.vert3, _ln);
center.hard_copy(_rhs.center, _ln);
radius = _rhs.radius;
height = _rhs.height;
width = _rhs.width;
message.hard_copy(_rhs.message, _ln);
source.hard_copy(_rhs.source, _ln);
}

ostream& _toString(ostream& _stream) const
{
_stream<<"(";
_stream<<"center:"<<center<<","<<"height:"<<height<<","<<"iColor:"<<iColor<<","<<"kind:"<<kind<<","<<"message:"<<message<<","<<"radius:"<<radius<<","<<"source:"<<source<<","<<"vert1:"<<vert1<<","<<"vert2:"<<vert2<<","<<"vert3:"<<vert3<<","<<"width:"<<width;
_stream<<")";
return _stream;
}

string _toString() const
{
ostringstream _stream;
_toString(_stream);
return _stream.str();
}

};

//-----------------------------------------

//-----------------------------------------
// _sl_Click_0 struct definition
//------------------------------------------
struct _sl_Click_0
{
bool clicked;
SLStruct<_sl_Point_0> clPoint;


_sl_Click_0():clicked(0), clPoint(false)
{
}

_sl_Click_0(Memflags _m):clicked(0), clPoint(false,_m)
{
}

_sl_Click_0(bool _clicked, SLStruct<_sl_Point_0> _clPoint):clicked(_clicked), clPoint(_clPoint)
{
}

void _initialize(Memflags _mfp)
{
clicked=0;
clPoint.initialize_empty(_mfp);

}

void _delete_data(bool _parallel)
{
clPoint.delete_data(_parallel);

}

void _finished()
{
clPoint.finished();

}

~_sl_Click_0()
{
_delete_data(true);
_finished();
}
void _Reference()
{
clPoint.Reference();

}

void _deFrag()
{
clPoint.deFrag();

}

void _parallel_deFrag(int _ln)
{
clPoint.parallel_deFrag(_ln);

}

void _fix_padding(_sl_Click_0& _old)
{

}

_sl_Click_0& operator=(const _sl_Click_0& _rhs)
{
clicked = _rhs.clicked;
clPoint = _rhs.clPoint;

return *this;
}

void _hard_copy(_sl_Click_0& _rhs, int _ln)
{
clicked = _rhs.clicked;
clPoint.hard_copy(_rhs.clPoint, _ln);
}

ostream& _toString(ostream& _stream) const
{
_stream<<"(";
_stream<<"clPoint:"<<clPoint<<","<<"clicked:"<<clicked;
_stream<<")";
return _stream;
}

string _toString() const
{
ostringstream _stream;
_toString(_stream);
return _stream.str();
}

};

//-----------------------------------------

//-----------------------------------------
// _sl_Input_0 struct definition
//------------------------------------------
struct _sl_Input_0
{
Sequence< char > keys;
SLStruct<_sl_Click_0> iClick;


_sl_Input_0():keys(), iClick(false)
{
}

_sl_Input_0(Memflags _m):keys(_m), iClick(false,_m)
{
}

_sl_Input_0(Sequence< char > _keys, SLStruct<_sl_Click_0> _iClick):keys(_keys), iClick(_iClick)
{
}

void _initialize(Memflags _mfp)
{
keys.initialize(_mfp);
iClick.initialize_empty(_mfp);

}

void _delete_data(bool _parallel)
{
keys.delete_data(_parallel);
iClick.delete_data(_parallel);

}

void _finished()
{
keys.finished();
iClick.finished();

}

~_sl_Input_0()
{
_delete_data(true);
_finished();
}
void _Reference()
{
keys.Reference();
iClick.Reference();

}

void _deFrag()
{
keys.deFrag();
iClick.deFrag();

}

void _parallel_deFrag(int _ln)
{
keys.parallel_deFrag(_ln);
iClick.parallel_deFrag(_ln);

}

void _fix_padding(_sl_Input_0& _old)
{
keys.fix_padding(_old.keys);

}

_sl_Input_0& operator=(const _sl_Input_0& _rhs)
{
iClick = _rhs.iClick;
keys = _rhs.keys;

return *this;
}

void _hard_copy(_sl_Input_0& _rhs, int _ln)
{
iClick.hard_copy(_rhs.iClick, _ln);
keys.hard_copy(_rhs.keys, _ln);
}

ostream& _toString(ostream& _stream) const
{
_stream<<"(";
_stream<<"iClick:"<<iClick<<","<<"keys:"<<keys;
_stream<<")";
return _stream;
}

string _toString() const
{
ostringstream _stream;
_toString(_stream);
return _stream.str();
}

};

//-----------------------------------------

//-----------------------------------------
// _sl_State_0 struct definition
//------------------------------------------
struct _sl_State_0
{
Sequence< _sl_Ball_0 > balls;


_sl_State_0():balls()
{
}

_sl_State_0(Memflags _m):balls(_m)
{
}

_sl_State_0(Sequence< _sl_Ball_0 > _balls):balls(_balls)
{
}

void _initialize(Memflags _mfp)
{
balls.initialize(_mfp);

}

void _delete_data(bool _parallel)
{
balls.delete_data(_parallel);

}

void _finished()
{
balls.finished();

}

~_sl_State_0()
{
_delete_data(true);
_finished();
}
void _Reference()
{
balls.Reference();

}

void _deFrag()
{
balls.deFrag();

}

void _parallel_deFrag(int _ln)
{
balls.parallel_deFrag(_ln);

}

void _fix_padding(_sl_State_0& _old)
{
balls.fix_padding(_old.balls);

}

_sl_State_0& operator=(const _sl_State_0& _rhs)
{
balls = _rhs.balls;

return *this;
}

void _hard_copy(_sl_State_0& _rhs, int _ln)
{
balls.hard_copy(_rhs.balls, _ln);
}

ostream& _toString(ostream& _stream) const
{
_stream<<"(";
_stream<<"balls:"<<balls;
_stream<<")";
return _stream;
}

string _toString() const
{
ostringstream _stream;
_toString(_stream);
return _stream.str();
}

};

//-----------------------------------------

//-----------------------------------------
// _sl_Ball_0 struct definition
//------------------------------------------
struct _sl_Ball_0
{
int ballRad;
SL_FLOAT bxv;
SL_FLOAT byv;
SLStruct<_sl_Point_0> ballCenter;


_sl_Ball_0():ballRad(0), bxv(0), byv(0), ballCenter(false)
{
}

_sl_Ball_0(Memflags _m):ballRad(0), bxv(0), byv(0), ballCenter(false,_m)
{
}

_sl_Ball_0(int _ballRad, SL_FLOAT _bxv, SL_FLOAT _byv, SLStruct<_sl_Point_0> _ballCenter):ballRad(_ballRad), bxv(_bxv), byv(_byv), ballCenter(_ballCenter)
{
}

void _initialize(Memflags _mfp)
{
ballRad=0;
bxv=0;
byv=0;
ballCenter.initialize_empty(_mfp);

}

void _delete_data(bool _parallel)
{
ballCenter.delete_data(_parallel);

}

void _finished()
{
ballCenter.finished();

}

~_sl_Ball_0()
{
_delete_data(true);
_finished();
}
void _Reference()
{
ballCenter.Reference();

}

void _deFrag()
{
ballCenter.deFrag();

}

void _parallel_deFrag(int _ln)
{
ballCenter.parallel_deFrag(_ln);

}

void _fix_padding(_sl_Ball_0& _old)
{

}

_sl_Ball_0& operator=(const _sl_Ball_0& _rhs)
{
ballCenter = _rhs.ballCenter;
ballRad = _rhs.ballRad;
bxv = _rhs.bxv;
byv = _rhs.byv;

return *this;
}

void _hard_copy(_sl_Ball_0& _rhs, int _ln)
{
ballCenter.hard_copy(_rhs.ballCenter, _ln);
ballRad = _rhs.ballRad;
bxv = _rhs.bxv;
byv = _rhs.byv;
}

ostream& _toString(ostream& _stream) const
{
_stream<<"(";
_stream<<"ballCenter:"<<ballCenter<<","<<"ballRad:"<<ballRad<<","<<"bxv:"<<bxv<<","<<"byv:"<<byv;
_stream<<")";
return _stream;
}

string _toString() const
{
ostringstream _stream;
_toString(_stream);
return _stream.str();
}

};

//-----------------------------------------

ostream &operator<<(ostream &stream, const _sl_Point_0& s);
bool operator==(const _sl_Point_0&_lhs, const _sl_Point_0&_rhs);
bool operator!=(const _sl_Point_0&_lhs, const _sl_Point_0&_rhs);
ostream &operator<<(ostream &stream, const _sl_Color_0& s);
bool operator==(const _sl_Color_0&_lhs, const _sl_Color_0&_rhs);
bool operator!=(const _sl_Color_0&_lhs, const _sl_Color_0&_rhs);
ostream &operator<<(ostream &stream, const _sl_Image_0& s);
bool operator==(const _sl_Image_0&_lhs, const _sl_Image_0&_rhs);
bool operator!=(const _sl_Image_0&_lhs, const _sl_Image_0&_rhs);
ostream &operator<<(ostream &stream, const _sl_Click_0& s);
bool operator==(const _sl_Click_0&_lhs, const _sl_Click_0&_rhs);
bool operator!=(const _sl_Click_0&_lhs, const _sl_Click_0&_rhs);
ostream &operator<<(ostream &stream, const _sl_Input_0& s);
bool operator==(const _sl_Input_0&_lhs, const _sl_Input_0&_rhs);
bool operator!=(const _sl_Input_0&_lhs, const _sl_Input_0&_rhs);
ostream &operator<<(ostream &stream, const _sl_State_0& s);
bool operator==(const _sl_State_0&_lhs, const _sl_State_0&_rhs);
bool operator!=(const _sl_State_0&_lhs, const _sl_State_0&_rhs);
ostream &operator<<(ostream &stream, const _sl_Ball_0& s);
bool operator==(const _sl_Ball_0&_lhs, const _sl_Ball_0&_rhs);
bool operator!=(const _sl_Ball_0&_lhs, const _sl_Ball_0&_rhs);

#ifdef _WIN32
#endif


typedef _sl_Point_0 _sl_Point;
typedef _sl_Color_0 _sl_Color;
typedef _sl_Image_0 _sl_Image;
typedef _sl_Click_0 _sl_Click;
typedef _sl_Input_0 _sl_Input;
typedef _sl_State_0 _sl_State;
typedef _sl_Ball_0 _sl_Ball;

void sl_sounds(_sl_Input_0 &_SequenceL__Arg_arg1, _sl_State_0 &_SequenceL__Arg_arg2, int _n, Sequence< Sequence< char > > &_SequenceL_);
void sl_newState(_sl_Input_0 &_SequenceL__Arg_arg1, _sl_State_0 &_SequenceL__Arg_arg2, int _n, _sl_State_0 &_SequenceL_);
void sl_images(_sl_State_0 &_SequenceL__Arg_arg1, int _n, Sequence< _sl_Image_0 > &_SequenceL_);
void sl_initialState( int _n, _sl_State_0 &_SequenceL_);

#endif
