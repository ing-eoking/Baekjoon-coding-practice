#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ice;
vector<vector<bool>> visit;

int N;

int dfs(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N) return 0;
	if (visit[r][c] || ice[r][c] == 0) return 0;
	visit[r][c] = true;
	return dfs(r + 1, c) + dfs(r - 1, c) + dfs(r, c + 1) + dfs(r, c - 1) + 1;
}


int main() {
	int div, Q;
	scanf("%d%d", &N, &Q);
	N = 1 << N;
	ice = vector<vector<int>>(N, vector<int>(N));
	visit = vector<vector<bool>>(N, vector<bool>(N));
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%d", &ice[i][j]);
	while (Q--) {
		scanf("%d", &div);
		div = 1 << div;
		for(int i = 0; i < N; i+= div)
			for (int j = 0; j < N; j += div) {
				vector<vector<int>> temp(div, vector<int>(div));
				for(int r = 0; r < div; r++)
					for (int c = 0; c < div; c++)
						temp[r][c] = ice[i + div - 1 - c][j + r];

				for (int r = 0; r < div; r++)
					for (int c = 0; c < div; c++)
						ice[i + r][j + c] = temp[r][c];


			}
		vector<vector<int>> ti = ice;
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) {
				int melt = 0;
				if (i > 0 && ice[i - 1][j] > 0) melt++;
				if (i < N - 1 && ice[i + 1][j] > 0) melt++;
				if (j > 0 && ice[i][j - 1] > 0) melt++;
				if (j < N - 1 && ice[i][j + 1] > 0) melt++;
				if (melt < 3 && ice[i][j] > 0) ti[i][j]--;
			}
		ice = ti;
	}
	int sum = 0, _max = 0, sz;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (!visit[i][j] && ice[i][j] != 0) {
				sz = dfs(i, j);
				if (_max < sz) _max = sz;
			}
			sum += ice[i][j];
		}
	printf("%d\n%d", sum, _max);
}
