#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;

int dfs(vector<vector<int>>& map, int y, int x) {
	if (map[y][x] != 0) return 0;
	map[y][x] = 2;
	int num = 1;
	if (y > 0) num += dfs(map, y - 1, x);
	if (y < N - 1) num += dfs(map, y + 1, x);
	if (x > 0) num += dfs(map, y, x - 1);
	if (x < M - 1) num += dfs(map, y, x + 1);
	return num;
}

int main() {
	int safe = 0;
	scanf("%d%d", &N, &M);
	vector<vector<int>> m(N, vector<int>(M));
	set<pair<int, int>> virus;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);
			if (m[i][j] == 2) {
				virus.insert({ i,j });
				m[i][j] = 0;
			}
			if (m[i][j] != 1) safe++;
		}
	}
	vector<int> num(N * M);
	vector<bool> per(N * M);
	for (int i = 0; i < num.size(); i++) num[i] = i;
	per[N * M - 1] = per[N * M - 2] = per[N * M - 3] = true;
	int mmax = 0;
	bool tf = false;
	pair<int, int> tp;
	do {
		vector<vector<int>> temp = m;
		vector<pair<int, int>> point;
		tf = false;
		for (int i = 0; i < per.size(); i++) 
			if (per[i]) {
				tp = { num[i] / M, num[i] % M };
				if (virus.find(tp) != virus.end()) {
					tf = true; 
					break;
				}
				point.push_back(tp);
			}
		if (tf) continue;
		for (int i = 0; i < point.size(); i++)
			temp[point[i].first][point[i].second] = 1;
		int sum = 0;
		for (auto i : virus) {
			sum += dfs(temp, i.first, i.second);
		}
		if (mmax < safe - sum) {
			mmax = safe - sum;
		}
	} while (next_permutation(per.begin(), per.end()));

	printf("%d", mmax - 3);


}
