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

	const int size = 32;//�T�C�Y
	const int radius = size / 2;//���a
	
	Quad quad;//�l�p
	Vector2 pos;//�ʒu
	Vector2 posTmp;//���ʒu
	Vector2 mapNum;//�}�b�v�̈ʒu
	Vector2 vel;//���x
	int HP;//�̗�
	int isAlive;//�����Ă��邩
	int textureHandle;//�摜
	int textureHandleNumber = 0;//�e�N�X�`���n���h���i���o�[

	int animationNumber = 0;//�A�j�����������ڂ�
	int AnimationNumberMax = 0;//�A�j���̍ő喇��
	int animationTime = 0;
	const int AnimationTimeMax = 5;

};

void PlayerSetting(Player& player);
void PlayerQuad(Player& player);

void DrawPlayer(Player& player);
