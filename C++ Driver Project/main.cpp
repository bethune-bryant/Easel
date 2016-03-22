#include "main.h"
class Stack;

#include <tbb/task.h>
#include <tbb/parallel_for.h>
using namespace tbb;
typedef void (*_sl_fun_pointer)(void);
void SequenceL_sounds_0(_sl_Input_0 &_SequenceL__Arg_I, _sl_State_0 &_SequenceL__Arg_S, Sequence< Sequence< char > > &_SequenceL__result);
void SequenceL_newState_0(_sl_Input_0 &_SequenceL__Arg_I, _sl_State_0 &_SequenceL__Arg_S, _sl_State_0 &_SequenceL__result);
void SequenceL_images_0(_sl_State_0 &_SequenceL__Arg_S, Sequence< _sl_Image_0 > &_SequenceL__result);
void SequenceL_checkVerticalBoundaries_0(_sl_Ball_0 &_SequenceL__Arg_ball, bool &_SequenceL__result);
void SequenceL_checkHorizontalBoundaries_0(_sl_Ball_0 &_SequenceL__Arg_ball, bool &_SequenceL__result);
void SequenceL_buildState_0(Sequence< _sl_Ball_0 > &_SequenceL__Arg_ba, _sl_State_0 &_SequenceL__result);
void SequenceL_ballMove_0(_sl_Ball_0 &_SequenceL__Arg_B, Sequence< _sl_Ball_0 > &_SequenceL__Arg_otherBalls, _sl_Ball_0 &_SequenceL__result);
void SequenceL_drop_1(Sequence< _sl_Ball_0 > &_SequenceL__Arg_list, int _SequenceL__Arg_n, Sequence< _sl_Ball_0 > &_SequenceL__result);
void SequenceL_slowDown_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result);
void SequenceL_speedUp_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result);
void SequenceL_ballImg_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Image_0 &_SequenceL__result);
void SequenceL_newDisc_0(_sl_Point_0 &_SequenceL__Arg_ce, int _SequenceL__Arg_rad, _sl_Color_0 &_SequenceL__Arg_c, _sl_Image_0 &_SequenceL__result);
void SequenceL_newPoint_0(int _SequenceL__Arg_a, int _SequenceL__Arg_b, _sl_Point_0 &_SequenceL__result);
void SequenceL_ballBottom_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result);
void SequenceL_ballTop_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result);
void SequenceL_ballLeft_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result);
void SequenceL_ballRight_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result);
void SequenceL_newBall_0(_sl_Point_0 &_SequenceL__Arg_c, int _SequenceL__Arg_r, SL_FLOAT _SequenceL__Arg_x, SL_FLOAT _SequenceL__Arg_y, _sl_Ball_0 &_SequenceL__result);
void SequenceL_floatToInt_2(SL_FLOAT _SequenceL__Arg_float, int &_SequenceL__result);
void SequenceL_yFlip_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result);
void SequenceL_xFlip_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result);
void SequenceL_mySign_0(int _SequenceL__Arg_x, int &_SequenceL__result);
void SequenceL_newGraphic_0(_sl_Point_0 &_SequenceL__Arg_ce, Sequence< char > &_SequenceL__Arg_file, _sl_Image_0 &_SequenceL__result);
void SequenceL_newColor_0(int _SequenceL__Arg_r, int _SequenceL__Arg_g, int _SequenceL__Arg_b, _sl_Color_0 &_SequenceL__result);
void SequenceL__parallel_sounds_0(_sl_Input_0 &_SequenceL__Arg_I, _sl_State_0 &_SequenceL__Arg_S, Sequence< Sequence< char > > &_SequenceL__result);
class SequenceL__sl_sounds_nt7_: public NTObj
{
	private:
		_sl_Input_0 &_SequenceL__Arg_I;
		int _SequenceL__start;
		int _SequenceL__stop;
		 Sequence< bool > &_SequenceL__result8;

