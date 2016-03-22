// MyExecRefsDll.h

#pragma once
extern "C"{




#define EASELDLL_API __declspec(dllexport)



namespace EaselDLL
{

	class EaselGame
		{
		public:
			static EASELDLL_API _sl_State* initialState(int);
			static EASELDLL_API _sl_State* newState(bool, int, int, char*, _sl_State *inputState, int);

			static EASELDLL_API void freeState(_sl_State*);

			static EASELDLL_API Sequence<Sequence<char> >* sounds(bool, int, int, char*, _sl_State *state, int);
			static EASELDLL_API int getSoundsCount(Sequence<Sequence<char> >*);
			static EASELDLL_API void getSound(Sequence<Sequence<char> >*, int, char*);

			static EASELDLL_API void freeSounds(Sequence<Sequence<char> >*);

			static EASELDLL_API Sequence<_sl_Image>* images(_sl_State *state, int);
			static EASELDLL_API int getImagesCount(Sequence<_sl_Image>*);
			static EASELDLL_API int getImageKind(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageEnd1X(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageEnd1Y(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageEnd2X(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageEnd2Y(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageEnd3X(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageEnd3Y(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageR(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageG(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageB(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageCenterX(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageCenterY(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageRadius(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageHeight(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageWidth(Sequence<_sl_Image>*, int);
			static EASELDLL_API int getImageText(Sequence<_sl_Image>*, int, char*);
			static EASELDLL_API int getGraphicLocation(Sequence<_sl_Image>*, int, char*);

			static EASELDLL_API void freeImages(Sequence<_sl_Image>*);
    };
}}
