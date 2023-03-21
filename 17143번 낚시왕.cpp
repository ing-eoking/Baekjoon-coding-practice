#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

map<int, vector<int>> shark;

int main() {
	int R, C, M, id = 1;
	scanf("%d%d%d", &R, &C, &M);
	shark[0] = { 0,0,0,0,0 };
	vector<vector<int>> water(R, vector<int>(C));
	int r, c, s, d, z, sum = 0, DR = R- 1, DC = C - 1;
	while (M--) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		if (d == 1 || d == 2) s = s % ((R - 1) * 2);
		else s = s % ((C - 1) * 2);
		shark[z] = { r-1,c-1,s,d};
		water[r-1][c-1] = z;
	}
	for (int p = 0; p < C; p++) {
		for (int i = 0; i < R; i++) {
			if (water[i][p]) {
				sum += water[i][p];
				shark.erase(water[i][p]);
				water[i][p] = 0;
				break;
			}
		}
		vector<int> rm;
		for (auto i = shark.begin(); i != shark.end();) {
			vector<int> j = i->second;
			if(water[j[0]][j[1]] == i->first) water[j[0]][j[1]] = 0;
			if (j[3] == 1 || j[3] == 2) {
				int mov = (j[0] + j[2] +(j[3] == 1) * (R - 1 - j[0]) * 2) % ((R - 1) * 2);
				if (mov > R - 1) {
					shark[i->first][3] = 1;
					shark[i->first][0] = (R - 1) * 2 - mov;
				}
				else {
					shark[i->first][3] = 2;
					shark[i->first][0] = mov;
				}
			}
			else {
				int mov = (j[1] + j[2] +(j[3] == 4) * (C - 1 - j[1]) * 2) % ((C - 1) * 2);
				if (mov > C - 1) {
					shark[i->first][3] = 4;
					shark[i->first][1] = (C - 1) * 2 - mov;
				}
				else {
					shark[i->first][3] = 3;
					shark[i->first][1] = mov;
				}
			}
			int sr = shark[i->first][0], sc = shark[i->first][1];
			if (water[sr][sc] < i->first) shark.erase(water[sr][sc]);
			water[sr][sc] = i->first;
			i++;
		}
	}
	printf("%d", sum);
}
