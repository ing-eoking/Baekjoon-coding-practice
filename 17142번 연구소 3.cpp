#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> lab;
vector<pair<int, int>> virus;

int all = 0, N, M, mintime = 99999999;

void dfs(int st,int cur,vector<pair<int,int>>& vir) {
	if (vir.size() > cur) {
		for (int i = st; i < virus.size(); i++) {
			vir[cur] = virus[i];
			dfs(i + 1, cur + 1, vir);
		}
	}
	else {
		vector<vector<int>> l = lab;
		queue<pair<pair<int, int>,int>> q;
		int r, c, t, nums = 0, maxt = 0;
		for (int i = 0; i < vir.size(); i++) q.push({ vir[i],0 });
		while (!q.empty()) {
			r = q.front().first.first;
			c = q.front().first.second;
			t = q.front().second;
			q.pop();
			if (l[r][c] != 0 && l[r][c] != -1) continue;
			if (l[r][c] == 0) l[r][c] = t;
			else if (l[r][c] == -1) 
				l[r][c] = -2;
			if (++nums == all) {
				break;
			}
			if (r > 0 && (l[r - 1][c] ==0 || l[r-1][c] == -1)) q.push({ {r - 1,c}, t + 1 });
			if (r < N - 1 && (l[r + 1][c] == 0 || l[r+1][c] == -1)) q.push({ {r + 1,c}, t + 1 });
			if (c > 0 && (l[r][c - 1] == 0 || l[r][c-1] == -1)) q.push({ {r, c - 1}, t + 1 });
			if (c < N - 1 && (l[r][c + 1] == 0 || l[r][c+1] == -1)) q.push({ {r, c + 1}, t + 1 });
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (l[i][j] == 0) return;
				else if(lab[i][j] == 1) continue;
				else if (maxt < l[i][j]) maxt = l[i][j];
		if (mintime > maxt) mintime = maxt;


	}
}


int main() {
	scanf("%d%d", &N, &M);
	lab = vector<vector<int>>(N, vector<int>(N));
	for(int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &lab[i][j]);
			if (lab[i][j] != 1) all++;
			if (lab[i][j] == 2) {
				virus.push_back({ i,j });
				lab[i][j] = -1;
			}
		}
	vector<pair<int, int>> comb(M);
	dfs(0, 0, comb);
	if (mintime < 99999999)printf("%d", mintime);
	else printf("-1");
}
