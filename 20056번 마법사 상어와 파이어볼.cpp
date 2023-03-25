#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dir[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

int main() {
	int N, M, K, r, c, m, s, d;
	scanf("%d %d %d", &N, &M, &K);
	vector<vector<vector<vector<int>>>> v(N, vector<vector<vector<int>>>(N));
	vector<vector<int>> fire;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d %d %d", &r, &c, &m, &s, &d);
		if(m > 0) v[r - 1][c - 1].push_back({ m,s,d });
	}
	for (int i = 0; i < K; i++) {
		vector<vector<vector<vector<int>>>> temp(N, vector<vector<vector<int>>>(N));
		for (int a = 0; a < N; a++) 
			for (int b = 0; b < N; b++) 
				if(!v[a][b].empty()){
					for (int k = 0; k < v[a][b].size(); k++) {
						r = (a + dir[v[a][b][k][2]][0] * v[a][b][k][1] + N*1000) % N;
						c = (b + dir[v[a][b][k][2]][1] * v[a][b][k][1] + N*1000) % N;
						temp[r][c].push_back(v[a][b][k]);
					}
				}
		v = temp;
		for(int a = 0; a < N; a++)
			for (int b = 0; b < N; b++)
				if (v[a][b].size() > 1) {
					int sm = 0, sv = 0;
					bool tf = false;
					for (int k = 0; k < v[a][b].size(); k++) {
						sm += v[a][b][k][0];
						sv += v[a][b][k][1];
						if (v[a][b][0][2] % 2 != v[a][b][k][2] % 2) tf = true;
					}
					sm /= 5;
					sv /= v[a][b].size();
					v[a][b].resize(0);
					if (sm > 0) {
						for (int k = 0; k < 4; k++) {
							v[a][b].push_back({sm, sv, k*2 + tf});
						}
					}
				}
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < v[i][j].size(); k++)
				sum += v[i][j][k][0];
	printf("%d", sum);
}
