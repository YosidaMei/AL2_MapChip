#pragma once
#include"Player.h"
const int WinWidth = 800;
const int WinHeight = 800;

const int MapChipSize = 32;//�}�b�v�`�b�v�T�C�Y
const int MapWidth = (WinWidth / MapChipSize) * 2;//�}�b�v��
const int MapHeight = WinHeight / MapChipSize;//�}�b�v����

//�}�b�v�̎��
enum MapType {
	none,//0
	block//1
};

int  MapLoading(int map[MapHeight][MapWidth]);
void DrawMap(int& textureHandle, int map[MapHeight][MapWidth]);
