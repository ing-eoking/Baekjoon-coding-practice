#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rot(vector<vector<double>>& mp) {
	vector<vector<double>> temp = mp;
	for (int i = 0; i < mp.size(); i++)
		for (int j = 0; j < mp.size(); j++)
			temp[i][j] = mp[j][mp.size() - 1 - i];
	mp = temp;
}

int main() {
	int N, r, c;
	scanf("%d", &N);
	vector<vector<int>> tot(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &tot[i][j]);
	int stx = N / 2, sty = N / 2;
	int add[2][2] = { {0, -1}, {1,0} };
	vector<vector<double>> mp = { {0,0,0.02,0,0},
						{0,0.1,0.07,0.01,0},
						{0.05,0,0,0,0},
						{0,0.1,0.07,0.01,0},
						{0,0,0.02,0,0} };

	int w = 1;
	int idx = 1, waste = 0;
	while (stx != 0 || sty != 0) {
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= w; j++) {
				r = stx + add[i][0] * j;
				c = sty + add[i][1] * j;
				if (r < 0 || r >= N || c < 0 || c >= N) {
					r = stx + add[i][0] * (j - 1);
					c = sty + add[i][1] * (j - 1);
					break;
				}
				vector<vector<int>> wing(5, vector<int>(5));
				int tr = 2 + add[i][0], tc = 2 + add[i][1];
				wing[tr][tc] = tot[r][c];
				for (int a = 0; a < 5; a++)
					for (int b = 0; b < 5; b++)
						if (a != tr || b != tc) 
							wing[tr][tc] -= (wing[a][b] = (double)mp[a][b] * tot[r][c]);
				
				for(int a = -2; a< 3; a++)
					for (int b = -2; b < 3; b++) {
						if (r + a < 0 || r + a >= N || c + b < 0 || c + b >= N) {
							waste += wing[a + 2][b + 2];
							continue;
						}
						tot[r + a][c + b] += wing[a + 2][b + 2];
					}
				tot[r][c] = 0;

			}
			stx = r;
			sty = c;
			if (stx == 0 && sty == 0) break;
			add[i][0] *= -1;
			add[i][1] *= -1;
			rot(mp);
		}
		w++;
	}
	printf("%d", waste);
}
