#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	int R, C, T, air;
	scanf("%d%d%d", &R, &C, &T);
	vector<vector<int>> room(R, vector<int>(C));
	for(int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			scanf("%d", &room[i][j]);
			if (room[i][j] < 0) air = i;
		}
	vector<vector<int>> tu, tl;
	while (T--) {
		vector<vector<int>> tr(R, vector<int>(C));
		for (int i = 0; i < R; i++) 
			for (int j = 0; j < C; j++) 
				if (room[i][j] > 0) {
					int n = 0;
					if (i > 0 && room[i - 1][j] >= 0) { tr[i - 1][j] += room[i][j] / 5; n++; }
					if (j > 0 && room[i][j- 1] >= 0) { tr[i][j - 1] += room[i][j] / 5; n++; }
					if (i < R - 1 && room[i + 1][j] >= 0) 
					{ tr[i + 1][j] += room[i][j] / 5; n++; }
					if (j < C - 1 && room[i][j+1] >= 0) { tr[i][j + 1] += room[i][j] / 5; n++; }
					tr[i][j] -= (room[i][j] / 5) * n;
				}
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++) room[i][j] += tr[i][j];
		vector<vector<int>> upper(room.begin(), room.begin() + air);
		vector<vector<int>> lower(room.begin() + air, room.end());
		tu = upper;
		tl = lower;
		for (int i = 1; i < upper.size(); i++) {
			tu[i][0] = upper[i - 1][0];
			tu[upper.size() - 1 - i][C - 1] = upper[upper.size() - i][C - 1];
		}
		for (int i = 1; i < C; i++) {
			tu[upper.size() - 1][i] = upper[upper.size() - 1][i - 1];
			tu[0][C - 1 - i] = upper[0][C - i];
		}
		tu[upper.size() - 1][0] = -1;
		tu[upper.size() - 1][1] = 0;
		for (int i = 1; i < lower.size(); i++) {
			tl[i][C - 1] = lower[i - 1][C - 1];
			tl[lower.size() - 1 - i][0] = lower[lower.size() - i][0];
		}
		for (int i = 1; i < C; i++) {
			tl[0][i] = lower[0][i - 1];
			tl[lower.size() - 1][C - 1 - i] = lower[lower.size() - 1][C - i];
		}
		tl[0][0] = -1;
		tl[0][1] = 0;

		for (int i = 0; i < air; i++)
			for (int j = 0; j < C; j++) room[i][j] = tu[i][j];
		for (int i = air; i < R; i++)
			for (int j = 0; j < C; j++) room[i][j] = tl[i - air][j];
	}
	int sum = 0;
	for (int i = 0; i < R; i++) 
		for (int j = 0; j < C; j++)
			if (room[i][j] > 0) sum += room[i][j];
	printf("%d", sum);
}
