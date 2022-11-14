#pragma once
#include"Player.h"
const int WinWidth = 800;
const int WinHeight = 800;

const int MapChipSize = 32;//マップチップサイズ
const int MapWidth = (WinWidth / MapChipSize) * 2;//マップ幅
const int MapHeight = WinHeight / MapChipSize;//マップ高さ

//マップの種類
enum MapType {
	none,//0
	block//1
};

int  MapLoading(int map[MapHeight][MapWidth]);
void DrawMap(int& textureHandle, int map[MapHeight][MapWidth]);
