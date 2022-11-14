#pragma once
#include "Map.h"
typedef struct Vector2 {
	int x;
	int y;
 };
typedef struct Quad {
	Vector2 leftTop;
	Vector2 rightTop;
	Vector2 leftBottom;
	Vector2 rightBottom;
};
typedef struct Player {

	const int size = 32;//サイズ
	const int radius = size / 2;//半径
	
	Quad quad;//四角
	Vector2 pos;//位置
	Vector2 posTmp;//仮位置
	Vector2 mapNum;//マップの位置
	Vector2 vel;//速度
	int HP;//体力
	int isAlive;//生きているか
	int textureHandle;//画像
	int textureHandleNumber = 0;//テクスチャハンドルナンバー

	int animationNumber = 0;//アニメが今何枚目か
	int AnimationNumberMax = 0;//アニメの最大枚数
	int animationTime = 0;
	const int AnimationTimeMax = 5;

};

void PlayerSetting(Player& player);
void PlayerQuad(Player& player);

void DrawPlayer(Player& player);
