#include <Novice.h>
#include <stdio.h>
#include "Map.h"
#include "Player.h"

const char kWindowTitle[] = "LC1A_28_ヨシダメイ";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, WinWidth, WinHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//マップ設定
	int map[MapHeight][MapWidth] = {};
	MapLoading(map);
	int mapTextureHandle = Novice::LoadTexture("white1x1.png");

	//マップの列
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	//マップの行
	int mapCountY = sizeof(map) / sizeof(map[0]);

	//プレイヤー
	Player player = {};
	PlayerSetting(player);

	Quad playerQuadMap = {};

	int speedTmp = 3;

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		/***** プレイヤー *****/
		PlayerQuad(player);//四角
		player.vel.y = 0;
		player.vel.x = 0;
		//マップチップ位置獲得
		playerQuadMap.leftTop.x = (player.pos.x - player.radius) / MapChipSize;
		playerQuadMap.leftTop.y = (player.pos.y - player.radius) / MapChipSize;
		playerQuadMap.rightTop.x = (player.pos.x + player.radius - 1) / MapChipSize;
		playerQuadMap.rightTop.y = (player.pos.y - player.radius - 1) / MapChipSize;
		playerQuadMap.leftBottom.x = (player.pos.x - player.radius) / MapChipSize;
		playerQuadMap.leftBottom.y = (player.pos.y + player.radius) / MapChipSize;
		playerQuadMap.rightBottom.x = (player.pos.x + player.radius - 1) / MapChipSize;
		playerQuadMap.rightBottom.y = (player.pos.y + player.radius - 1) / MapChipSize;

		if (keys[DIK_UP]) {
			playerQuadMap.leftTop.y = (player.pos.y - speedTmp - player.radius) / MapChipSize;
			playerQuadMap.rightTop.y = (player.pos.y - speedTmp - player.radius - 1) / MapChipSize;
			if (map[playerQuadMap.leftTop.y][playerQuadMap.leftTop.x] == none && map[playerQuadMap.rightTop.y][playerQuadMap.rightTop.x] == none) {
				player.vel.y = -speedTmp;
			}
		}
		else if (keys[DIK_RIGHT]) {
			playerQuadMap.rightTop.x = (player.pos.x + speedTmp + player.radius - 1) / MapChipSize;
			playerQuadMap.rightBottom.x = (player.pos.x + speedTmp + player.radius - 1) / MapChipSize;
			if (map[playerQuadMap.rightTop.y][playerQuadMap.rightTop.x] == none && map[playerQuadMap.rightBottom.y][playerQuadMap.rightBottom.x] == none) {
				player.vel.x = speedTmp;
			}
		}
		else if (keys[DIK_DOWN]) {
			playerQuadMap.leftBottom.y = (player.pos.y + speedTmp + player.radius) / MapChipSize;
			playerQuadMap.rightBottom.y = (player.pos.y + speedTmp + player.radius - 1) / MapChipSize;
			if (map[playerQuadMap.leftBottom.y][playerQuadMap.leftBottom.x] == none && map[playerQuadMap.rightBottom.y][playerQuadMap.rightBottom.x] == none) {
				player.vel.y = speedTmp;
			}
		}
		else if (keys[DIK_LEFT]) {
			playerQuadMap.leftTop.x = (player.pos.x - speedTmp - player.radius) / MapChipSize;
			playerQuadMap.leftBottom.x = (player.pos.x - speedTmp - player.radius) / MapChipSize;
			if (map[playerQuadMap.leftTop.y][playerQuadMap.leftTop.x] == none && map[playerQuadMap.leftBottom.y][playerQuadMap.leftBottom.x] == none) {
				player.vel.x = -speedTmp;
			}
		}

		player.pos.x += player.vel.x;
		player.pos.y += player.vel.y;

		/*
		player.mapNum.x = player.pos.x / MapChipSize;
		player.mapNum.y = player.pos.y / MapChipSize;

		//上に動く
		if (keys[DIK_W] && preKeys[DIK_W] == 0) {
			//仮に進ませる
			player.posTmp.y = player.pos.y - player.vel.y;
			player.mapNum.y = player.posTmp.y / MapChipSize;

			//何もないなら進ませる
			if (map[player.mapNum.y][player.mapNum.x] == none) {
				player.pos.y -= player.vel.y;
			}
		}
		//下
		if (keys[DIK_S] && preKeys[DIK_S] == 0) {
			//仮に進ませる
			player.posTmp.y = player.pos.y + player.vel.y;
			player.mapNum.y = player.posTmp.y / MapChipSize;

			//何もないなら進ませる
			if (map[player.mapNum.y][player.mapNum.x] == none) {
				player.pos.y += player.vel.y;
			}
		}
		//右
		if (keys[DIK_D] && preKeys[DIK_D] == 0) {
			//仮に進ませる
			player.posTmp.x = player.pos.x + player.vel.x;
			player.mapNum.x = player.posTmp.x / MapChipSize;

			//何もないなら進ませる
			if (map[player.mapNum.y][player.mapNum.x] == none) {
				player.pos.x += player.vel.x;
			}
		}
		//左
		if (keys[DIK_A] && preKeys[DIK_A] == 0) {
			//仮に進ませる
			player.posTmp.x = player.pos.x - player.vel.x;
			player.mapNum.x = player.posTmp.x / MapChipSize;

			//何もないなら進ませる
			if (map[player.mapNum.y][player.mapNum.x] == none) {
				player.pos.x -= player.vel.x;
			}
		}
		*/


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		//マップ描画
		DrawMap(mapTextureHandle, map);

		//プレイヤー描画
		DrawPlayer(player);

		Novice::ScreenPrintf(100, 40, "player.quad.leftTop.x / MapchipSize %d", player.quad.leftTop.x / MapChipSize);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
