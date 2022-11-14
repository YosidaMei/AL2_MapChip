#include <Novice.h>
#include "Player.h"
#include "Map.h"

void PlayerSetting(Player& player) {
	player.posTmp.x = 0;
	player.posTmp.y = 0;
	player.pos.x = 48;
	player.pos.y = 80;
	player.mapNum.x = 0;
	player.mapNum.y = 0;
	player.vel.x = 0;
	player.vel.y = 0;

	player.HP = 3;
	player.isAlive = true;

	player.textureHandle = Novice::LoadTexture("white1x1.png");
	player.textureHandleNumber = 0;

	player.animationNumber = 0;//�A�j���[�V�����ԍ�
	player.animationTime = 0;//�A�j���[�V�����^�C��
	player.AnimationNumberMax = 3;
}

void PlayerQuad(Player& player) {
	//����
	player.quad.leftTop.x = player.pos.x - player.radius;
	player.quad.leftTop.y = player.pos.y - player.radius;
	//�E��
	player.quad.rightTop.x = player.pos.x + player.radius;
	player.quad.rightTop.y = player.pos.y - player.radius;
	//����
	player.quad.leftBottom.x = player.pos.x - player.radius;
	player.quad.leftBottom.y = player.pos.y + player.radius;
	//�E��
	player.quad.rightBottom.x = player.pos.x + player.radius;
	player.quad.rightBottom.y = player.pos.y + player.radius;

}

void DrawPlayer(Player& player) {
	Novice::DrawQuad(
		player.quad.rightTop.x, player.quad.rightTop.y,
		player.quad.leftTop.x, player.quad.leftTop.y,
		player.quad.rightBottom.x, player.quad.rightBottom.y,
		player.quad.leftBottom.x, player.quad.leftBottom.y,
		player.size * player.animationNumber, 0, player.size, player.size, player.textureHandle, 0xFFFFFFFF);
}