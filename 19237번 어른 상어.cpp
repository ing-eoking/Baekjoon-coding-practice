#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main() {
	int N, M, K, time = 0, remain = 0;
	scanf("%d%d%d", &N, &M, &K);
	vector<vector<pair<int, int>>> water(N, vector<pair<int,int>>(N));
	vector<vector<pair<int, int>>> temp = water;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &water[i][j].first);
			if (water[i][j].first > 0) {
				water[i][j].first--;
				water[i][j].second = K;
			}
		}
	vector<int> sd(M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &sd[i]);
		sd[i]--;
	}
	vector<vector<vector<int>>> pri(M, vector<vector<int>>(4, vector<int>(4)));
	for(int i = 0; i < M; i++)
		for(int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++) {
				scanf("%d", &pri[i][j][k]);
				pri[i][j][k]--;
			}
	for (time = 0; time <= 1000 ; time++) {
		map<int, pair<int, int>> shark;
		for(int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				if (water[i][j].second == K)
					shark[water[i][j].first] = { i, j };
			}
		if (shark.size() == 1) break;
		temp = water;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (temp[i][j].second > 0) temp[i][j].second--;
		for (auto i : shark) {
			int id = i.first, r = i.second.first, c = i.second.second;
			bool nemp = true;
			pair<int, int> go;
			for (int u = 0; u < 4; u++) {
				go = { r + dir[pri[id][sd[id]][u]][0], c + dir[pri[id][sd[id]][u]][1] };
				
				if (go.first >= 0 && go.first < N && go.second >= 0 && go.second < N
					&& water[go.first][go.second].second == 0) {
					sd[id] = pri[id][sd[id]][u];
					nemp = false;
					break;
				}
			}
			if (nemp) {
				for (int u = 0; u < 4; u++) {
					go = { r + dir[pri[id][sd[id]][u]][0], c + dir[pri[id][sd[id]][u]][1] };
					if (go.first >= 0 && go.first < N && go.second >= 0 && go.second < N
						&& water[go.first][go.second].first == id) {
						sd[id] = pri[id][sd[id]][u];
						break;
					}
				}
			}
			if (temp[go.first][go.second].second != K) {
				temp[go.first][go.second] = { id, K };
			}
		}	
		water = temp;


	}
	if (time <= 1000) printf("%d", time);
	else printf("-1");
}
