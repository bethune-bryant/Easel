// MyExecRefsDll.cpp : Defines the exported functions for the DLL application.
//


#include <iostream>

#include "main.h"
#include "LibraryTest.h"

using namespace std;

namespace EaselDLL
{
_sl_State* EaselGame::initialState(int inCores)
{

	sl_init(inCores);

	_sl_State *result = new _sl_State();

    sl_initialState(inCores, *result);

    return result;
}

_sl_State* EaselGame::newState(bool clicked, int x, int y, char* keys, _sl_State *inputState, int inCores)
{
	_sl_State *result = new _sl_State();
	_sl_Input inputInp;

	inputInp.iClick = new _sl_Click();
	inputInp.iClick.data->clicked = clicked;
	inputInp.iClick.data->clPoint =new _sl_Point();
	inputInp.iClick.data->clPoint.data->x = x;
	inputInp.iClick.data->clPoint.data->y = y;

	int keyDims[] = { strlen(keys), 0};
	Sequence<char> keySeq((void*)keys, keyDims);

	inputInp.keys = keySeq;

	sl_newState(inputInp, *inputState, inCores, *result);

	inputState->_delete_data(true);
	free(inputState);

	return result;
}

Sequence<Sequence<char> >* EaselGame::sounds(bool clicked, int x, int y, char* keys, _sl_State *inputState, int inCores)
{
	Sequence<Sequence<char> > *result = new Sequence<Sequence<char> >();
	_sl_Input inputInp;

	inputInp.iClick = new _sl_Click();
	inputInp.iClick.data->clicked = clicked;
	inputInp.iClick.data->clPoint =new _sl_Point();
	inputInp.iClick.data->clPoint.data->x = x;
	inputInp.iClick.data->clPoint.data->y = y;

	int keyDims[] = { strlen(keys), 0};
	Sequence<char> keySeq((void*)keys, keyDims);

	inputInp.keys = keySeq;

	sl_sounds(inputInp, *inputState, inCores, *result);

	return result;
}

int EaselGame::getSoundsCount(Sequence<Sequence<char> >* soundsSeq)
{
	return soundsSeq->size();
}

void EaselGame::getSound(Sequence<Sequence<char> >* soundsSeq, int index, char* textOut)
{
	stringstream ss;

	ss << (*soundsSeq)[index];

	strcpy(textOut, ss.str().substr(1, ss.str().length()-2).c_str());
}

Sequence<_sl_Image>* EaselGame::images(_sl_State *state, int inCores)
{
	Sequence<_sl_Image> *result = new Sequence<_sl_Image>();

	sl_images(*state, inCores, *result);

	return result;
}

int EaselGame::getImagesCount(Sequence<_sl_Image>* imagesSeq)
{
	return imagesSeq->size();
}

int EaselGame::getImageKind(Sequence<_sl_Image>* imagesSeq, int index)
{
	char kind = (*imagesSeq)[index].kind[1];

	switch(kind)
	{
	case('s'):
			return 1;
	case('c'):
			return 2;
	case('d'):
			return 3;
	case('t'):
			switch((*imagesSeq)[index].kind[2])
			{
			case('e'):
					return 4;
			case('r'):
					return 5;
			}
			break;
	case('g'):
			return 6;

	}

	return 0;
}

int EaselGame::getImageEnd1X(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].vert1.data->x;
}

int EaselGame::getImageEnd1Y(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].vert1.data->y;
}

int EaselGame::getImageEnd2X(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].vert2.data->x;
}

int EaselGame::getImageEnd2Y(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].vert2.data->y;
}

int EaselGame::getImageEnd3X(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].vert3.data->x;
}

int EaselGame::getImageEnd3Y(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].vert3.data->y;
}

int EaselGame::getImageR(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].iColor.data->red;
}

int EaselGame::getImageG(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].iColor.data->green;
}

int EaselGame::getImageB(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].iColor.data->blue;
}

int EaselGame::getImageCenterX(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].center.data->x;
}

int EaselGame::getImageCenterY(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].center.data->y;
}

int EaselGame::getImageRadius(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].radius;
}

int EaselGame::getImageHeight(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].height;
}

int EaselGame::getImageWidth(Sequence<_sl_Image>* imagesSeq, int index)
{
	return (*imagesSeq)[index].width;
}

int EaselGame::getImageText(Sequence<_sl_Image>* imagesSeq, int index, char* textOut)
{
	stringstream ss;

	ss << (*imagesSeq)[index].message;

	strcpy(textOut, ss.str().substr(1, ss.str().length()-2).c_str());

	return 0;
}

int EaselGame::getGraphicLocation(Sequence<_sl_Image>* imagesSeq, int index, char* textOut)
{
	stringstream ss;

	ss << (*imagesSeq)[index].source;

	strcpy(textOut, ss.str().substr(1, ss.str().length()-2).c_str());

	return 0;
}

void EaselGame::freeState(_sl_State* state)
{
	state->_delete_data(true);
	free(state);
}

void EaselGame::freeImages(Sequence<_sl_Image>* imagesSeq)
{
	imagesSeq->delete_data(true);
	free(imagesSeq);
}

void EaselGame::freeSounds(Sequence<Sequence<char> >* soundsSeq)
{
	soundsSeq->delete_data(true);
	free(soundsSeq);
}


}