	public:
		SequenceL__sl_sounds_nt7_(_sl_Input_0 &_inp1, int _inp2, int _inp3, Sequence< bool > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_I(_inp1), _SequenceL__start(_inp2), _SequenceL__stop(_inp3), _SequenceL__result8(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt5_: public NTObj
{
	private:
		Sequence< bool > &_SequenceL_tmp8;
		Sequence< bool > &_SequenceL_tmp11;
		int _SequenceL__start;
		int _SequenceL__stop;
		 Sequence< bool > &_SequenceL__result6;

	public:
		SequenceL__sl_sounds_nt5_(Sequence< bool > &_inp1, Sequence< bool > &_inp2, int _inp3, int _inp4, Sequence< bool > &_out1): NTObj(__LINE__,false), _SequenceL_tmp8(_inp1), _SequenceL_tmp11(_inp2), _SequenceL__start(_inp3), _SequenceL__stop(_inp4), _SequenceL__result6(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt3_: public NTObj
{
	private:
		_sl_State_0 &_SequenceL__Arg_S;
		int _SequenceL__start;
		int _SequenceL__stop;
		 Sequence< bool > &_SequenceL__result4;

	public:
		SequenceL__sl_sounds_nt3_(_sl_State_0 &_inp1, int _inp2, int _inp3, Sequence< bool > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_S(_inp1), _SequenceL__start(_inp2), _SequenceL__stop(_inp3), _SequenceL__result4(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt1_: public NTObj
{
	private:
		_sl_State_0 &_SequenceL__Arg_S;
		int _SequenceL__start;
		int _SequenceL__stop;
		 Sequence< bool > &_SequenceL__result2;

	public:
		SequenceL__sl_sounds_nt1_(_sl_State_0 &_inp1, int _inp2, int _inp3, Sequence< bool > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_S(_inp1), _SequenceL__start(_inp2), _SequenceL__stop(_inp3), _SequenceL__result2(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
void SequenceL__parallel_newState_0(_sl_Input_0 &_SequenceL__Arg_I, _sl_State_0 &_SequenceL__Arg_S, _sl_State_0 &_SequenceL__result);
class SequenceL__sl_sounds_nt23_: public NTObj
{
	private:
		_sl_Input_0 &_SequenceL__Arg_I;
		int _SequenceL__start;
		int _SequenceL__stop;
		 Sequence< bool > &_SequenceL__result24;

	public:
		SequenceL__sl_sounds_nt23_(_sl_Input_0 &_inp1, int _inp2, int _inp3, Sequence< bool > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_I(_inp1), _SequenceL__start(_inp2), _SequenceL__stop(_inp3), _SequenceL__result24(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt21_: public NTObj
{
	private:
		_sl_Input_0 &_SequenceL__Arg_I;
		int _SequenceL__start;
		int _SequenceL__stop;
		 Sequence< bool > &_SequenceL__result22;

	public:
		SequenceL__sl_sounds_nt21_(_sl_Input_0 &_inp1, int _inp2, int _inp3, Sequence< bool > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_I(_inp1), _SequenceL__start(_inp2), _SequenceL__stop(_inp3), _SequenceL__result22(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt19_: public NTObj
{
	private:
		_sl_Input_0 &_SequenceL__Arg_I;
		int _SequenceL__start;
		int _SequenceL__stop;
		 Sequence< bool > &_SequenceL__result20;

	public:
		SequenceL__sl_sounds_nt19_(_sl_Input_0 &_inp1, int _inp2, int _inp3, Sequence< bool > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_I(_inp1), _SequenceL__start(_inp2), _SequenceL__stop(_inp3), _SequenceL__result20(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt17_: public NTObj
{
	private:
		_sl_State_0 &_SequenceL__Arg_S;
		 Sequence< _sl_Ball_0 > &_SequenceL__result18;

	public:
		SequenceL__sl_sounds_nt17_(_sl_State_0 &_inp1, Sequence< _sl_Ball_0 > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_S(_inp1), _SequenceL__result18(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt15_: public NTObj
{
	private:
		Sequence< _sl_Ball_0 > &_SequenceL__Arg_newPos;
		 Sequence< _sl_Ball_0 > &_SequenceL__result16;

	public:
		SequenceL__sl_sounds_nt15_(Sequence< _sl_Ball_0 > &_inp1, Sequence< _sl_Ball_0 > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_newPos(_inp1), _SequenceL__result16(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt13_: public NTObj
{
	private:
		_sl_State_0 &_SequenceL__Arg_S;
		 Sequence< _sl_Ball_0 > &_SequenceL__result14;

	public:
		SequenceL__sl_sounds_nt13_(_sl_State_0 &_inp1, Sequence< _sl_Ball_0 > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_S(_inp1), _SequenceL__result14(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt11_: public NTObj
{
	private:
		Sequence< _sl_Ball_0 > &_SequenceL__Arg_newPos;
		 Sequence< _sl_Ball_0 > &_SequenceL__result12;

	public:
		SequenceL__sl_sounds_nt11_(Sequence< _sl_Ball_0 > &_inp1, Sequence< _sl_Ball_0 > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_newPos(_inp1), _SequenceL__result12(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
class SequenceL__sl_sounds_nt9_: public NTObj
{
	private:
		_sl_State_0 &_SequenceL__Arg_S;
		 Sequence< _sl_Ball_0 > &_SequenceL__result10;

	public:
		SequenceL__sl_sounds_nt9_(_sl_State_0 &_inp1, Sequence< _sl_Ball_0 > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_S(_inp1), _SequenceL__result10(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
void SequenceL__parallel_images_0(_sl_State_0 &_SequenceL__Arg_S, Sequence< _sl_Image_0 > &_SequenceL__result);
class SequenceL__sl_sounds_nt25_: public NTObj
{
	private:
		_sl_State_0 &_SequenceL__Arg_S;
		 Sequence< _sl_Image_0 > &_SequenceL__result26;

	public:
		SequenceL__sl_sounds_nt25_(_sl_State_0 &_inp1, Sequence< _sl_Image_0 > &_out1): NTObj(__LINE__,false), _SequenceL__Arg_S(_inp1), _SequenceL__result26(_out1)
		{
		}
		void operator() (const blocked_range<int>& r) const;
};
_sl_State_0 _SequenceL_initialState_0(cspace);
void SequenceL__parallel_checkVerticalBoundaries_0(_sl_Ball_0 &_SequenceL__Arg_ball, bool &_SequenceL__result);
void SequenceL__parallel_checkHorizontalBoundaries_0(_sl_Ball_0 &_SequenceL__Arg_ball, bool &_SequenceL__result);
void SequenceL__parallel_buildState_0(Sequence< _sl_Ball_0 > &_SequenceL__Arg_ba, _sl_State_0 &_SequenceL__result);
void SequenceL__parallel_ballMove_0(_sl_Ball_0 &_SequenceL__Arg_B, Sequence< _sl_Ball_0 > &_SequenceL__Arg_otherBalls, _sl_Ball_0 &_SequenceL__result);
void SequenceL__parallel_drop_1(Sequence< _sl_Ball_0 > &_SequenceL__Arg_list, int _SequenceL__Arg_n, Sequence< _sl_Ball_0 > &_SequenceL__result);
void SequenceL__parallel_slowDown_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result);
void SequenceL__parallel_speedUp_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result);
void SequenceL__parallel_ballImg_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Image_0 &_SequenceL__result);
void SequenceL__parallel_newDisc_0(_sl_Point_0 &_SequenceL__Arg_ce, int _SequenceL__Arg_rad, _sl_Color_0 &_SequenceL__Arg_c, _sl_Image_0 &_SequenceL__result);
_sl_Color_0 _SequenceL_dBlack_0(cspace);
void SequenceL__parallel_newPoint_0(int _SequenceL__Arg_a, int _SequenceL__Arg_b, _sl_Point_0 &_SequenceL__result);
Sequence< _sl_Ball_0 > _SequenceL_ballStart_0(cspace);
void SequenceL__parallel_ballBottom_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result);
void SequenceL__parallel_ballTop_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result);
void SequenceL__parallel_ballLeft_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result);
void SequenceL__parallel_ballRight_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result);
void SequenceL__parallel_newBall_0(_sl_Point_0 &_SequenceL__Arg_c, int _SequenceL__Arg_r, SL_FLOAT _SequenceL__Arg_x, SL_FLOAT _SequenceL__Arg_y, _sl_Ball_0 &_SequenceL__result);
void SequenceL__parallel_floatToInt_2(SL_FLOAT _SequenceL__Arg_float, int &_SequenceL__result);
void SequenceL__parallel_yFlip_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result);
void SequenceL__parallel_xFlip_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result);
void SequenceL__parallel_mySign_0(int _SequenceL__Arg_x, int &_SequenceL__result);
void SequenceL__parallel_newGraphic_0(_sl_Point_0 &_SequenceL__Arg_ce, Sequence< char > &_SequenceL__Arg_file, _sl_Image_0 &_SequenceL__result);
_sl_Point_0 _SequenceL_originPoint_0(cspace);
void SequenceL__parallel_newColor_0(int _SequenceL__Arg_r, int _SequenceL__Arg_g, int _SequenceL__Arg_b, _sl_Color_0 &_SequenceL__result);
_sl_Color_0 _SequenceL_dViolet_0(cspace);
class SequenceL__sl_sounds_ballMovess_0: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 Sequence< _sl_Ball_0 > &_SequenceL__Arg_otherBalls;
		 _sl_Ball_0 &_SequenceL__result;
_sl_Ball_0 _SequenceL__Arg_yBall;
bool _SequenceL_tmp6;
_sl_Ball_0 _SequenceL__Arg_xBall;
bool _SequenceL_tmp3;
int _SequenceL_tmp11;
int _SequenceL_tmp16;
_sl_Point_0 _SequenceL_tmp17;

	public:
		SequenceL__sl_sounds_ballMovess_0(_sl_Ball_0 &_inp1, Sequence< _sl_Ball_0 > &_inp2, _sl_Ball_0 &_out1): _SequenceL__Arg_B(_inp1), _SequenceL__Arg_otherBalls(_inp2), _SequenceL__result(_out1), _SequenceL__Arg_yBall(cspace), _SequenceL__Arg_xBall(cspace), _SequenceL_tmp17(cspace)
		{
		}
		task *execute();

};
class SequenceL__sl_sounds_csp27_: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 _sl_Ball_0 &_SequenceL__Arg_yBall;
		 int &_SequenceL_tmp11;
SL_FLOAT _SequenceL_tmp10;

	public:
		SequenceL__sl_sounds_csp27_(_sl_Ball_0 &_inp1, _sl_Ball_0 &_inp2, int &_out1): _SequenceL__Arg_B(_inp1), _SequenceL__Arg_yBall(_inp2), _SequenceL_tmp11(_out1)
		{
		}
		task *execute();

};
class SequenceL__sl_sounds_csp28_: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 _sl_Ball_0 &_SequenceL__Arg_yBall;
		 int &_SequenceL_tmp16;
SL_FLOAT _SequenceL_tmp15;

	public:
		SequenceL__sl_sounds_csp28_(_sl_Ball_0 &_inp1, _sl_Ball_0 &_inp2, int &_out1): _SequenceL__Arg_B(_inp1), _SequenceL__Arg_yBall(_inp2), _SequenceL_tmp16(_out1)
		{
		}
		task *execute();

};
class SequenceL__sl_sounds_slowDowns_0: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 _sl_Ball_0 &_SequenceL__result;
SL_FLOAT _SequenceL_tmp7;
SL_FLOAT _SequenceL_tmp12;

	public:
		SequenceL__sl_sounds_slowDowns_0(_sl_Ball_0 &_inp1, _sl_Ball_0 &_out1): _SequenceL__Arg_B(_inp1), _SequenceL__result(_out1)
		{
		}
		task *execute();

};
class SequenceL__sl_sounds_csp32_: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 SL_FLOAT &_SequenceL_tmp7;
int _SequenceL_tmp6;
int _SequenceL_tmp5;

	public:
		SequenceL__sl_sounds_csp32_(_sl_Ball_0 &_inp1, SL_FLOAT &_out1): _SequenceL__Arg_B(_inp1), _SequenceL_tmp7(_out1)
		{
		}
		task *execute();

};
class SequenceL__sl_sounds_csp33_: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 SL_FLOAT &_SequenceL_tmp12;
int _SequenceL_tmp11;
int _SequenceL_tmp10;

	public:
		SequenceL__sl_sounds_csp33_(_sl_Ball_0 &_inp1, SL_FLOAT &_out1): _SequenceL__Arg_B(_inp1), _SequenceL_tmp12(_out1)
		{
		}
		task *execute();

};
class SequenceL__sl_sounds_speedUps_0: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 _sl_Ball_0 &_SequenceL__result;
SL_FLOAT _SequenceL_tmp7;
SL_FLOAT _SequenceL_tmp12;

	public:
		SequenceL__sl_sounds_speedUps_0(_sl_Ball_0 &_inp1, _sl_Ball_0 &_out1): _SequenceL__Arg_B(_inp1), _SequenceL__result(_out1)
		{
		}
		task *execute();

};
class SequenceL__sl_sounds_csp37_: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 SL_FLOAT &_SequenceL_tmp7;
int _SequenceL_tmp6;
int _SequenceL_tmp5;

	public:
		SequenceL__sl_sounds_csp37_(_sl_Ball_0 &_inp1, SL_FLOAT &_out1): _SequenceL__Arg_B(_inp1), _SequenceL_tmp7(_out1)
		{
		}
		task *execute();

};
class SequenceL__sl_sounds_csp38_: public task
{
	private:
		 _sl_Ball_0 &_SequenceL__Arg_B;
		 SL_FLOAT &_SequenceL_tmp12;
int _SequenceL_tmp11;
int _SequenceL_tmp10;

	public:
		SequenceL__sl_sounds_csp38_(_sl_Ball_0 &_inp1, SL_FLOAT &_out1): _SequenceL__Arg_B(_inp1), _SequenceL_tmp12(_out1)
		{
		}
		task *execute();

};

ostream &operator<<(ostream &stream, const _sl_Point_0& s)
{
return s._toString(stream);
}

bool operator==(const _sl_Point_0&_lhs, const _sl_Point_0&_rhs)
{
return ((_lhs.x == _rhs.x)&&(_lhs.y == _rhs.y));
}
bool operator!=(const _sl_Point_0&_lhs, const _sl_Point_0&_rhs)
{
 return ((_lhs.x != _rhs.x)||(_lhs.y != _rhs.y));
}
ostream &operator<<(ostream &stream, const _sl_Color_0& s)
{
return s._toString(stream);
}

bool operator==(const _sl_Color_0&_lhs, const _sl_Color_0&_rhs)
{
return ((_lhs.red == _rhs.red)&&(_lhs.green == _rhs.green)&&(_lhs.blue == _rhs.blue));
}
bool operator!=(const _sl_Color_0&_lhs, const _sl_Color_0&_rhs)
{
 return ((_lhs.red != _rhs.red)||(_lhs.green != _rhs.green)||(_lhs.blue != _rhs.blue));
}
ostream &operator<<(ostream &stream, const _sl_Image_0& s)
{
return s._toString(stream);
}

bool operator==(const _sl_Image_0&_lhs, const _sl_Image_0&_rhs)
{
return ((_lhs.kind == _rhs.kind)&&(_lhs.iColor == _rhs.iColor)&&(_lhs.vert1 == _rhs.vert1)&&(_lhs.vert2 == _rhs.vert2)&&(_lhs.vert3 == _rhs.vert3)&&(_lhs.center == _rhs.center)&&(_lhs.radius == _rhs.radius)&&(_lhs.height == _rhs.height)&&(_lhs.width == _rhs.width)&&(_lhs.message == _rhs.message)&&(_lhs.source == _rhs.source));
}
bool operator!=(const _sl_Image_0&_lhs, const _sl_Image_0&_rhs)
{
 return ((_lhs.kind != _rhs.kind)||(_lhs.iColor != _rhs.iColor)||(_lhs.vert1 != _rhs.vert1)||(_lhs.vert2 != _rhs.vert2)||(_lhs.vert3 != _rhs.vert3)||(_lhs.center != _rhs.center)||(_lhs.radius != _rhs.radius)||(_lhs.height != _rhs.height)||(_lhs.width != _rhs.width)||(_lhs.message != _rhs.message)||(_lhs.source != _rhs.source));
}
ostream &operator<<(ostream &stream, const _sl_Click_0& s)
{
return s._toString(stream);
}

bool operator==(const _sl_Click_0&_lhs, const _sl_Click_0&_rhs)
{
return ((_lhs.clicked == _rhs.clicked)&&(_lhs.clPoint == _rhs.clPoint));
}
bool operator!=(const _sl_Click_0&_lhs, const _sl_Click_0&_rhs)
{
 return ((_lhs.clicked != _rhs.clicked)||(_lhs.clPoint != _rhs.clPoint));
}
ostream &operator<<(ostream &stream, const _sl_Input_0& s)
{
return s._toString(stream);
}

bool operator==(const _sl_Input_0&_lhs, const _sl_Input_0&_rhs)
{
return ((_lhs.iClick == _rhs.iClick)&&(_lhs.keys == _rhs.keys));
}
bool operator!=(const _sl_Input_0&_lhs, const _sl_Input_0&_rhs)
{
 return ((_lhs.iClick != _rhs.iClick)||(_lhs.keys != _rhs.keys));
}
ostream &operator<<(ostream &stream, const _sl_State_0& s)
{
return s._toString(stream);
}

bool operator==(const _sl_State_0&_lhs, const _sl_State_0&_rhs)
{
return ((_lhs.balls == _rhs.balls));
}
bool operator!=(const _sl_State_0&_lhs, const _sl_State_0&_rhs)
{
 return ((_lhs.balls != _rhs.balls));
}
ostream &operator<<(ostream &stream, const _sl_Ball_0& s)
{
return s._toString(stream);
}

bool operator==(const _sl_Ball_0&_lhs, const _sl_Ball_0&_rhs)
{
return ((_lhs.ballCenter == _rhs.ballCenter)&&(_lhs.ballRad == _rhs.ballRad)&&(_lhs.bxv == _rhs.bxv)&&(_lhs.byv == _rhs.byv));
}
bool operator!=(const _sl_Ball_0&_lhs, const _sl_Ball_0&_rhs)
{
 return ((_lhs.ballCenter != _rhs.ballCenter)||(_lhs.ballRad != _rhs.ballRad)||(_lhs.bxv != _rhs.bxv)||(_lhs.byv != _rhs.byv));
}

void _SequenceL_init_sl_sounds_globals()
{

}

void _SequenceL_init_sl_newState_globals()
{

}

void _SequenceL_init_sl_images_globals()
{
{

SequenceL__parallel_newColor_0(0, 0, 0, _SequenceL_dBlack_0);	/*newStructs.sl:23: newColor(0, 0, 0)*/
}
{

SequenceL__parallel_newPoint_0(0, 0, _SequenceL_originPoint_0);	/*newStructs.sl:51: newPoint(0,0)*/
}
{

SequenceL__parallel_newColor_0(148, 0, 211, _SequenceL_dViolet_0);	/*newStructs.sl:30: newColor(148, 0, 211)*/
}

}

void _SequenceL_init_sl_initialState_globals()
{
{
_sl_Ball_0 _SequenceL_tmp3(cspace);
_sl_Point_0 _SequenceL_tmp1(cspace);
SL_FLOAT _SequenceL_tmp2;
_sl_Ball_0 _SequenceL_tmp6(cspace);
_sl_Point_0 _SequenceL_tmp4(cspace);
SL_FLOAT _SequenceL_tmp5;
_sl_Ball_0 _SequenceL_tmp8(cspace);
_sl_Point_0 _SequenceL_tmp7(cspace);
_sl_Ball_0 _SequenceL_tmp11(cspace);
_sl_Point_0 _SequenceL_tmp9(cspace);
SL_FLOAT _SequenceL_tmp10;

_SequenceL_ballStart_0.setSize(4);	
SequenceL__parallel_newPoint_0(900, 600, _SequenceL_tmp1);	/*newStructs.sl:53: newPoint(900,600)*/
_SequenceL_tmp2 = (-6.0);	/*newStructs.sl:53: -6.0*/
SequenceL__parallel_newBall_0(_SequenceL_tmp1, 15, 4.0, _SequenceL_tmp2, _SequenceL_tmp3);	/*newStructs.sl:53: newBall(newPoint(900,600), 15, 4.0, -6.0)*/
_SequenceL_tmp1._delete_data(false);	
_SequenceL_tmp1._finished();	
_SequenceL_ballStart_0[1] = _SequenceL_tmp3;	
_SequenceL_tmp3._delete_data(false);	
_SequenceL_tmp3._finished();	
SequenceL__parallel_newPoint_0(100, 500, _SequenceL_tmp4);	/*newStructs.sl:53: newPoint(100,500)*/
_SequenceL_tmp5 = (-9.0);	/*newStructs.sl:53: -9.0*/
SequenceL__parallel_newBall_0(_SequenceL_tmp4, 10, 7.0, _SequenceL_tmp5, _SequenceL_tmp6);	/*newStructs.sl:53: newBall(newPoint(100,500), 10, 7.0, -9.0)*/
_SequenceL_tmp4._delete_data(false);	
_SequenceL_tmp4._finished();	
_SequenceL_ballStart_0[2] = _SequenceL_tmp6;	
_SequenceL_tmp6._delete_data(false);	
_SequenceL_tmp6._finished();	
SequenceL__parallel_newPoint_0(600, 200, _SequenceL_tmp7);	/*newStructs.sl:53: newPoint(600,200)*/
SequenceL__parallel_newBall_0(_SequenceL_tmp7, 8, 8.0, 2.0, _SequenceL_tmp8);	/*newStructs.sl:53: newBall(newPoint(600,200), 8, 8.0, 2.0)*/
_SequenceL_tmp7._delete_data(false);	
_SequenceL_tmp7._finished();	
_SequenceL_ballStart_0[3] = _SequenceL_tmp8;	
_SequenceL_tmp8._delete_data(false);	
_SequenceL_tmp8._finished();	
SequenceL__parallel_newPoint_0(700, 200, _SequenceL_tmp9);	/*newStructs.sl:53: newPoint(700,200)*/
_SequenceL_tmp10 = (-4.0);	/*newStructs.sl:53: -4.0*/
SequenceL__parallel_newBall_0(_SequenceL_tmp9, 20, _SequenceL_tmp10, 6.0, _SequenceL_tmp11);	/*newStructs.sl:53: newBall(newPoint(700,200), 20, -4.0, 6.0)*/
_SequenceL_tmp9._delete_data(false);	
_SequenceL_tmp9._finished();	
_SequenceL_ballStart_0[4] = _SequenceL_tmp11;	
_SequenceL_tmp11._delete_data(false);	
_SequenceL_tmp11._finished();	
}
{
Sequence< _sl_Ball_0 > _SequenceL_tmp1(cspace);

_SequenceL_tmp1 = _SequenceL_ballStart_0;	
SequenceL__parallel_buildState_0(_SequenceL_tmp1, _SequenceL_initialState_0);	/*newStructs.sl:95: buildState(ballStart)*/
_SequenceL_tmp1.delete_data(false);	
_SequenceL_tmp1.finished();	
}

}

void _SequenceL_delete_sl_sounds_globals()
{

}

void _SequenceL_delete_sl_newState_globals()
{

}

void _SequenceL_delete_sl_images_globals()
{
_SequenceL_dBlack_0._delete_data(false);
_SequenceL_dBlack_0._finished();
_SequenceL_originPoint_0._delete_data(false);
_SequenceL_originPoint_0._finished();
_SequenceL_dViolet_0._delete_data(false);
_SequenceL_dViolet_0._finished();

}

void _SequenceL_delete_sl_initialState_globals()
{
_SequenceL_initialState_0._delete_data(false);
_SequenceL_initialState_0._finished();
_SequenceL_ballStart_0.delete_data(false);
_SequenceL_ballStart_0.finished();

}

#ifdef _WIN32
Sequence< Sequence< char > > _sl_vc10_main_dummy_1(cspace);
Sequence< _sl_Image_0 > _sl_vc10_main_dummy_2(cspace);
Sequence< char > _sl_vc10_main_dummy_3(cspace);
Sequence< bool > _sl_vc10_main_dummy_4(cspace);
Sequence< Empty > _sl_vc10_main_dummy_5(cspace);
Sequence< _sl_Ball_0 > _sl_vc10_main_dummy_6(cspace);
#endif

task *SequenceL__sl_sounds_csp38_::execute()
{
SequenceL_floatToInt_2(_SequenceL__Arg_B.byv, _SequenceL_tmp10);	/*newStructs.sl:89: floatToInt(B.byv)*/
SequenceL_mySign_0(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:89: mySign(floatToInt(B.byv))*/
_SequenceL_tmp12 = (_SequenceL__Arg_B.byv + _SequenceL_tmp11);	/*newStructs.sl:89: B.byv + mySign(floatToInt(B.byv))*/
_SequenceL__Arg_B._delete_data(true);	
return NULL;
}
task *SequenceL__sl_sounds_csp37_::execute()
{
SequenceL_floatToInt_2(_SequenceL__Arg_B.bxv, _SequenceL_tmp5);	/*newStructs.sl:89: floatToInt(B.bxv)*/
SequenceL_mySign_0(_SequenceL_tmp5, _SequenceL_tmp6);	/*newStructs.sl:89: mySign(floatToInt(B.bxv))*/
_SequenceL_tmp7 = (_SequenceL__Arg_B.bxv + _SequenceL_tmp6);	/*newStructs.sl:89: B.bxv + mySign(floatToInt(B.bxv))*/
_SequenceL__Arg_B._delete_data(true);	
return NULL;
}
task *SequenceL__sl_sounds_speedUps_0::execute()
{
_SequenceL__Arg_B._Reference();	
_SequenceL__Arg_B._Reference();	
set_ref_count(3);
spawn(*new(allocate_child()) SequenceL__sl_sounds_csp37_(_SequenceL__Arg_B, _SequenceL_tmp7));
spawn_and_wait_for_all(*new(allocate_child()) SequenceL__sl_sounds_csp38_(_SequenceL__Arg_B, _SequenceL_tmp12));
SequenceL_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:89: newBall(B.ballCenter, B.ballRad, B.bxv + mySign(floatToInt(B.bxv)), B.byv + mySign(floatToInt(B.byv)))"), _SequenceL__Arg_B.ballRad, _SequenceL_tmp7, _SequenceL_tmp12, _SequenceL__result);	/*newStructs.sl:89: newBall(B.ballCenter, B.ballRad, B.bxv + mySign(floatToInt(B.bxv)), B.byv + mySign(floatToInt(B.byv)))*/
_SequenceL__Arg_B._delete_data(true);	
return NULL;
}
task *SequenceL__sl_sounds_csp33_::execute()
{
SequenceL_floatToInt_2(_SequenceL__Arg_B.byv, _SequenceL_tmp10);	/*newStructs.sl:91: floatToInt(B.byv)*/
SequenceL_mySign_0(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:91: mySign(floatToInt(B.byv))*/
_SequenceL_tmp12 = (_SequenceL__Arg_B.byv - _SequenceL_tmp11);	/*newStructs.sl:91: B.byv - mySign(floatToInt(B.byv))*/
_SequenceL__Arg_B._delete_data(true);	
return NULL;
}
task *SequenceL__sl_sounds_csp32_::execute()
{
SequenceL_floatToInt_2(_SequenceL__Arg_B.bxv, _SequenceL_tmp5);	/*newStructs.sl:91: floatToInt(B.bxv)*/
SequenceL_mySign_0(_SequenceL_tmp5, _SequenceL_tmp6);	/*newStructs.sl:91: mySign(floatToInt(B.bxv))*/
_SequenceL_tmp7 = (_SequenceL__Arg_B.bxv - _SequenceL_tmp6);	/*newStructs.sl:91: B.bxv - mySign(floatToInt(B.bxv))*/
_SequenceL__Arg_B._delete_data(true);	
return NULL;
}
task *SequenceL__sl_sounds_slowDowns_0::execute()
{
_SequenceL__Arg_B._Reference();	
_SequenceL__Arg_B._Reference();	
set_ref_count(3);
spawn(*new(allocate_child()) SequenceL__sl_sounds_csp32_(_SequenceL__Arg_B, _SequenceL_tmp7));
spawn_and_wait_for_all(*new(allocate_child()) SequenceL__sl_sounds_csp33_(_SequenceL__Arg_B, _SequenceL_tmp12));
SequenceL_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:91: newBall(B.ballCenter, B.ballRad, B.bxv - mySign(floatToInt(B.bxv)), B.byv - mySign(floatToInt(B.byv)))"), _SequenceL__Arg_B.ballRad, _SequenceL_tmp7, _SequenceL_tmp12, _SequenceL__result);	/*newStructs.sl:91: newBall(B.ballCenter, B.ballRad, B.bxv - mySign(floatToInt(B.bxv)), B.byv - mySign(floatToInt(B.byv)))*/
_SequenceL__Arg_B._delete_data(true);	
return NULL;
}
task *SequenceL__sl_sounds_csp28_::execute()
{
_SequenceL_tmp15 = (_SequenceL__Arg_B.ballCenter.val("newStructs.sl:85: B.ballCenter.y + yBall.byv").y + _SequenceL__Arg_yBall.byv);	/*newStructs.sl:85: B.ballCenter.y + yBall.byv*/
_SequenceL__Arg_B._delete_data(true);	
_SequenceL__Arg_yBall._delete_data(true);	
SequenceL_floatToInt_2(_SequenceL_tmp15, _SequenceL_tmp16);	/*newStructs.sl:85: floatToInt(B.ballCenter.y + yBall.byv)*/
return NULL;
}
task *SequenceL__sl_sounds_csp27_::execute()
{
_SequenceL_tmp10 = (_SequenceL__Arg_B.ballCenter.val("newStructs.sl:85: B.ballCenter.x + yBall.bxv").x + _SequenceL__Arg_yBall.bxv);	/*newStructs.sl:85: B.ballCenter.x + yBall.bxv*/
_SequenceL__Arg_B._delete_data(true);	
_SequenceL__Arg_yBall._delete_data(true);	
SequenceL_floatToInt_2(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:85: floatToInt(B.ballCenter.x + yBall.bxv)*/
return NULL;
}
task *SequenceL__sl_sounds_ballMovess_0::execute()
{
SequenceL_checkHorizontalBoundaries_0(_SequenceL__Arg_B, _SequenceL_tmp3);	/*newStructs.sl:82: checkHorizontalBoundaries(B)*/
if (_SequenceL_tmp3)	/*newStructs.sl:82: xFlip(B) when checkHorizontalBoundaries(B) else B*/
{
SequenceL_xFlip_0(_SequenceL__Arg_B, _SequenceL__Arg_xBall);	/*newStructs.sl:82: xFlip(B)*/
}
else
{
_SequenceL__Arg_xBall = _SequenceL__Arg_B;	
}
SequenceL_checkVerticalBoundaries_0(_SequenceL__Arg_xBall, _SequenceL_tmp6);	/*newStructs.sl:83: checkVerticalBoundaries(xBall)*/
if (_SequenceL_tmp6)	/*newStructs.sl:83: yFlip(xBall) when checkVerticalBoundaries(xBall) else xBall*/
{
SequenceL_yFlip_0(_SequenceL__Arg_xBall, _SequenceL__Arg_yBall);	/*newStructs.sl:83: yFlip(xBall)*/
_SequenceL__Arg_xBall._delete_data(true);	
_SequenceL__Arg_xBall._finished();	
}
else
{
_SequenceL__Arg_yBall = _SequenceL__Arg_xBall;	
_SequenceL__Arg_xBall._delete_data(true);	
_SequenceL__Arg_xBall._finished();	
}
_SequenceL__Arg_B._Reference();	
_SequenceL__Arg_yBall._Reference();	
_SequenceL__Arg_B._Reference();	
_SequenceL__Arg_yBall._Reference();	
set_ref_count(3);
spawn(*new(allocate_child()) SequenceL__sl_sounds_csp27_(_SequenceL__Arg_B, _SequenceL__Arg_yBall, _SequenceL_tmp11));
spawn_and_wait_for_all(*new(allocate_child()) SequenceL__sl_sounds_csp28_(_SequenceL__Arg_B, _SequenceL__Arg_yBall, _SequenceL_tmp16));
SequenceL_newPoint_0(_SequenceL_tmp11, _SequenceL_tmp16, _SequenceL_tmp17);	/*newStructs.sl:85: newPoint(floatToInt(B.ballCenter.x + yBall.bxv), floatToInt(B.ballCenter.y + yBall.byv))*/
SequenceL_newBall_0(_SequenceL_tmp17, _SequenceL__Arg_B.ballRad, _SequenceL__Arg_yBall.bxv, _SequenceL__Arg_yBall.byv, _SequenceL__result);	/*newStructs.sl:85: newBall(newPoint(floatToInt(B.ballCenter.x + yBall.bxv), floatToInt(B.ballCenter.y + yBall.byv)), B.ballRad, yBall.bxv, yBall.byv)*/
_SequenceL_tmp17._delete_data(true);	
_SequenceL__Arg_B._delete_data(true);	
_SequenceL__Arg_yBall._delete_data(true);	
_SequenceL_tmp17._finished();	
_SequenceL__Arg_yBall._finished();	
_SequenceL__Arg_otherBalls.delete_data(true);	
return NULL;
}
void SequenceL__parallel_newColor_0(int _SequenceL__Arg_r, int _SequenceL__Arg_g, int _SequenceL__Arg_b, _sl_Color_0 &_SequenceL__result)
{

_SequenceL__result.red = _SequenceL__Arg_r;	
_SequenceL__result.green = _SequenceL__Arg_g;	
_SequenceL__result.blue = _SequenceL__Arg_b;	
}
void SequenceL__parallel_newGraphic_0(_sl_Point_0 &_SequenceL__Arg_ce, Sequence< char > &_SequenceL__Arg_file, _sl_Image_0 &_SequenceL__result)
{
Sequence< char > _SequenceL_tmp1(cspace);
_sl_Color_0 _SequenceL_tmp2(cspace);
_sl_Point_0 _SequenceL_tmp3(cspace);
_sl_Point_0 _SequenceL_tmp4(cspace);
_sl_Point_0 _SequenceL_tmp5(cspace);

_SequenceL_tmp1.setSize(7);	
_SequenceL_tmp1[1] = 'g';	
_SequenceL_tmp1[2] = 'r';	
_SequenceL_tmp1[3] = 'a';	
_SequenceL_tmp1[4] = 'p';	
_SequenceL_tmp1[5] = 'h';	
_SequenceL_tmp1[6] = 'i';	
_SequenceL_tmp1[7] = 'c';	
_SequenceL__result.kind = _SequenceL_tmp1;	
_SequenceL_tmp1.delete_data(false);	
_SequenceL_tmp1.finished();	
_SequenceL__result.center = _SequenceL__Arg_ce;	
_SequenceL__result.source = _SequenceL__Arg_file;	
_SequenceL_tmp2 = _SequenceL_dViolet_0;	
_SequenceL__result.iColor = _SequenceL_tmp2;	
_SequenceL_tmp2._delete_data(false);	
_SequenceL_tmp2._finished();	
_SequenceL_tmp3 = _SequenceL_originPoint_0;	
_SequenceL__result.vert1 = _SequenceL_tmp3;	
_SequenceL_tmp3._delete_data(false);	
_SequenceL_tmp3._finished();	
_SequenceL_tmp4 = _SequenceL_originPoint_0;	
_SequenceL__result.vert2 = _SequenceL_tmp4;	
_SequenceL_tmp4._delete_data(false);	
_SequenceL_tmp4._finished();	
_SequenceL_tmp5 = _SequenceL_originPoint_0;	
_SequenceL__result.vert3 = _SequenceL_tmp5;	
_SequenceL_tmp5._delete_data(false);	
_SequenceL_tmp5._finished();	
}
void SequenceL__parallel_mySign_0(int _SequenceL__Arg_x, int &_SequenceL__result)
{

if (_SequenceL__Arg_x >= 0)	/*newStructs.sl:87: 1 when x >= 0 else -1*/
{
_SequenceL__result = 1;	
}
else
{
_SequenceL__result = (-1);	/*newStructs.sl:87: -1*/
}
}
void SequenceL__parallel_xFlip_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result)
{
SL_FLOAT _SequenceL__Arg_xV;
SL_FLOAT _SequenceL__Arg_yV;

_SequenceL__Arg_xV = ((-1.0) * _SequenceL__Arg_B.bxv);	/*newStructs.sl:59: -1.0 * B.bxv*/
_SequenceL__Arg_yV = _SequenceL__Arg_B.byv;	/*newStructs.sl:60: B.byv*/
SequenceL__parallel_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:62: newBall(B.ballCenter, B.ballRad, xV, yV)"), _SequenceL__Arg_B.ballRad, _SequenceL__Arg_xV, _SequenceL__Arg_yV, _SequenceL__result);	/*newStructs.sl:62: newBall(B.ballCenter, B.ballRad, xV, yV)*/
}
void SequenceL__parallel_yFlip_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result)
{
SL_FLOAT _SequenceL__Arg_xV;
SL_FLOAT _SequenceL__Arg_yV;

_SequenceL__Arg_xV = _SequenceL__Arg_B.bxv;	/*newStructs.sl:67: B.bxv*/
_SequenceL__Arg_yV = ((-1.0) * _SequenceL__Arg_B.byv);	/*newStructs.sl:66: -1.0 * B.byv*/
SequenceL__parallel_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:69: newBall(B.ballCenter, B.ballRad, xV, yV)"), _SequenceL__Arg_B.ballRad, _SequenceL__Arg_xV, _SequenceL__Arg_yV, _SequenceL__result);	/*newStructs.sl:69: newBall(B.ballCenter, B.ballRad, xV, yV)*/
}
void SequenceL__parallel_floatToInt_2(SL_FLOAT _SequenceL__Arg_float, int &_SequenceL__result)
{
int _SequenceL_tmp4;
SL_FLOAT _SequenceL_tmp3;

if (_SequenceL__Arg_float < 0)	/*Conversion.sl:119: -floatToInt(-float) when float < 0	else		floor(float)*/
{
_SequenceL_tmp3 = (-_SequenceL__Arg_float);	/*Conversion.sl:117: -float*/
SequenceL__parallel_floatToInt_2(_SequenceL_tmp3, _SequenceL_tmp4);	/*Conversion.sl:117: floatToInt(-float)*/
_SequenceL__result = (-_SequenceL_tmp4);	/*Conversion.sl:117: -floatToInt(-float)*/
}
else
{
_SequenceL__result = ((int) floor(_SequenceL__Arg_float));	/*Conversion.sl:119: floor(float)*/
}
}
void SequenceL__parallel_newBall_0(_sl_Point_0 &_SequenceL__Arg_c, int _SequenceL__Arg_r, SL_FLOAT _SequenceL__Arg_x, SL_FLOAT _SequenceL__Arg_y, _sl_Ball_0 &_SequenceL__result)
{

_SequenceL__result.ballCenter = _SequenceL__Arg_c;	
_SequenceL__result.ballRad = _SequenceL__Arg_r;	
_SequenceL__result.bxv = _SequenceL__Arg_x;	
_SequenceL__result.byv = _SequenceL__Arg_y;	
}
void SequenceL__parallel_ballRight_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result)
{

_SequenceL__result = (_SequenceL__Arg_ball.ballCenter.val("newStructs.sl:71: ball.ballCenter.x + ball.ballRad").x + _SequenceL__Arg_ball.ballRad);	/*newStructs.sl:71: ball.ballCenter.x + ball.ballRad*/
}
void SequenceL__parallel_ballLeft_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result)
{

_SequenceL__result = (_SequenceL__Arg_ball.ballCenter.val("newStructs.sl:72: ball.ballCenter.x - ball.ballRad").x - _SequenceL__Arg_ball.ballRad);	/*newStructs.sl:72: ball.ballCenter.x - ball.ballRad*/
}
void SequenceL__parallel_ballTop_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result)
{

_SequenceL__result = (_SequenceL__Arg_ball.ballCenter.val("newStructs.sl:73: ball.ballCenter.y + ball.ballRad").y + _SequenceL__Arg_ball.ballRad);	/*newStructs.sl:73: ball.ballCenter.y + ball.ballRad*/
}
void SequenceL__parallel_ballBottom_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result)
{

_SequenceL__result = (_SequenceL__Arg_ball.ballCenter.val("newStructs.sl:74: ball.ballCenter.y - ball.ballRad").y - _SequenceL__Arg_ball.ballRad);	/*newStructs.sl:74: ball.ballCenter.y - ball.ballRad*/
}
void SequenceL__parallel_newPoint_0(int _SequenceL__Arg_a, int _SequenceL__Arg_b, _sl_Point_0 &_SequenceL__result)
{

_SequenceL__result.x = _SequenceL__Arg_a;	
_SequenceL__result.y = _SequenceL__Arg_b;	
}
void SequenceL__parallel_newDisc_0(_sl_Point_0 &_SequenceL__Arg_ce, int _SequenceL__Arg_rad, _sl_Color_0 &_SequenceL__Arg_c, _sl_Image_0 &_SequenceL__result)
{
Sequence< char > _SequenceL_tmp1(cspace);
_sl_Point_0 _SequenceL_tmp2(cspace);
_sl_Point_0 _SequenceL_tmp3(cspace);
_sl_Point_0 _SequenceL_tmp4(cspace);

_SequenceL_tmp1.setSize(4);	
_SequenceL_tmp1[1] = 'd';	
_SequenceL_tmp1[2] = 'i';	
_SequenceL_tmp1[3] = 's';	
_SequenceL_tmp1[4] = 'c';	
_SequenceL__result.kind = _SequenceL_tmp1;	
_SequenceL_tmp1.delete_data(false);	
_SequenceL_tmp1.finished();	
_SequenceL__result.center = _SequenceL__Arg_ce;	
_SequenceL__result.radius = _SequenceL__Arg_rad;	
_SequenceL__result.iColor = _SequenceL__Arg_c;	
_SequenceL_tmp2 = _SequenceL_originPoint_0;	
_SequenceL__result.vert1 = _SequenceL_tmp2;	
_SequenceL_tmp2._delete_data(false);	
_SequenceL_tmp2._finished();	
_SequenceL_tmp3 = _SequenceL_originPoint_0;	
_SequenceL__result.vert2 = _SequenceL_tmp3;	
_SequenceL_tmp3._delete_data(false);	
_SequenceL_tmp3._finished();	
_SequenceL_tmp4 = _SequenceL_originPoint_0;	
_SequenceL__result.vert3 = _SequenceL_tmp4;	
_SequenceL_tmp4._delete_data(false);	
_SequenceL_tmp4._finished();	
}
void SequenceL__parallel_ballImg_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Image_0 &_SequenceL__result)
{
Sequence< char > _SequenceL_tmp2(cspace);

_SequenceL_tmp2.setSize(12);	
_SequenceL_tmp2[1] = 'T';	
_SequenceL_tmp2[2] = 'e';	
_SequenceL_tmp2[3] = 's';	
_SequenceL_tmp2[4] = 't';	
_SequenceL_tmp2[5] = 'B';	
_SequenceL_tmp2[6] = 'a';	
_SequenceL_tmp2[7] = 'l';	
_SequenceL_tmp2[8] = 'l';	
_SequenceL_tmp2[9] = '.';	
_SequenceL_tmp2[10] = 'j';	
_SequenceL_tmp2[11] = 'p';	
_SequenceL_tmp2[12] = 'g';	
SequenceL__parallel_newGraphic_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:93: newGraphic(B.ballCenter, \"TestBall.jpg\")"), _SequenceL_tmp2, _SequenceL__result);	/*newStructs.sl:93: newGraphic(B.ballCenter, "TestBall.jpg")*/
_SequenceL_tmp2.delete_data(false);	
_SequenceL_tmp2.finished();	
}
void SequenceL__parallel_speedUp_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result)
{
SL_FLOAT _SequenceL_tmp7;
int _SequenceL_tmp6;
int _SequenceL_tmp5;
SL_FLOAT _SequenceL_tmp12;
int _SequenceL_tmp11;
int _SequenceL_tmp10;

SequenceL__parallel_floatToInt_2(_SequenceL__Arg_B.bxv, _SequenceL_tmp5);	/*newStructs.sl:89: floatToInt(B.bxv)*/
SequenceL__parallel_mySign_0(_SequenceL_tmp5, _SequenceL_tmp6);	/*newStructs.sl:89: mySign(floatToInt(B.bxv))*/
_SequenceL_tmp7 = (_SequenceL__Arg_B.bxv + _SequenceL_tmp6);	/*newStructs.sl:89: B.bxv + mySign(floatToInt(B.bxv))*/
SequenceL__parallel_floatToInt_2(_SequenceL__Arg_B.byv, _SequenceL_tmp10);	/*newStructs.sl:89: floatToInt(B.byv)*/
SequenceL__parallel_mySign_0(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:89: mySign(floatToInt(B.byv))*/
_SequenceL_tmp12 = (_SequenceL__Arg_B.byv + _SequenceL_tmp11);	/*newStructs.sl:89: B.byv + mySign(floatToInt(B.byv))*/
SequenceL__parallel_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:89: newBall(B.ballCenter, B.ballRad, B.bxv + mySign(floatToInt(B.bxv)), B.byv + mySign(floatToInt(B.byv)))"), _SequenceL__Arg_B.ballRad, _SequenceL_tmp7, _SequenceL_tmp12, _SequenceL__result);	/*newStructs.sl:89: newBall(B.ballCenter, B.ballRad, B.bxv + mySign(floatToInt(B.bxv)), B.byv + mySign(floatToInt(B.byv)))*/
}
void SequenceL__parallel_slowDown_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result)
{
SL_FLOAT _SequenceL_tmp7;
int _SequenceL_tmp6;
int _SequenceL_tmp5;
SL_FLOAT _SequenceL_tmp12;
int _SequenceL_tmp11;
int _SequenceL_tmp10;

SequenceL__parallel_floatToInt_2(_SequenceL__Arg_B.bxv, _SequenceL_tmp5);	/*newStructs.sl:91: floatToInt(B.bxv)*/
SequenceL__parallel_mySign_0(_SequenceL_tmp5, _SequenceL_tmp6);	/*newStructs.sl:91: mySign(floatToInt(B.bxv))*/
_SequenceL_tmp7 = (_SequenceL__Arg_B.bxv - _SequenceL_tmp6);	/*newStructs.sl:91: B.bxv - mySign(floatToInt(B.bxv))*/
SequenceL__parallel_floatToInt_2(_SequenceL__Arg_B.byv, _SequenceL_tmp10);	/*newStructs.sl:91: floatToInt(B.byv)*/
SequenceL__parallel_mySign_0(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:91: mySign(floatToInt(B.byv))*/
_SequenceL_tmp12 = (_SequenceL__Arg_B.byv - _SequenceL_tmp11);	/*newStructs.sl:91: B.byv - mySign(floatToInt(B.byv))*/
SequenceL__parallel_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:91: newBall(B.ballCenter, B.ballRad, B.bxv - mySign(floatToInt(B.bxv)), B.byv - mySign(floatToInt(B.byv)))"), _SequenceL__Arg_B.ballRad, _SequenceL_tmp7, _SequenceL_tmp12, _SequenceL__result);	/*newStructs.sl:91: newBall(B.ballCenter, B.ballRad, B.bxv - mySign(floatToInt(B.bxv)), B.byv - mySign(floatToInt(B.byv)))*/
}
void SequenceL__parallel_drop_1(Sequence< _sl_Ball_0 > &_SequenceL__Arg_list, int _SequenceL__Arg_n, Sequence< _sl_Ball_0 > &_SequenceL__result)
{

_SequenceL__Arg_list.sub_seq((_SequenceL__Arg_n + 1), _SequenceL__Arg_list.size(), _SequenceL__result);	/*Sequence.sl:142: list[(n + 1) ... size(list)]*/
}
void SequenceL__parallel_ballMove_0(_sl_Ball_0 &_SequenceL__Arg_B, Sequence< _sl_Ball_0 > &_SequenceL__Arg_otherBalls, _sl_Ball_0 &_SequenceL__result)
{
_sl_Point_0 _SequenceL_tmp17(cspace);
int _SequenceL_tmp11;
SL_FLOAT _SequenceL_tmp10;
_sl_Ball_0 _SequenceL__Arg_yBall(cspace);
bool _SequenceL_tmp6;
_sl_Ball_0 _SequenceL__Arg_xBall(cspace);
bool _SequenceL_tmp3;
int _SequenceL_tmp16;
SL_FLOAT _SequenceL_tmp15;

SequenceL__parallel_checkHorizontalBoundaries_0(_SequenceL__Arg_B, _SequenceL_tmp3);	/*newStructs.sl:82: checkHorizontalBoundaries(B)*/
if (_SequenceL_tmp3)	/*newStructs.sl:82: xFlip(B) when checkHorizontalBoundaries(B) else B*/
{
SequenceL__parallel_xFlip_0(_SequenceL__Arg_B, _SequenceL__Arg_xBall);	/*newStructs.sl:82: xFlip(B)*/
}
else
{
_SequenceL__Arg_xBall = _SequenceL__Arg_B;	
}
SequenceL__parallel_checkVerticalBoundaries_0(_SequenceL__Arg_xBall, _SequenceL_tmp6);	/*newStructs.sl:83: checkVerticalBoundaries(xBall)*/
if (_SequenceL_tmp6)	/*newStructs.sl:83: yFlip(xBall) when checkVerticalBoundaries(xBall) else xBall*/
{
SequenceL__parallel_yFlip_0(_SequenceL__Arg_xBall, _SequenceL__Arg_yBall);	/*newStructs.sl:83: yFlip(xBall)*/
_SequenceL__Arg_xBall._delete_data(false);	
_SequenceL__Arg_xBall._finished();	
}
else
{
_SequenceL__Arg_yBall = _SequenceL__Arg_xBall;	
_SequenceL__Arg_xBall._delete_data(false);	
_SequenceL__Arg_xBall._finished();	
}
_SequenceL_tmp10 = (_SequenceL__Arg_B.ballCenter.val("newStructs.sl:85: B.ballCenter.x + yBall.bxv").x + _SequenceL__Arg_yBall.bxv);	/*newStructs.sl:85: B.ballCenter.x + yBall.bxv*/
SequenceL__parallel_floatToInt_2(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:85: floatToInt(B.ballCenter.x + yBall.bxv)*/
_SequenceL_tmp15 = (_SequenceL__Arg_B.ballCenter.val("newStructs.sl:85: B.ballCenter.y + yBall.byv").y + _SequenceL__Arg_yBall.byv);	/*newStructs.sl:85: B.ballCenter.y + yBall.byv*/
SequenceL__parallel_floatToInt_2(_SequenceL_tmp15, _SequenceL_tmp16);	/*newStructs.sl:85: floatToInt(B.ballCenter.y + yBall.byv)*/
SequenceL__parallel_newPoint_0(_SequenceL_tmp11, _SequenceL_tmp16, _SequenceL_tmp17);	/*newStructs.sl:85: newPoint(floatToInt(B.ballCenter.x + yBall.bxv), floatToInt(B.ballCenter.y + yBall.byv))*/
SequenceL__parallel_newBall_0(_SequenceL_tmp17, _SequenceL__Arg_B.ballRad, _SequenceL__Arg_yBall.bxv, _SequenceL__Arg_yBall.byv, _SequenceL__result);	/*newStructs.sl:85: newBall(newPoint(floatToInt(B.ballCenter.x + yBall.bxv), floatToInt(B.ballCenter.y + yBall.byv)), B.ballRad, yBall.bxv, yBall.byv)*/
_SequenceL_tmp17._delete_data(false);	
_SequenceL__Arg_yBall._delete_data(false);	
_SequenceL_tmp17._finished();	
_SequenceL__Arg_yBall._finished();	
}
void SequenceL__parallel_buildState_0(Sequence< _sl_Ball_0 > &_SequenceL__Arg_ba, _sl_State_0 &_SequenceL__result)
{

_SequenceL__result.balls = _SequenceL__Arg_ba;	
}
void SequenceL__parallel_checkHorizontalBoundaries_0(_sl_Ball_0 &_SequenceL__Arg_ball, bool &_SequenceL__result)
{
int _SequenceL_tmp1;
int _SequenceL_tmp3;

SequenceL__parallel_ballRight_0(_SequenceL__Arg_ball, _SequenceL_tmp1);	/*newStructs.sl:78: ballRight(ball)*/
SequenceL__parallel_ballLeft_0(_SequenceL__Arg_ball, _SequenceL_tmp3);	/*newStructs.sl:78: ballLeft(ball)*/
_SequenceL__result = ((_SequenceL_tmp1 >= 1000) || (_SequenceL_tmp3 <= 0));	/*newStructs.sl:78: ballRight(ball) >= 1000 or ballLeft(ball) <= 0*/
}
void SequenceL__parallel_checkVerticalBoundaries_0(_sl_Ball_0 &_SequenceL__Arg_ball, bool &_SequenceL__result)
{
int _SequenceL_tmp1;
int _SequenceL_tmp3;

SequenceL__parallel_ballTop_0(_SequenceL__Arg_ball, _SequenceL_tmp1);	/*newStructs.sl:76: ballTop(ball)*/
SequenceL__parallel_ballBottom_0(_SequenceL__Arg_ball, _SequenceL_tmp3);	/*newStructs.sl:76: ballBottom(ball)*/
_SequenceL__result = ((_SequenceL_tmp1 >= 800) || (_SequenceL_tmp3 <= 0));	/*newStructs.sl:76: ballTop(ball) >= 800 or ballBottom(ball) <= 0*/
}
void SequenceL__sl_sounds_nt25_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i7 = _r.begin(); _SequenceL__i7 < _e; _SequenceL__i7++)
{

SequenceL_ballImg_0(_SequenceL__Arg_S.balls[_SequenceL__i7], _SequenceL__result26[_SequenceL__i7]);	/*newStructs.sl:109: ballImg(S.balls)*/
}
}
void SequenceL__parallel_images_0(_sl_State_0 &_SequenceL__Arg_S, Sequence< _sl_Image_0 > &_SequenceL__result)
{
Sequence< _sl_Image_0 > _SequenceL_tmp1(cspace);
_sl_Image_0 _SequenceL_tmp4(cspace);
_sl_Point_0 _SequenceL_tmp2(cspace);
_sl_Color_0 _SequenceL_tmp3(cspace);
Sequence< _sl_Image_0 > _SequenceL_tmp6(cspace);

_SequenceL_tmp1.setSize(1);	
SequenceL__parallel_newPoint_0(500, 400, _SequenceL_tmp2);	/*newStructs.sl:109: newPoint(500, 400)*/
_SequenceL_tmp3 = _SequenceL_dBlack_0;	
SequenceL__parallel_newDisc_0(_SequenceL_tmp2, 641, _SequenceL_tmp3, _SequenceL_tmp4);	/*newStructs.sl:109: newDisc(newPoint(500, 400), 641, dBlack)*/
_SequenceL_tmp2._delete_data(false);	
_SequenceL_tmp3._delete_data(false);	
_SequenceL_tmp2._finished();	
_SequenceL_tmp3._finished();	
_SequenceL_tmp1[1] = _SequenceL_tmp4;	
_SequenceL_tmp4._delete_data(false);	
_SequenceL_tmp4._finished();	
_SequenceL_tmp6.setSize(_SequenceL__Arg_S.balls.size());	
SequenceL__sl_sounds_nt25_ SequenceL__sl_sounds_nt25__val(_SequenceL__Arg_S, _SequenceL_tmp6);
sl_redistribute_mem();
sl_add_new_nt(1, _SequenceL_tmp6.size()+1, SequenceL__sl_sounds_nt25__val);
append(_SequenceL_tmp1, _SequenceL_tmp6, _SequenceL__result);	/*newStructs.sl:109: [newDisc(newPoint(500, 400), 641, dBlack)] ++ ballImg(S.balls)*/
_SequenceL_tmp1.delete_data(false);	
_SequenceL_tmp6.delete_data(false);	
_SequenceL_tmp1.finished();	
_SequenceL_tmp6.finished();	
}
void SequenceL__sl_sounds_nt9_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__scope__Index_newPos_i = _r.begin(); _SequenceL__scope__Index_newPos_i < _e; _SequenceL__scope__Index_newPos_i++)
{
Sequence< _sl_Ball_0 > _SequenceL_tmp15(cspace);

SequenceL_drop_1(_SequenceL__Arg_S.balls, _SequenceL__scope__Index_newPos_i, _SequenceL_tmp15);	/*newStructs.sl:99: drop(S.balls, i)*/
SequenceL_ballMove_0(_SequenceL__Arg_S.balls[_SequenceL__scope__Index_newPos_i], _SequenceL_tmp15, _SequenceL__result10[_SequenceL__scope__Index_newPos_i]);	/*newStructs.sl:99: ballMove(S.balls[i], drop(S.balls, i))*/
}
}
void SequenceL__sl_sounds_nt11_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i17 = _r.begin(); _SequenceL__i17 < _e; _SequenceL__i17++)
{

SequenceL_speedUp_0(_SequenceL__Arg_newPos[_SequenceL__i17], _SequenceL__result12[_SequenceL__i17]);	/*newStructs.sl:103: speedUp(newPos)*/
}
}
void SequenceL__sl_sounds_nt13_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__scope__Index_newPos_i = _r.begin(); _SequenceL__scope__Index_newPos_i < _e; _SequenceL__scope__Index_newPos_i++)
{
Sequence< _sl_Ball_0 > _SequenceL_tmp27(cspace);

SequenceL_drop_1(_SequenceL__Arg_S.balls, _SequenceL__scope__Index_newPos_i, _SequenceL_tmp27);	/*newStructs.sl:99: drop(S.balls, i)*/
SequenceL_ballMove_0(_SequenceL__Arg_S.balls[_SequenceL__scope__Index_newPos_i], _SequenceL_tmp27, _SequenceL__result14[_SequenceL__scope__Index_newPos_i]);	/*newStructs.sl:99: ballMove(S.balls[i], drop(S.balls, i))*/
}
}
void SequenceL__sl_sounds_nt15_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i29 = _r.begin(); _SequenceL__i29 < _e; _SequenceL__i29++)
{

SequenceL_slowDown_0(_SequenceL__Arg_newPos[_SequenceL__i29], _SequenceL__result16[_SequenceL__i29]);	/*newStructs.sl:105: slowDown(newPos)*/
}
}
void SequenceL__sl_sounds_nt17_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__scope__Index_newPos_i = _r.begin(); _SequenceL__scope__Index_newPos_i < _e; _SequenceL__scope__Index_newPos_i++)
{
Sequence< _sl_Ball_0 > _SequenceL_tmp34(cspace);

SequenceL_drop_1(_SequenceL__Arg_S.balls, _SequenceL__scope__Index_newPos_i, _SequenceL_tmp34);	/*newStructs.sl:99: drop(S.balls, i)*/
SequenceL_ballMove_0(_SequenceL__Arg_S.balls[_SequenceL__scope__Index_newPos_i], _SequenceL_tmp34, _SequenceL__result18[_SequenceL__scope__Index_newPos_i]);	/*newStructs.sl:99: ballMove(S.balls[i], drop(S.balls, i))*/
}
}
void SequenceL__sl_sounds_nt19_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i21 = _r.begin(); _SequenceL__i21 < _e; _SequenceL__i21++)
{
int _SequenceL__no_share_pos;
int _SequenceL__no_share_start;
int _SequenceL__no_share_stop;

_SequenceL__no_share_pos = (((_SequenceL__stop - _SequenceL__start) / (sl_get_num_units() * WORK_SHARE_VALUE)) + 1);	
_SequenceL__no_share_start = (((_SequenceL__i21 - 1) * _SequenceL__no_share_pos) + _SequenceL__start);	
_SequenceL__no_share_stop = SequenceL_min(((_SequenceL__i21 * _SequenceL__no_share_pos) + (_SequenceL__start - 1)), _SequenceL__stop);	
for (int _SequenceL__no_share_iter=_SequenceL__no_share_start; _SequenceL__no_share_iter<=_SequenceL__no_share_stop; _SequenceL__no_share_iter+=1)
{
_SequenceL__result20[_SequenceL__no_share_iter] = (_SequenceL__Arg_I.keys[_SequenceL__no_share_iter] == 'S');	/*newStructs.sl:105: I.keys = 'S'*/
}
}
}
void SequenceL__sl_sounds_nt21_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i9 = _r.begin(); _SequenceL__i9 < _e; _SequenceL__i9++)
{
int _SequenceL__no_share_pos;
int _SequenceL__no_share_start;
int _SequenceL__no_share_stop;

_SequenceL__no_share_pos = (((_SequenceL__stop - _SequenceL__start) / (sl_get_num_units() * WORK_SHARE_VALUE)) + 1);	
_SequenceL__no_share_start = (((_SequenceL__i9 - 1) * _SequenceL__no_share_pos) + _SequenceL__start);	
_SequenceL__no_share_stop = SequenceL_min(((_SequenceL__i9 * _SequenceL__no_share_pos) + (_SequenceL__start - 1)), _SequenceL__stop);	
for (int _SequenceL__no_share_iter=_SequenceL__no_share_start; _SequenceL__no_share_iter<=_SequenceL__no_share_stop; _SequenceL__no_share_iter+=1)
{
_SequenceL__result22[_SequenceL__no_share_iter] = (_SequenceL__Arg_I.keys[_SequenceL__no_share_iter] == 'W');	/*newStructs.sl:103: I.keys = 'W'*/
}
}
}
void SequenceL__sl_sounds_nt23_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i3 = _r.begin(); _SequenceL__i3 < _e; _SequenceL__i3++)
{
int _SequenceL__no_share_pos;
int _SequenceL__no_share_start;
int _SequenceL__no_share_stop;

_SequenceL__no_share_pos = (((_SequenceL__stop - _SequenceL__start) / (sl_get_num_units() * WORK_SHARE_VALUE)) + 1);	
_SequenceL__no_share_start = (((_SequenceL__i3 - 1) * _SequenceL__no_share_pos) + _SequenceL__start);	
_SequenceL__no_share_stop = SequenceL_min(((_SequenceL__i3 * _SequenceL__no_share_pos) + (_SequenceL__start - 1)), _SequenceL__stop);	
for (int _SequenceL__no_share_iter=_SequenceL__no_share_start; _SequenceL__no_share_iter<=_SequenceL__no_share_stop; _SequenceL__no_share_iter+=1)
{
_SequenceL__result24[_SequenceL__no_share_iter] = (_SequenceL__Arg_I.keys[_SequenceL__no_share_iter] == 'P');	/*newStructs.sl:101: I.keys = 'P'*/
}
}
}
void SequenceL__parallel_newState_0(_sl_Input_0 &_SequenceL__Arg_I, _sl_State_0 &_SequenceL__Arg_S, _sl_State_0 &_SequenceL__result)
{
bool _SequenceL_tmp4;
Sequence< bool > _SequenceL_tmp2(cspace);
bool _SequenceL_tmp10;
Sequence< bool > _SequenceL_tmp8(cspace);
Sequence< _sl_Ball_0 > _SequenceL__Arg_newPos(cspace);
Sequence< _sl_Ball_0 > _SequenceL_tmp16(cspace);
bool _SequenceL_tmp22;
Sequence< bool > _SequenceL_tmp20(cspace);
Sequence< _sl_Ball_0 > _SequenceL_tmp28(cspace);

_SequenceL_tmp2.setSize(_SequenceL__Arg_I.keys.size());	
if ((_SequenceL_tmp2.size() - 1) > (sl_get_num_units() * (WORK_SHARE_VALUE * MIN_PARALLEL_ITEMS)))	
{
SequenceL__sl_sounds_nt23_ SequenceL__sl_sounds_nt23__val(_SequenceL__Arg_I, 1, _SequenceL_tmp2.size(), _SequenceL_tmp2);
sl_redistribute_mem();
sl_add_new_nt(1, (sl_get_num_units() * WORK_SHARE_VALUE)+1, SequenceL__sl_sounds_nt23__val);
}
else
{
for (int _SequenceL__i3=1; _SequenceL__i3<=_SequenceL_tmp2.size(); _SequenceL__i3+=1)
{
_SequenceL_tmp2[_SequenceL__i3] = (_SequenceL__Arg_I.keys[_SequenceL__i3] == 'P');	/*newStructs.sl:101: I.keys = 'P'*/
}
}
_SequenceL_tmp4 = some(_SequenceL_tmp2);	/*newStructs.sl:102: some(I.keys = 'P')*/
_SequenceL_tmp2.delete_data(false);	
_SequenceL_tmp2.finished();	
if (_SequenceL_tmp4)	/*newStructs.sl:107: S when some(I.keys = 'P')	else		buildState(speedUp(newPos)) when some(I.keys = 'W')	else		buildState(slowDown(newPos)) when some(I.keys = 'S')	else		buildState(newPos)*/
{
_SequenceL__result = _SequenceL__Arg_S;	
_SequenceL__Arg_newPos.delete_data(false);	
_SequenceL_tmp16.delete_data(false);	
_SequenceL_tmp28.delete_data(false);	
_SequenceL__Arg_newPos.finished();	
_SequenceL_tmp16.finished();	
_SequenceL_tmp28.finished();	
}
else
{
_SequenceL_tmp8.setSize(_SequenceL__Arg_I.keys.size());	
if ((_SequenceL_tmp8.size() - 1) > (sl_get_num_units() * (WORK_SHARE_VALUE * MIN_PARALLEL_ITEMS)))	
{
SequenceL__sl_sounds_nt21_ SequenceL__sl_sounds_nt21__val(_SequenceL__Arg_I, 1, _SequenceL_tmp8.size(), _SequenceL_tmp8);
sl_redistribute_mem();
sl_add_new_nt(1, (sl_get_num_units() * WORK_SHARE_VALUE)+1, SequenceL__sl_sounds_nt21__val);
}
else
{
for (int _SequenceL__i9=1; _SequenceL__i9<=_SequenceL_tmp8.size(); _SequenceL__i9+=1)
{
_SequenceL_tmp8[_SequenceL__i9] = (_SequenceL__Arg_I.keys[_SequenceL__i9] == 'W');	/*newStructs.sl:103: I.keys = 'W'*/
}
}
_SequenceL_tmp10 = some(_SequenceL_tmp8);	/*newStructs.sl:104: some(I.keys = 'W')*/
_SequenceL_tmp8.delete_data(false);	
_SequenceL_tmp8.finished();	
if (_SequenceL_tmp10)	/*newStructs.sl:107: buildState(speedUp(newPos)) when some(I.keys = 'W')	else		buildState(slowDown(newPos)) when some(I.keys = 'S')	else		buildState(newPos)*/
{
_SequenceL__Arg_newPos.setSize(_SequenceL__Arg_S.balls.size());	
SequenceL__sl_sounds_nt9_ SequenceL__sl_sounds_nt9__val(_SequenceL__Arg_S, _SequenceL__Arg_newPos);
sl_redistribute_mem();
sl_add_new_nt(1, _SequenceL__Arg_newPos.size()+1, SequenceL__sl_sounds_nt9__val);
_SequenceL_tmp16.setSize(_SequenceL__Arg_newPos.size());	
SequenceL__sl_sounds_nt11_ SequenceL__sl_sounds_nt11__val(_SequenceL__Arg_newPos, _SequenceL_tmp16);
sl_redistribute_mem();
sl_add_new_nt(1, _SequenceL_tmp16.size()+1, SequenceL__sl_sounds_nt11__val);
_SequenceL__Arg_newPos.delete_data(false);	
_SequenceL__Arg_newPos.finished();	
SequenceL__parallel_buildState_0(_SequenceL_tmp16, _SequenceL__result);	/*newStructs.sl:103: buildState(speedUp(newPos))*/
_SequenceL_tmp16.delete_data(false);	
_SequenceL_tmp16.finished();	
_SequenceL_tmp28.delete_data(false);	
_SequenceL_tmp28.finished();	
}
else
{
_SequenceL_tmp20.setSize(_SequenceL__Arg_I.keys.size());	
if ((_SequenceL_tmp20.size() - 1) > (sl_get_num_units() * (WORK_SHARE_VALUE * MIN_PARALLEL_ITEMS)))	
{
SequenceL__sl_sounds_nt19_ SequenceL__sl_sounds_nt19__val(_SequenceL__Arg_I, 1, _SequenceL_tmp20.size(), _SequenceL_tmp20);
sl_redistribute_mem();
sl_add_new_nt(1, (sl_get_num_units() * WORK_SHARE_VALUE)+1, SequenceL__sl_sounds_nt19__val);
}
else
{
for (int _SequenceL__i21=1; _SequenceL__i21<=_SequenceL_tmp20.size(); _SequenceL__i21+=1)
{
_SequenceL_tmp20[_SequenceL__i21] = (_SequenceL__Arg_I.keys[_SequenceL__i21] == 'S');	/*newStructs.sl:105: I.keys = 'S'*/
}
}
_SequenceL_tmp22 = some(_SequenceL_tmp20);	/*newStructs.sl:106: some(I.keys = 'S')*/
_SequenceL_tmp20.delete_data(false);	
_SequenceL_tmp20.finished();	
if (_SequenceL_tmp22)	/*newStructs.sl:107: buildState(slowDown(newPos)) when some(I.keys = 'S')	else		buildState(newPos)*/
{
_SequenceL__Arg_newPos.setSize(_SequenceL__Arg_S.balls.size());	
SequenceL__sl_sounds_nt13_ SequenceL__sl_sounds_nt13__val(_SequenceL__Arg_S, _SequenceL__Arg_newPos);
sl_redistribute_mem();
sl_add_new_nt(1, _SequenceL__Arg_newPos.size()+1, SequenceL__sl_sounds_nt13__val);
_SequenceL_tmp28.setSize(_SequenceL__Arg_newPos.size());	
SequenceL__sl_sounds_nt15_ SequenceL__sl_sounds_nt15__val(_SequenceL__Arg_newPos, _SequenceL_tmp28);
sl_redistribute_mem();
sl_add_new_nt(1, _SequenceL_tmp28.size()+1, SequenceL__sl_sounds_nt15__val);
_SequenceL__Arg_newPos.delete_data(false);	
_SequenceL__Arg_newPos.finished();	
SequenceL__parallel_buildState_0(_SequenceL_tmp28, _SequenceL__result);	/*newStructs.sl:105: buildState(slowDown(newPos))*/
_SequenceL_tmp28.delete_data(false);	
_SequenceL_tmp28.finished();	
}
else
{
_SequenceL__Arg_newPos.setSize(_SequenceL__Arg_S.balls.size());	
SequenceL__sl_sounds_nt17_ SequenceL__sl_sounds_nt17__val(_SequenceL__Arg_S, _SequenceL__Arg_newPos);
sl_redistribute_mem();
sl_add_new_nt(1, _SequenceL__Arg_newPos.size()+1, SequenceL__sl_sounds_nt17__val);
SequenceL__parallel_buildState_0(_SequenceL__Arg_newPos, _SequenceL__result);	/*newStructs.sl:107: buildState(newPos)*/
_SequenceL__Arg_newPos.delete_data(false);	
_SequenceL__Arg_newPos.finished();	
_SequenceL_tmp28.delete_data(false);	
_SequenceL_tmp28.finished();	
}
_SequenceL_tmp16.delete_data(false);	
_SequenceL_tmp16.finished();	
}
}
}
void SequenceL__sl_sounds_nt1_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i9 = _r.begin(); _SequenceL__i9 < _e; _SequenceL__i9++)
{
int _SequenceL__no_share_pos;
int _SequenceL__no_share_start;
int _SequenceL__no_share_stop;

_SequenceL__no_share_pos = (((_SequenceL__stop - _SequenceL__start) / (sl_get_num_units() * WORK_SHARE_VALUE)) + 1);	
_SequenceL__no_share_start = (((_SequenceL__i9 - 1) * _SequenceL__no_share_pos) + _SequenceL__start);	
_SequenceL__no_share_stop = SequenceL_min(((_SequenceL__i9 * _SequenceL__no_share_pos) + (_SequenceL__start - 1)), _SequenceL__stop);	
for (int _SequenceL__no_share_iter=_SequenceL__no_share_start; _SequenceL__no_share_iter<=_SequenceL__no_share_stop; _SequenceL__no_share_iter+=1)
{
SequenceL_checkHorizontalBoundaries_0(_SequenceL__Arg_S.balls[_SequenceL__no_share_iter], _SequenceL__result2[_SequenceL__no_share_iter]);	/*newStructs.sl:114: checkHorizontalBoundaries(S.balls)*/
}
}
}
void SequenceL__sl_sounds_nt3_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i12 = _r.begin(); _SequenceL__i12 < _e; _SequenceL__i12++)
{
int _SequenceL__no_share_pos;
int _SequenceL__no_share_start;
int _SequenceL__no_share_stop;

_SequenceL__no_share_pos = (((_SequenceL__stop - _SequenceL__start) / (sl_get_num_units() * WORK_SHARE_VALUE)) + 1);	
_SequenceL__no_share_start = (((_SequenceL__i12 - 1) * _SequenceL__no_share_pos) + _SequenceL__start);	
_SequenceL__no_share_stop = SequenceL_min(((_SequenceL__i12 * _SequenceL__no_share_pos) + (_SequenceL__start - 1)), _SequenceL__stop);	
for (int _SequenceL__no_share_iter=_SequenceL__no_share_start; _SequenceL__no_share_iter<=_SequenceL__no_share_stop; _SequenceL__no_share_iter+=1)
{
SequenceL_checkVerticalBoundaries_0(_SequenceL__Arg_S.balls[_SequenceL__no_share_iter], _SequenceL__result4[_SequenceL__no_share_iter]);	/*newStructs.sl:114: checkVerticalBoundaries(S.balls)*/
}
}
}
void SequenceL__sl_sounds_nt5_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i14 = _r.begin(); _SequenceL__i14 < _e; _SequenceL__i14++)
{
int _SequenceL__no_share_pos;
int _SequenceL__no_share_start;
int _SequenceL__no_share_stop;

_SequenceL__no_share_pos = (((_SequenceL__stop - _SequenceL__start) / (sl_get_num_units() * WORK_SHARE_VALUE)) + 1);	
_SequenceL__no_share_start = (((_SequenceL__i14 - 1) * _SequenceL__no_share_pos) + _SequenceL__start);	
_SequenceL__no_share_stop = SequenceL_min(((_SequenceL__i14 * _SequenceL__no_share_pos) + (_SequenceL__start - 1)), _SequenceL__stop);	
for (int _SequenceL__no_share_iter=_SequenceL__no_share_start; _SequenceL__no_share_iter<=_SequenceL__no_share_stop; _SequenceL__no_share_iter+=1)
{
_SequenceL__result6[_SequenceL__no_share_iter] = (_SequenceL_tmp8[_SequenceL__no_share_iter] || _SequenceL_tmp11[_SequenceL__no_share_iter]);	/*newStructs.sl:114: checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls)*/
}
}
}
void SequenceL__sl_sounds_nt7_::operator() (const blocked_range<int>& _r) const {
  int _e = _r.end();
  for(int _SequenceL__i3 = _r.begin(); _SequenceL__i3 < _e; _SequenceL__i3++)
{
int _SequenceL__no_share_pos;
int _SequenceL__no_share_start;
int _SequenceL__no_share_stop;

_SequenceL__no_share_pos = (((_SequenceL__stop - _SequenceL__start) / (sl_get_num_units() * WORK_SHARE_VALUE)) + 1);	
_SequenceL__no_share_start = (((_SequenceL__i3 - 1) * _SequenceL__no_share_pos) + _SequenceL__start);	
_SequenceL__no_share_stop = SequenceL_min(((_SequenceL__i3 * _SequenceL__no_share_pos) + (_SequenceL__start - 1)), _SequenceL__stop);	
for (int _SequenceL__no_share_iter=_SequenceL__no_share_start; _SequenceL__no_share_iter<=_SequenceL__no_share_stop; _SequenceL__no_share_iter+=1)
{
_SequenceL__result8[_SequenceL__no_share_iter] = (_SequenceL__Arg_I.keys[_SequenceL__no_share_iter] == 'P');	/*newStructs.sl:112: I.keys = 'P'*/
}
}
}
void SequenceL__parallel_sounds_0(_sl_Input_0 &_SequenceL__Arg_I, _sl_State_0 &_SequenceL__Arg_S, Sequence< Sequence< char > > &_SequenceL__result)
{
bool _SequenceL_tmp4;
Sequence< bool > _SequenceL_tmp2(cspace);
Sequence< Empty > _SequenceL_tmp5(cspace);
bool _SequenceL_tmp15;
Sequence< bool > _SequenceL_tmp8(cspace);
Sequence< bool > _SequenceL_tmp11(cspace);
Sequence< bool > _SequenceL_tmp13(cspace);
Sequence< char > _SequenceL_tmp17(cspace);
Sequence< Empty > _SequenceL_tmp18(cspace);

_SequenceL_tmp2.setSize(_SequenceL__Arg_I.keys.size());	
if ((_SequenceL_tmp2.size() - 1) > (sl_get_num_units() * (WORK_SHARE_VALUE * MIN_PARALLEL_ITEMS)))	
{
SequenceL__sl_sounds_nt7_ SequenceL__sl_sounds_nt7__val(_SequenceL__Arg_I, 1, _SequenceL_tmp2.size(), _SequenceL_tmp2);
sl_redistribute_mem();
sl_add_new_nt(1, (sl_get_num_units() * WORK_SHARE_VALUE)+1, SequenceL__sl_sounds_nt7__val);
}
else
{
for (int _SequenceL__i3=1; _SequenceL__i3<=_SequenceL_tmp2.size(); _SequenceL__i3+=1)
{
_SequenceL_tmp2[_SequenceL__i3] = (_SequenceL__Arg_I.keys[_SequenceL__i3] == 'P');	/*newStructs.sl:112: I.keys = 'P'*/
}
}
_SequenceL_tmp4 = some(_SequenceL_tmp2);	/*newStructs.sl:113: some(I.keys = 'P')*/
_SequenceL_tmp2.delete_data(false);	
_SequenceL_tmp2.finished();	
if (_SequenceL_tmp4)	/*newStructs.sl:116: [] when some(I.keys = 'P')	else		["ding"] when some(checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls))	else		[]*/
{
_SequenceL_tmp5.setSize(0);	
_convert(_SequenceL_tmp5, _SequenceL__result);	
_SequenceL_tmp5.delete_data(false);	
_SequenceL_tmp5.finished();	
}
else
{
_SequenceL_tmp8.setSize(_SequenceL__Arg_S.balls.size());	
if ((_SequenceL_tmp8.size() - 1) > (sl_get_num_units() * (WORK_SHARE_VALUE * MIN_PARALLEL_ITEMS)))	
{
SequenceL__sl_sounds_nt1_ SequenceL__sl_sounds_nt1__val(_SequenceL__Arg_S, 1, _SequenceL_tmp8.size(), _SequenceL_tmp8);
sl_redistribute_mem();
sl_add_new_nt(1, (sl_get_num_units() * WORK_SHARE_VALUE)+1, SequenceL__sl_sounds_nt1__val);
}
else
{
for (int _SequenceL__i9=1; _SequenceL__i9<=_SequenceL_tmp8.size(); _SequenceL__i9+=1)
{
SequenceL_checkHorizontalBoundaries_0(_SequenceL__Arg_S.balls[_SequenceL__i9], _SequenceL_tmp8[_SequenceL__i9]);	/*newStructs.sl:114: checkHorizontalBoundaries(S.balls)*/
}
}
_SequenceL_tmp11.setSize(_SequenceL__Arg_S.balls.size());	
if ((_SequenceL_tmp11.size() - 1) > (sl_get_num_units() * (WORK_SHARE_VALUE * MIN_PARALLEL_ITEMS)))	
{
SequenceL__sl_sounds_nt3_ SequenceL__sl_sounds_nt3__val(_SequenceL__Arg_S, 1, _SequenceL_tmp11.size(), _SequenceL_tmp11);
sl_redistribute_mem();
sl_add_new_nt(1, (sl_get_num_units() * WORK_SHARE_VALUE)+1, SequenceL__sl_sounds_nt3__val);
}
else
{
for (int _SequenceL__i12=1; _SequenceL__i12<=_SequenceL_tmp11.size(); _SequenceL__i12+=1)
{
SequenceL_checkVerticalBoundaries_0(_SequenceL__Arg_S.balls[_SequenceL__i12], _SequenceL_tmp11[_SequenceL__i12]);	/*newStructs.sl:114: checkVerticalBoundaries(S.balls)*/
}
}
_SequenceL_tmp13.setSize(_SequenceL_tmp8.size());	
if ((_SequenceL_tmp13.size() - 1) > (sl_get_num_units() * (WORK_SHARE_VALUE * MIN_PARALLEL_ITEMS)))	
{
sequenceL_check_sizes("newStructs.sl:114: checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls)", 2, _SequenceL_tmp8.size(), _SequenceL_tmp11.size());
SequenceL__sl_sounds_nt5_ SequenceL__sl_sounds_nt5__val(_SequenceL_tmp8, _SequenceL_tmp11, 1, _SequenceL_tmp13.size(), _SequenceL_tmp13);
sl_redistribute_mem();
sl_add_new_nt(1, (sl_get_num_units() * WORK_SHARE_VALUE)+1, SequenceL__sl_sounds_nt5__val);
_SequenceL_tmp8.delete_data(false);	
_SequenceL_tmp11.delete_data(false);	
_SequenceL_tmp8.finished();	
_SequenceL_tmp11.finished();	
}
else
{
sequenceL_check_sizes("newStructs.sl:114: checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls)", 2, _SequenceL_tmp8.size(), _SequenceL_tmp11.size());
for (int _SequenceL__i14=1; _SequenceL__i14<=_SequenceL_tmp13.size(); _SequenceL__i14+=1)
{
_SequenceL_tmp13[_SequenceL__i14] = (_SequenceL_tmp8[_SequenceL__i14] || _SequenceL_tmp11[_SequenceL__i14]);	/*newStructs.sl:114: checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls)*/
}
_SequenceL_tmp8.delete_data(false);	
_SequenceL_tmp11.delete_data(false);	
_SequenceL_tmp8.finished();	
_SequenceL_tmp11.finished();	
}
_SequenceL_tmp15 = some(_SequenceL_tmp13);	/*newStructs.sl:115: some(checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls))*/
_SequenceL_tmp13.delete_data(false);	
_SequenceL_tmp13.finished();	
if (_SequenceL_tmp15)	/*newStructs.sl:116: ["ding"] when some(checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls))	else		[]*/
{
_SequenceL__result.setSize(1);	
_SequenceL_tmp17.setSize(4);	
_SequenceL_tmp17[1] = 'd';	
_SequenceL_tmp17[2] = 'i';	
_SequenceL_tmp17[3] = 'n';	
_SequenceL_tmp17[4] = 'g';	
_SequenceL__result[1] = _SequenceL_tmp17;	
_SequenceL_tmp17.delete_data(false);	
_SequenceL_tmp17.finished();	
}
else
{
_SequenceL_tmp18.setSize(0);	
_convert(_SequenceL_tmp18, _SequenceL__result);	
_SequenceL_tmp18.delete_data(false);	
_SequenceL_tmp18.finished();	
}
}
}
void SequenceL_newColor_0(int _SequenceL__Arg_r, int _SequenceL__Arg_g, int _SequenceL__Arg_b, _sl_Color_0 &_SequenceL__result)
{

_SequenceL__result.red = _SequenceL__Arg_r;	
_SequenceL__result.green = _SequenceL__Arg_g;	
_SequenceL__result.blue = _SequenceL__Arg_b;	
}
void SequenceL_newGraphic_0(_sl_Point_0 &_SequenceL__Arg_ce, Sequence< char > &_SequenceL__Arg_file, _sl_Image_0 &_SequenceL__result)
{
Sequence< char > _SequenceL_tmp1(cspace);
_sl_Color_0 _SequenceL_tmp2(cspace);
_sl_Point_0 _SequenceL_tmp3(cspace);
_sl_Point_0 _SequenceL_tmp4(cspace);
_sl_Point_0 _SequenceL_tmp5(cspace);

_SequenceL_tmp1.setSize(7);	
_SequenceL_tmp1[1] = 'g';	
_SequenceL_tmp1[2] = 'r';	
_SequenceL_tmp1[3] = 'a';	
_SequenceL_tmp1[4] = 'p';	
_SequenceL_tmp1[5] = 'h';	
_SequenceL_tmp1[6] = 'i';	
_SequenceL_tmp1[7] = 'c';	
_SequenceL__result.kind = _SequenceL_tmp1;	
_SequenceL_tmp1.delete_data(true);	
_SequenceL_tmp1.finished();	
_SequenceL__result.center = _SequenceL__Arg_ce;	
_SequenceL__result.source = _SequenceL__Arg_file;	
_SequenceL_tmp2 = _SequenceL_dViolet_0;	
_SequenceL__result.iColor = _SequenceL_tmp2;	
_SequenceL_tmp2._delete_data(true);	
_SequenceL_tmp2._finished();	
_SequenceL_tmp3 = _SequenceL_originPoint_0;	
_SequenceL__result.vert1 = _SequenceL_tmp3;	
_SequenceL_tmp3._delete_data(true);	
_SequenceL_tmp3._finished();	
_SequenceL_tmp4 = _SequenceL_originPoint_0;	
_SequenceL__result.vert2 = _SequenceL_tmp4;	
_SequenceL_tmp4._delete_data(true);	
_SequenceL_tmp4._finished();	
_SequenceL_tmp5 = _SequenceL_originPoint_0;	
_SequenceL__result.vert3 = _SequenceL_tmp5;	
_SequenceL_tmp5._delete_data(true);	
_SequenceL_tmp5._finished();	
}
void SequenceL_mySign_0(int _SequenceL__Arg_x, int &_SequenceL__result)
{

if (_SequenceL__Arg_x >= 0)	/*newStructs.sl:87: 1 when x >= 0 else -1*/
{
_SequenceL__result = 1;	
}
else
{
_SequenceL__result = (-1);	/*newStructs.sl:87: -1*/
}
}
void SequenceL_xFlip_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result)
{
SL_FLOAT _SequenceL__Arg_xV;
SL_FLOAT _SequenceL__Arg_yV;

_SequenceL__Arg_xV = ((-1.0) * _SequenceL__Arg_B.bxv);	/*newStructs.sl:59: -1.0 * B.bxv*/
_SequenceL__Arg_yV = _SequenceL__Arg_B.byv;	/*newStructs.sl:60: B.byv*/
SequenceL_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:62: newBall(B.ballCenter, B.ballRad, xV, yV)"), _SequenceL__Arg_B.ballRad, _SequenceL__Arg_xV, _SequenceL__Arg_yV, _SequenceL__result);	/*newStructs.sl:62: newBall(B.ballCenter, B.ballRad, xV, yV)*/
}
void SequenceL_yFlip_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result)
{
SL_FLOAT _SequenceL__Arg_xV;
SL_FLOAT _SequenceL__Arg_yV;

_SequenceL__Arg_xV = _SequenceL__Arg_B.bxv;	/*newStructs.sl:67: B.bxv*/
_SequenceL__Arg_yV = ((-1.0) * _SequenceL__Arg_B.byv);	/*newStructs.sl:66: -1.0 * B.byv*/
SequenceL_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:69: newBall(B.ballCenter, B.ballRad, xV, yV)"), _SequenceL__Arg_B.ballRad, _SequenceL__Arg_xV, _SequenceL__Arg_yV, _SequenceL__result);	/*newStructs.sl:69: newBall(B.ballCenter, B.ballRad, xV, yV)*/
}
void SequenceL_floatToInt_2(SL_FLOAT _SequenceL__Arg_float, int &_SequenceL__result)
{
int _SequenceL_tmp4;
SL_FLOAT _SequenceL_tmp3;

if (_SequenceL__Arg_float < 0)	/*Conversion.sl:119: -floatToInt(-float) when float < 0	else		floor(float)*/
{
_SequenceL_tmp3 = (-_SequenceL__Arg_float);	/*Conversion.sl:117: -float*/
SequenceL_floatToInt_2(_SequenceL_tmp3, _SequenceL_tmp4);	/*Conversion.sl:117: floatToInt(-float)*/
_SequenceL__result = (-_SequenceL_tmp4);	/*Conversion.sl:117: -floatToInt(-float)*/
}
else
{
_SequenceL__result = ((int) floor(_SequenceL__Arg_float));	/*Conversion.sl:119: floor(float)*/
}
}
void SequenceL_newBall_0(_sl_Point_0 &_SequenceL__Arg_c, int _SequenceL__Arg_r, SL_FLOAT _SequenceL__Arg_x, SL_FLOAT _SequenceL__Arg_y, _sl_Ball_0 &_SequenceL__result)
{

_SequenceL__result.ballCenter = _SequenceL__Arg_c;	
_SequenceL__result.ballRad = _SequenceL__Arg_r;	
_SequenceL__result.bxv = _SequenceL__Arg_x;	
_SequenceL__result.byv = _SequenceL__Arg_y;	
}
void SequenceL_ballRight_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result)
{

_SequenceL__result = (_SequenceL__Arg_ball.ballCenter.val("newStructs.sl:71: ball.ballCenter.x + ball.ballRad").x + _SequenceL__Arg_ball.ballRad);	/*newStructs.sl:71: ball.ballCenter.x + ball.ballRad*/
}
void SequenceL_ballLeft_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result)
{

_SequenceL__result = (_SequenceL__Arg_ball.ballCenter.val("newStructs.sl:72: ball.ballCenter.x - ball.ballRad").x - _SequenceL__Arg_ball.ballRad);	/*newStructs.sl:72: ball.ballCenter.x - ball.ballRad*/
}
void SequenceL_ballTop_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result)
{

_SequenceL__result = (_SequenceL__Arg_ball.ballCenter.val("newStructs.sl:73: ball.ballCenter.y + ball.ballRad").y + _SequenceL__Arg_ball.ballRad);	/*newStructs.sl:73: ball.ballCenter.y + ball.ballRad*/
}
void SequenceL_ballBottom_0(_sl_Ball_0 &_SequenceL__Arg_ball, int &_SequenceL__result)
{

_SequenceL__result = (_SequenceL__Arg_ball.ballCenter.val("newStructs.sl:74: ball.ballCenter.y - ball.ballRad").y - _SequenceL__Arg_ball.ballRad);	/*newStructs.sl:74: ball.ballCenter.y - ball.ballRad*/
}
void SequenceL_newPoint_0(int _SequenceL__Arg_a, int _SequenceL__Arg_b, _sl_Point_0 &_SequenceL__result)
{

_SequenceL__result.x = _SequenceL__Arg_a;	
_SequenceL__result.y = _SequenceL__Arg_b;	
}
void SequenceL_newDisc_0(_sl_Point_0 &_SequenceL__Arg_ce, int _SequenceL__Arg_rad, _sl_Color_0 &_SequenceL__Arg_c, _sl_Image_0 &_SequenceL__result)
{
Sequence< char > _SequenceL_tmp1(cspace);
_sl_Point_0 _SequenceL_tmp2(cspace);
_sl_Point_0 _SequenceL_tmp3(cspace);
_sl_Point_0 _SequenceL_tmp4(cspace);

_SequenceL_tmp1.setSize(4);	
_SequenceL_tmp1[1] = 'd';	
_SequenceL_tmp1[2] = 'i';	
_SequenceL_tmp1[3] = 's';	
_SequenceL_tmp1[4] = 'c';	
_SequenceL__result.kind = _SequenceL_tmp1;	
_SequenceL_tmp1.delete_data(true);	
_SequenceL_tmp1.finished();	
_SequenceL__result.center = _SequenceL__Arg_ce;	
_SequenceL__result.radius = _SequenceL__Arg_rad;	
_SequenceL__result.iColor = _SequenceL__Arg_c;	
_SequenceL_tmp2 = _SequenceL_originPoint_0;	
_SequenceL__result.vert1 = _SequenceL_tmp2;	
_SequenceL_tmp2._delete_data(true);	
_SequenceL_tmp2._finished();	
_SequenceL_tmp3 = _SequenceL_originPoint_0;	
_SequenceL__result.vert2 = _SequenceL_tmp3;	
_SequenceL_tmp3._delete_data(true);	
_SequenceL_tmp3._finished();	
_SequenceL_tmp4 = _SequenceL_originPoint_0;	
_SequenceL__result.vert3 = _SequenceL_tmp4;	
_SequenceL_tmp4._delete_data(true);	
_SequenceL_tmp4._finished();	
}
void SequenceL_ballImg_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Image_0 &_SequenceL__result)
{
Sequence< char > _SequenceL_tmp2(cspace);

_SequenceL_tmp2.setSize(12);	
_SequenceL_tmp2[1] = 'T';	
_SequenceL_tmp2[2] = 'e';	
_SequenceL_tmp2[3] = 's';	
_SequenceL_tmp2[4] = 't';	
_SequenceL_tmp2[5] = 'B';	
_SequenceL_tmp2[6] = 'a';	
_SequenceL_tmp2[7] = 'l';	
_SequenceL_tmp2[8] = 'l';	
_SequenceL_tmp2[9] = '.';	
_SequenceL_tmp2[10] = 'j';	
_SequenceL_tmp2[11] = 'p';	
_SequenceL_tmp2[12] = 'g';	
SequenceL_newGraphic_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:93: newGraphic(B.ballCenter, \"TestBall.jpg\")"), _SequenceL_tmp2, _SequenceL__result);	/*newStructs.sl:93: newGraphic(B.ballCenter, "TestBall.jpg")*/
_SequenceL_tmp2.delete_data(true);	
_SequenceL_tmp2.finished();	
}
void SequenceL_speedUp_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result)
{
SL_FLOAT _SequenceL_tmp7;
int _SequenceL_tmp6;
int _SequenceL_tmp5;
SL_FLOAT _SequenceL_tmp12;
int _SequenceL_tmp11;
int _SequenceL_tmp10;

SequenceL_floatToInt_2(_SequenceL__Arg_B.bxv, _SequenceL_tmp5);	/*newStructs.sl:89: floatToInt(B.bxv)*/
SequenceL_mySign_0(_SequenceL_tmp5, _SequenceL_tmp6);	/*newStructs.sl:89: mySign(floatToInt(B.bxv))*/
_SequenceL_tmp7 = (_SequenceL__Arg_B.bxv + _SequenceL_tmp6);	/*newStructs.sl:89: B.bxv + mySign(floatToInt(B.bxv))*/
SequenceL_floatToInt_2(_SequenceL__Arg_B.byv, _SequenceL_tmp10);	/*newStructs.sl:89: floatToInt(B.byv)*/
SequenceL_mySign_0(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:89: mySign(floatToInt(B.byv))*/
_SequenceL_tmp12 = (_SequenceL__Arg_B.byv + _SequenceL_tmp11);	/*newStructs.sl:89: B.byv + mySign(floatToInt(B.byv))*/
SequenceL_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:89: newBall(B.ballCenter, B.ballRad, B.bxv + mySign(floatToInt(B.bxv)), B.byv + mySign(floatToInt(B.byv)))"), _SequenceL__Arg_B.ballRad, _SequenceL_tmp7, _SequenceL_tmp12, _SequenceL__result);	/*newStructs.sl:89: newBall(B.ballCenter, B.ballRad, B.bxv + mySign(floatToInt(B.bxv)), B.byv + mySign(floatToInt(B.byv)))*/
}
void SequenceL_slowDown_0(_sl_Ball_0 &_SequenceL__Arg_B, _sl_Ball_0 &_SequenceL__result)
{
SL_FLOAT _SequenceL_tmp7;
int _SequenceL_tmp6;
int _SequenceL_tmp5;
SL_FLOAT _SequenceL_tmp12;
int _SequenceL_tmp11;
int _SequenceL_tmp10;

SequenceL_floatToInt_2(_SequenceL__Arg_B.bxv, _SequenceL_tmp5);	/*newStructs.sl:91: floatToInt(B.bxv)*/
SequenceL_mySign_0(_SequenceL_tmp5, _SequenceL_tmp6);	/*newStructs.sl:91: mySign(floatToInt(B.bxv))*/
_SequenceL_tmp7 = (_SequenceL__Arg_B.bxv - _SequenceL_tmp6);	/*newStructs.sl:91: B.bxv - mySign(floatToInt(B.bxv))*/
SequenceL_floatToInt_2(_SequenceL__Arg_B.byv, _SequenceL_tmp10);	/*newStructs.sl:91: floatToInt(B.byv)*/
SequenceL_mySign_0(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:91: mySign(floatToInt(B.byv))*/
_SequenceL_tmp12 = (_SequenceL__Arg_B.byv - _SequenceL_tmp11);	/*newStructs.sl:91: B.byv - mySign(floatToInt(B.byv))*/
SequenceL_newBall_0(_SequenceL__Arg_B.ballCenter.val("newStructs.sl:91: newBall(B.ballCenter, B.ballRad, B.bxv - mySign(floatToInt(B.bxv)), B.byv - mySign(floatToInt(B.byv)))"), _SequenceL__Arg_B.ballRad, _SequenceL_tmp7, _SequenceL_tmp12, _SequenceL__result);	/*newStructs.sl:91: newBall(B.ballCenter, B.ballRad, B.bxv - mySign(floatToInt(B.bxv)), B.byv - mySign(floatToInt(B.byv)))*/
}
void SequenceL_drop_1(Sequence< _sl_Ball_0 > &_SequenceL__Arg_list, int _SequenceL__Arg_n, Sequence< _sl_Ball_0 > &_SequenceL__result)
{

_SequenceL__Arg_list.sub_seq((_SequenceL__Arg_n + 1), _SequenceL__Arg_list.size(), _SequenceL__result);	/*Sequence.sl:142: list[(n + 1) ... size(list)]*/
}
void SequenceL_ballMove_0(_sl_Ball_0 &_SequenceL__Arg_B, Sequence< _sl_Ball_0 > &_SequenceL__Arg_otherBalls, _sl_Ball_0 &_SequenceL__result)
{
_sl_Point_0 _SequenceL_tmp17(cspace);
int _SequenceL_tmp11;
SL_FLOAT _SequenceL_tmp10;
_sl_Ball_0 _SequenceL__Arg_yBall(cspace);
bool _SequenceL_tmp6;
_sl_Ball_0 _SequenceL__Arg_xBall(cspace);
bool _SequenceL_tmp3;
int _SequenceL_tmp16;
SL_FLOAT _SequenceL_tmp15;

SequenceL_checkHorizontalBoundaries_0(_SequenceL__Arg_B, _SequenceL_tmp3);	/*newStructs.sl:82: checkHorizontalBoundaries(B)*/
if (_SequenceL_tmp3)	/*newStructs.sl:82: xFlip(B) when checkHorizontalBoundaries(B) else B*/
{
SequenceL_xFlip_0(_SequenceL__Arg_B, _SequenceL__Arg_xBall);	/*newStructs.sl:82: xFlip(B)*/
}
else
{
_SequenceL__Arg_xBall = _SequenceL__Arg_B;	
}
SequenceL_checkVerticalBoundaries_0(_SequenceL__Arg_xBall, _SequenceL_tmp6);	/*newStructs.sl:83: checkVerticalBoundaries(xBall)*/
if (_SequenceL_tmp6)	/*newStructs.sl:83: yFlip(xBall) when checkVerticalBoundaries(xBall) else xBall*/
{
SequenceL_yFlip_0(_SequenceL__Arg_xBall, _SequenceL__Arg_yBall);	/*newStructs.sl:83: yFlip(xBall)*/
_SequenceL__Arg_xBall._delete_data(true);	
_SequenceL__Arg_xBall._finished();	
}
else
{
_SequenceL__Arg_yBall = _SequenceL__Arg_xBall;	
_SequenceL__Arg_xBall._delete_data(true);	
_SequenceL__Arg_xBall._finished();	
}
_SequenceL_tmp10 = (_SequenceL__Arg_B.ballCenter.val("newStructs.sl:85: B.ballCenter.x + yBall.bxv").x + _SequenceL__Arg_yBall.bxv);	/*newStructs.sl:85: B.ballCenter.x + yBall.bxv*/
SequenceL_floatToInt_2(_SequenceL_tmp10, _SequenceL_tmp11);	/*newStructs.sl:85: floatToInt(B.ballCenter.x + yBall.bxv)*/
_SequenceL_tmp15 = (_SequenceL__Arg_B.ballCenter.val("newStructs.sl:85: B.ballCenter.y + yBall.byv").y + _SequenceL__Arg_yBall.byv);	/*newStructs.sl:85: B.ballCenter.y + yBall.byv*/
SequenceL_floatToInt_2(_SequenceL_tmp15, _SequenceL_tmp16);	/*newStructs.sl:85: floatToInt(B.ballCenter.y + yBall.byv)*/
SequenceL_newPoint_0(_SequenceL_tmp11, _SequenceL_tmp16, _SequenceL_tmp17);	/*newStructs.sl:85: newPoint(floatToInt(B.ballCenter.x + yBall.bxv), floatToInt(B.ballCenter.y + yBall.byv))*/
SequenceL_newBall_0(_SequenceL_tmp17, _SequenceL__Arg_B.ballRad, _SequenceL__Arg_yBall.bxv, _SequenceL__Arg_yBall.byv, _SequenceL__result);	/*newStructs.sl:85: newBall(newPoint(floatToInt(B.ballCenter.x + yBall.bxv), floatToInt(B.ballCenter.y + yBall.byv)), B.ballRad, yBall.bxv, yBall.byv)*/
_SequenceL_tmp17._delete_data(true);	
_SequenceL__Arg_yBall._delete_data(true);	
_SequenceL_tmp17._finished();	
_SequenceL__Arg_yBall._finished();	
}
void SequenceL_buildState_0(Sequence< _sl_Ball_0 > &_SequenceL__Arg_ba, _sl_State_0 &_SequenceL__result)
{

_SequenceL__result.balls = _SequenceL__Arg_ba;	
}
void SequenceL_checkHorizontalBoundaries_0(_sl_Ball_0 &_SequenceL__Arg_ball, bool &_SequenceL__result)
{
int _SequenceL_tmp1;
int _SequenceL_tmp3;

SequenceL_ballRight_0(_SequenceL__Arg_ball, _SequenceL_tmp1);	/*newStructs.sl:78: ballRight(ball)*/
SequenceL_ballLeft_0(_SequenceL__Arg_ball, _SequenceL_tmp3);	/*newStructs.sl:78: ballLeft(ball)*/
_SequenceL__result = ((_SequenceL_tmp1 >= 1000) || (_SequenceL_tmp3 <= 0));	/*newStructs.sl:78: ballRight(ball) >= 1000 or ballLeft(ball) <= 0*/
}
void SequenceL_checkVerticalBoundaries_0(_sl_Ball_0 &_SequenceL__Arg_ball, bool &_SequenceL__result)
{
int _SequenceL_tmp1;
int _SequenceL_tmp3;

SequenceL_ballTop_0(_SequenceL__Arg_ball, _SequenceL_tmp1);	/*newStructs.sl:76: ballTop(ball)*/
SequenceL_ballBottom_0(_SequenceL__Arg_ball, _SequenceL_tmp3);	/*newStructs.sl:76: ballBottom(ball)*/
_SequenceL__result = ((_SequenceL_tmp1 >= 800) || (_SequenceL_tmp3 <= 0));	/*newStructs.sl:76: ballTop(ball) >= 800 or ballBottom(ball) <= 0*/
}
void SequenceL_images_0(_sl_State_0 &_SequenceL__Arg_S, Sequence< _sl_Image_0 > &_SequenceL__result)
{
Sequence< _sl_Image_0 > _SequenceL_tmp1(cspace);
_sl_Image_0 _SequenceL_tmp4(cspace);
_sl_Point_0 _SequenceL_tmp2(cspace);
_sl_Color_0 _SequenceL_tmp3(cspace);
Sequence< _sl_Image_0 > _SequenceL_tmp6(cspace);

_SequenceL_tmp1.setSize(1);	
SequenceL_newPoint_0(500, 400, _SequenceL_tmp2);	/*newStructs.sl:109: newPoint(500, 400)*/
_SequenceL_tmp3 = _SequenceL_dBlack_0;	
SequenceL_newDisc_0(_SequenceL_tmp2, 641, _SequenceL_tmp3, _SequenceL_tmp4);	/*newStructs.sl:109: newDisc(newPoint(500, 400), 641, dBlack)*/
_SequenceL_tmp2._delete_data(true);	
_SequenceL_tmp3._delete_data(true);	
_SequenceL_tmp2._finished();	
_SequenceL_tmp3._finished();	
_SequenceL_tmp1[1] = _SequenceL_tmp4;	
_SequenceL_tmp4._delete_data(true);	
_SequenceL_tmp4._finished();	
_SequenceL_tmp6.setSize(_SequenceL__Arg_S.balls.size());	
for (int _SequenceL__i7=1; _SequenceL__i7<=_SequenceL_tmp6.size(); _SequenceL__i7+=1)
{
SequenceL_ballImg_0(_SequenceL__Arg_S.balls[_SequenceL__i7], _SequenceL_tmp6[_SequenceL__i7]);	/*newStructs.sl:109: ballImg(S.balls)*/
}
append(_SequenceL_tmp1, _SequenceL_tmp6, _SequenceL__result);	/*newStructs.sl:109: [newDisc(newPoint(500, 400), 641, dBlack)] ++ ballImg(S.balls)*/
_SequenceL_tmp1.delete_data(true);	
_SequenceL_tmp6.delete_data(true);	
_SequenceL_tmp1.finished();	
_SequenceL_tmp6.finished();	
}
void SequenceL_newState_0(_sl_Input_0 &_SequenceL__Arg_I, _sl_State_0 &_SequenceL__Arg_S, _sl_State_0 &_SequenceL__result)
{
bool _SequenceL_tmp4;
Sequence< bool > _SequenceL_tmp2(cspace);
bool _SequenceL_tmp10;
Sequence< bool > _SequenceL_tmp8(cspace);
Sequence< _sl_Ball_0 > _SequenceL__Arg_newPos(cspace);
Sequence< _sl_Ball_0 > _SequenceL_tmp15(cspace);
Sequence< _sl_Ball_0 > _SequenceL_tmp16(cspace);
bool _SequenceL_tmp22;
Sequence< bool > _SequenceL_tmp20(cspace);
Sequence< _sl_Ball_0 > _SequenceL_tmp27(cspace);
Sequence< _sl_Ball_0 > _SequenceL_tmp28(cspace);
Sequence< _sl_Ball_0 > _SequenceL_tmp34(cspace);

_SequenceL_tmp2.setSize(_SequenceL__Arg_I.keys.size());	
for (int _SequenceL__i3=1; _SequenceL__i3<=_SequenceL_tmp2.size(); _SequenceL__i3+=1)
{
_SequenceL_tmp2[_SequenceL__i3] = (_SequenceL__Arg_I.keys[_SequenceL__i3] == 'P');	/*newStructs.sl:101: I.keys = 'P'*/
}
_SequenceL_tmp4 = some(_SequenceL_tmp2);	/*newStructs.sl:102: some(I.keys = 'P')*/
_SequenceL_tmp2.delete_data(true);	
_SequenceL_tmp2.finished();	
if (_SequenceL_tmp4)	/*newStructs.sl:107: S when some(I.keys = 'P')	else		buildState(speedUp(newPos)) when some(I.keys = 'W')	else		buildState(slowDown(newPos)) when some(I.keys = 'S')	else		buildState(newPos)*/
{
_SequenceL__result = _SequenceL__Arg_S;	
}
else
{
_SequenceL_tmp8.setSize(_SequenceL__Arg_I.keys.size());	
for (int _SequenceL__i9=1; _SequenceL__i9<=_SequenceL_tmp8.size(); _SequenceL__i9+=1)
{
_SequenceL_tmp8[_SequenceL__i9] = (_SequenceL__Arg_I.keys[_SequenceL__i9] == 'W');	/*newStructs.sl:103: I.keys = 'W'*/
}
_SequenceL_tmp10 = some(_SequenceL_tmp8);	/*newStructs.sl:104: some(I.keys = 'W')*/
_SequenceL_tmp8.delete_data(true);	
_SequenceL_tmp8.finished();	
if (_SequenceL_tmp10)	/*newStructs.sl:107: buildState(speedUp(newPos)) when some(I.keys = 'W')	else		buildState(slowDown(newPos)) when some(I.keys = 'S')	else		buildState(newPos)*/
{
_SequenceL__Arg_newPos.setSize(_SequenceL__Arg_S.balls.size());	
for (int _SequenceL__scope__Index_newPos_i=1; _SequenceL__scope__Index_newPos_i<=_SequenceL__Arg_newPos.size(); _SequenceL__scope__Index_newPos_i+=1)
{
SequenceL_drop_1(_SequenceL__Arg_S.balls, _SequenceL__scope__Index_newPos_i, _SequenceL_tmp15);	/*newStructs.sl:99: drop(S.balls, i)*/
SequenceL_ballMove_0(_SequenceL__Arg_S.balls[_SequenceL__scope__Index_newPos_i], _SequenceL_tmp15, _SequenceL__Arg_newPos[_SequenceL__scope__Index_newPos_i]);	/*newStructs.sl:99: ballMove(S.balls[i], drop(S.balls, i))*/
}
_SequenceL_tmp15.delete_data(true);	
_SequenceL_tmp15.finished();	
_SequenceL_tmp16.setSize(_SequenceL__Arg_newPos.size());	
for (int _SequenceL__i17=1; _SequenceL__i17<=_SequenceL_tmp16.size(); _SequenceL__i17+=1)
{
SequenceL_speedUp_0(_SequenceL__Arg_newPos[_SequenceL__i17], _SequenceL_tmp16[_SequenceL__i17]);	/*newStructs.sl:103: speedUp(newPos)*/
}
_SequenceL__Arg_newPos.delete_data(true);	
_SequenceL__Arg_newPos.finished();	
SequenceL_buildState_0(_SequenceL_tmp16, _SequenceL__result);	/*newStructs.sl:103: buildState(speedUp(newPos))*/
_SequenceL_tmp16.delete_data(true);	
_SequenceL_tmp16.finished();	
}
else
{
_SequenceL_tmp20.setSize(_SequenceL__Arg_I.keys.size());	
for (int _SequenceL__i21=1; _SequenceL__i21<=_SequenceL_tmp20.size(); _SequenceL__i21+=1)
{
_SequenceL_tmp20[_SequenceL__i21] = (_SequenceL__Arg_I.keys[_SequenceL__i21] == 'S');	/*newStructs.sl:105: I.keys = 'S'*/
}
_SequenceL_tmp22 = some(_SequenceL_tmp20);	/*newStructs.sl:106: some(I.keys = 'S')*/
_SequenceL_tmp20.delete_data(true);	
_SequenceL_tmp20.finished();	
if (_SequenceL_tmp22)	/*newStructs.sl:107: buildState(slowDown(newPos)) when some(I.keys = 'S')	else		buildState(newPos)*/
{
_SequenceL__Arg_newPos.setSize(_SequenceL__Arg_S.balls.size());	
for (int _SequenceL__scope__Index_newPos_i=1; _SequenceL__scope__Index_newPos_i<=_SequenceL__Arg_newPos.size(); _SequenceL__scope__Index_newPos_i+=1)
{
SequenceL_drop_1(_SequenceL__Arg_S.balls, _SequenceL__scope__Index_newPos_i, _SequenceL_tmp27);	/*newStructs.sl:99: drop(S.balls, i)*/
SequenceL_ballMove_0(_SequenceL__Arg_S.balls[_SequenceL__scope__Index_newPos_i], _SequenceL_tmp27, _SequenceL__Arg_newPos[_SequenceL__scope__Index_newPos_i]);	/*newStructs.sl:99: ballMove(S.balls[i], drop(S.balls, i))*/
}
_SequenceL_tmp27.delete_data(true);	
_SequenceL_tmp27.finished();	
_SequenceL_tmp28.setSize(_SequenceL__Arg_newPos.size());	
for (int _SequenceL__i29=1; _SequenceL__i29<=_SequenceL_tmp28.size(); _SequenceL__i29+=1)
{
SequenceL_slowDown_0(_SequenceL__Arg_newPos[_SequenceL__i29], _SequenceL_tmp28[_SequenceL__i29]);	/*newStructs.sl:105: slowDown(newPos)*/
}
_SequenceL__Arg_newPos.delete_data(true);	
_SequenceL__Arg_newPos.finished();	
SequenceL_buildState_0(_SequenceL_tmp28, _SequenceL__result);	/*newStructs.sl:105: buildState(slowDown(newPos))*/
_SequenceL_tmp28.delete_data(true);	
_SequenceL_tmp28.finished();	
}
else
{
_SequenceL__Arg_newPos.setSize(_SequenceL__Arg_S.balls.size());	
for (int _SequenceL__scope__Index_newPos_i=1; _SequenceL__scope__Index_newPos_i<=_SequenceL__Arg_newPos.size(); _SequenceL__scope__Index_newPos_i+=1)
{
SequenceL_drop_1(_SequenceL__Arg_S.balls, _SequenceL__scope__Index_newPos_i, _SequenceL_tmp34);	/*newStructs.sl:99: drop(S.balls, i)*/
SequenceL_ballMove_0(_SequenceL__Arg_S.balls[_SequenceL__scope__Index_newPos_i], _SequenceL_tmp34, _SequenceL__Arg_newPos[_SequenceL__scope__Index_newPos_i]);	/*newStructs.sl:99: ballMove(S.balls[i], drop(S.balls, i))*/
}
_SequenceL_tmp34.delete_data(true);	
_SequenceL_tmp34.finished();	
SequenceL_buildState_0(_SequenceL__Arg_newPos, _SequenceL__result);	/*newStructs.sl:107: buildState(newPos)*/
_SequenceL__Arg_newPos.delete_data(true);	
_SequenceL__Arg_newPos.finished();	
}
}
}
}
void SequenceL_sounds_0(_sl_Input_0 &_SequenceL__Arg_I, _sl_State_0 &_SequenceL__Arg_S, Sequence< Sequence< char > > &_SequenceL__result)
{
bool _SequenceL_tmp4;
Sequence< bool > _SequenceL_tmp2(cspace);
Sequence< Empty > _SequenceL_tmp5(cspace);
bool _SequenceL_tmp15;
Sequence< bool > _SequenceL_tmp8(cspace);
Sequence< bool > _SequenceL_tmp11(cspace);
Sequence< bool > _SequenceL_tmp13(cspace);
Sequence< char > _SequenceL_tmp17(cspace);
Sequence< Empty > _SequenceL_tmp18(cspace);

_SequenceL_tmp2.setSize(_SequenceL__Arg_I.keys.size());	
for (int _SequenceL__i3=1; _SequenceL__i3<=_SequenceL_tmp2.size(); _SequenceL__i3+=1)
{
_SequenceL_tmp2[_SequenceL__i3] = (_SequenceL__Arg_I.keys[_SequenceL__i3] == 'P');	/*newStructs.sl:112: I.keys = 'P'*/
}
_SequenceL_tmp4 = some(_SequenceL_tmp2);	/*newStructs.sl:113: some(I.keys = 'P')*/
_SequenceL_tmp2.delete_data(true);	
_SequenceL_tmp2.finished();	
if (_SequenceL_tmp4)	/*newStructs.sl:116: [] when some(I.keys = 'P')	else		["ding"] when some(checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls))	else		[]*/
{
_SequenceL_tmp5.setSize(0);	
_convert(_SequenceL_tmp5, _SequenceL__result);	
_SequenceL_tmp5.delete_data(true);	
_SequenceL_tmp5.finished();	
}
else
{
_SequenceL_tmp8.setSize(_SequenceL__Arg_S.balls.size());	
for (int _SequenceL__i9=1; _SequenceL__i9<=_SequenceL_tmp8.size(); _SequenceL__i9+=1)
{
SequenceL_checkHorizontalBoundaries_0(_SequenceL__Arg_S.balls[_SequenceL__i9], _SequenceL_tmp8[_SequenceL__i9]);	/*newStructs.sl:114: checkHorizontalBoundaries(S.balls)*/
}
_SequenceL_tmp11.setSize(_SequenceL__Arg_S.balls.size());	
for (int _SequenceL__i12=1; _SequenceL__i12<=_SequenceL_tmp11.size(); _SequenceL__i12+=1)
{
SequenceL_checkVerticalBoundaries_0(_SequenceL__Arg_S.balls[_SequenceL__i12], _SequenceL_tmp11[_SequenceL__i12]);	/*newStructs.sl:114: checkVerticalBoundaries(S.balls)*/
}
_SequenceL_tmp13.setSize(_SequenceL_tmp8.size());	
sequenceL_check_sizes("newStructs.sl:114: checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls)", 2, _SequenceL_tmp8.size(), _SequenceL_tmp11.size());
for (int _SequenceL__i14=1; _SequenceL__i14<=_SequenceL_tmp13.size(); _SequenceL__i14+=1)
{
_SequenceL_tmp13[_SequenceL__i14] = (_SequenceL_tmp8[_SequenceL__i14] || _SequenceL_tmp11[_SequenceL__i14]);	/*newStructs.sl:114: checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls)*/
}
_SequenceL_tmp8.delete_data(true);	
_SequenceL_tmp11.delete_data(true);	
_SequenceL_tmp8.finished();	
_SequenceL_tmp11.finished();	
_SequenceL_tmp15 = some(_SequenceL_tmp13);	/*newStructs.sl:115: some(checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls))*/
_SequenceL_tmp13.delete_data(true);	
_SequenceL_tmp13.finished();	
if (_SequenceL_tmp15)	/*newStructs.sl:116: ["ding"] when some(checkHorizontalBoundaries(S.balls) or checkVerticalBoundaries(S.balls))	else		[]*/
{
_SequenceL__result.setSize(1);	
_SequenceL_tmp17.setSize(4);	
_SequenceL_tmp17[1] = 'd';	
_SequenceL_tmp17[2] = 'i';	
_SequenceL_tmp17[3] = 'n';	
_SequenceL_tmp17[4] = 'g';	
_SequenceL__result[1] = _SequenceL_tmp17;	
_SequenceL_tmp17.delete_data(true);	
_SequenceL_tmp17.finished();	
}
else
{
_SequenceL_tmp18.setSize(0);	
_convert(_SequenceL_tmp18, _SequenceL__result);	
_SequenceL_tmp18.delete_data(true);	
_SequenceL_tmp18.finished();	
}
}
}
void sl_sounds(_sl_Input_0 &_SequenceL__Arg_arg1, _sl_State_0 &_SequenceL__Arg_arg2, int _n, Sequence< Sequence< char > > &_SequenceL__result)
{
_sl_Input_0 _SequenceL__delete_opttmp1(cspace);
_sl_State_0 _SequenceL__delete_opttmp2(cspace);

bool tag = !sl_active_controller();
if (tag)
{
sl_init(_n);
}
_SequenceL_init_sl_sounds_globals();
_SequenceL__delete_opttmp1 = _SequenceL__Arg_arg1;	
_SequenceL__delete_opttmp2 = _SequenceL__Arg_arg2;	
SequenceL__parallel_sounds_0(_SequenceL__delete_opttmp1, _SequenceL__delete_opttmp2, _SequenceL__result);	
_SequenceL__delete_opttmp1._delete_data(true);	
_SequenceL__delete_opttmp2._delete_data(true);	
_SequenceL__delete_opttmp1._finished();	
_SequenceL__delete_opttmp2._finished();	
_SequenceL_delete_sl_sounds_globals();

if (tag)
{
sl_done();
}
}
void sl_newState(_sl_Input_0 &_SequenceL__Arg_arg1, _sl_State_0 &_SequenceL__Arg_arg2, int _n, _sl_State_0 &_SequenceL__result)
{

bool tag = !sl_active_controller();
if (tag)
{
sl_init(_n);
}
_SequenceL_init_sl_newState_globals();
SequenceL__parallel_newState_0(_SequenceL__Arg_arg1, _SequenceL__Arg_arg2, _SequenceL__result);	
_SequenceL_delete_sl_newState_globals();

if (tag)
{
sl_done();
}
}
void sl_images(_sl_State_0 &_SequenceL__Arg_arg1, int _n, Sequence< _sl_Image_0 > &_SequenceL__result)
{

bool tag = !sl_active_controller();
if (tag)
{
sl_init(_n);
}
_SequenceL_init_sl_images_globals();
SequenceL__parallel_images_0(_SequenceL__Arg_arg1, _SequenceL__result);	
_SequenceL_delete_sl_images_globals();

if (tag)
{
sl_done();
}
}
void sl_initialState( int _n, _sl_State_0 &_SequenceL__result)
{

bool tag = !sl_active_controller();
if (tag)
{
sl_init(_n);
}
_SequenceL_init_sl_initialState_globals();
_SequenceL__result = _SequenceL_initialState_0;	
_SequenceL_delete_sl_initialState_globals();

if (tag)
{
sl_done();
}
}
