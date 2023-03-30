#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int dir[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int dir2[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };


int main() {
	int M, S;
	scanf("%d %d", &M, &S);
	vector<vector<vector<int>>> v(4, vector<vector<int>>(4)), temp;
	vector<vector<int>> smell(4, vector<int>(4));
	int fx, fy, d;
	while (M--) {
		scanf("%d %d %d", &fx, &fy, &d);
		v[fx - 1][fy - 1].push_back(d - 1);
	}
	pair<int, int> shark;
	scanf("%d %d", &shark.first, &shark.second);
	shark.first--;
	shark.second--;
	while (S--) {
		temp = v;
		vector<vector<vector<int>>> tt(4, vector<vector<int>>(4));
		
		for(int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < v[i][j].size(); k++) {
					bool mov = true;
					for (int a = 0; a < 8; a++) {
						int dd = (v[i][j][k] - a + 8) % 8;
						int r = i + dir[dd][0];
						int c = j + dir[dd][1];
						if (r >= 0 && r < 4 && c >= 0 && c < 4
							&& (r != shark.first || c != shark.second)
							&& smell[r][c] == 0) {
							mov = false;
							tt[r][c].push_back(dd);
							break;
						}
					}
					if (mov) tt[i][j].push_back(v[i][j][k]);
				}
			}
		v = tt;
		int _max = -1;
		vector<pair<int,int>> mmov;
		for (int a = 0; a < 4; a++) {
			int ar = shark.first + dir2[a][0], ac = shark.second + dir2[a][1];
			if (ar < 0 || ar >= 4 || ac < 0 || ac >= 4) continue;
			for (int b = 0; b < 4; b++) {
				int br = ar + dir2[b][0], bc = ac + dir2[b][1];
				if (br < 0 || br >= 4 || bc < 0 || bc >= 4) continue;
				for (int c = 0; c < 4; c++) {
					int cr = br + dir2[c][0], cc = bc + dir2[c][1];
					if (cr < 0 || cr >= 4 || cc < 0 || cc >= 4) continue;
					int fish = v[ar][ac].size() + v[br][bc].size()
						+ (c != (b + 2) % 4) * v[cr][cc].size();
					if (_max < fish) {
						_max = fish;
						mmov = { {ar, ac}, {br, bc}, {cr, cc} };
					}

				}
			}
		}
		for (auto i : mmov) {
			bool tf = !v[i.first][i.second].empty();
			v[i.first][i.second].clear();
			if(tf) smell[i.first][i.second] = 3;
		}
		shark = {mmov[2].first, mmov[2].second};
		for(int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (smell[i][j] > 0) smell[i][j]--;
				for (int k = 0; k < temp[i][j].size(); k++)
					v[i][j].push_back(temp[i][j][k]);
			}
	}
	int all = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			all += v[i][j].size();
	printf("%d", all);

}
