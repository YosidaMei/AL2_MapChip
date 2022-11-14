#include <Novice.h>
#include <stdio.h>
#include "Map.h"
#include "Player.h"

//マップ読み込み
int  MapLoading(int map[MapHeight][MapWidth]) {

	FILE* fp = NULL;
	fopen_s(&fp, "./mapSample.csv", "rt");
	if (fp == NULL) {
		return 0;
	}
	int x = 0;
	int y = 0;
	while ((fscanf_s(fp, "%d,", &map[y][x])) != EOF && y < MapHeight && x < MapWidth) {
		if (x < MapWidth) {
			x++;
			if (x == MapWidth - 1) {
				fscanf_s(fp, "%d\n", &map[y][x]);
				x = 0;
				y++;
			}
		}
	}

	fclose(fp);

	return 0;

}

//マップの描画
void DrawMap(int& textureHandle, int map[MapHeight][MapWidth]) {

	for (int y = 0; y < MapHeight; y++) {
		for (int x = 0; x < MapWidth; x++) {
			if (map[y][x] == none) {
				Novice::DrawQuad(MapChipSize * x, MapChipSize * y,
					MapChipSize * (x + 1), MapChipSize * y,
					MapChipSize * x, MapChipSize * (y + 1),
					MapChipSize * (x + 1), MapChipSize * (y + 1),
					0, 0, MapChipSize, MapChipSize, textureHandle, 0x000000FF);
			}
			else {
				Novice::DrawQuad(MapChipSize * x, MapChipSize * y,
					MapChipSize * (x + 1), MapChipSize * y,
					MapChipSize * x, MapChipSize * (y + 1),
					MapChipSize * (x + 1), MapChipSize * (y + 1),
					0, 0, MapChipSize, MapChipSize, textureHandle, 0x888888FF);
			}
		}
	}
}

