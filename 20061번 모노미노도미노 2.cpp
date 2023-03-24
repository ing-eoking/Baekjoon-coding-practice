#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<vector<vector<bool>>> bg(2, vector<vector<bool>>(6, vector<bool>(4)));
vector<vector<vector<vector<bool>>>> tile
= { { {{1}}, {{1,1}}, {{1}, {1}}}, {{{1}}, {{1},{1}}, {{1,1}}} };

int main() {
	int N, t;
	int block[2];
	scanf("%d", &N);
	int score = 0;
	while (N--) {
		scanf("%d%d%d", &t, &block[1], &block[0]);
		t--;
		for (int i = 0; i < 2; i++) {
			int w = tile[i][t][0].size(), rm = 0, h;
			bool tf = true;
			
			for(h = 0; tf && h < 6; h+= tf)
				for(int j = 0; j < w; j++)
					if (bg[i][h][block[i] + j]) {
						tf = false;
						break;
					}
			h--;
			for (int r = 0; r < tile[i][t].size(); r++) {
				for (int c = 0; c < w; c++) {
					bg[i][h - r][block[i] + c] = true;
				}
			}
			for (auto it = bg[i].begin() + 2; it != bg[i].end();) {
				if ((*it)[0] && (*it)[1] && (*it)[2] && (*it)[3]) {
					score++;
					it = bg[i].erase(it);
					rm++;
				}
				else it++;
			}
			while (rm--) bg[i].insert(bg[i].begin(), { 0,0,0,0 });
			if (bg[i][0][0] || bg[i][0][1] || bg[i][0][2] || bg[i][0][3])
			{
				bg[i].pop_back();
				bg[i].pop_back();
				bg[i].insert(bg[i].begin(), { 0,0,0,0 });
				bg[i].insert(bg[i].begin(), { 0,0,0,0 });
			}
			else if (bg[i][1][0] || bg[i][1][1] || bg[i][1][2] || bg[i][1][3]) {
				bg[i].pop_back();
				bg[i].insert(bg[i].begin(), { 0,0,0,0 });
			}
		}
	}
	printf("%d\n", score);
	int num = 0;
	for (int n = 0; n < 2; n++)
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 4; j++)
				num += bg[n][i][j];
	printf("%d", num);
}
