#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int M, N, H, nums = 0, _max = 0;
	scanf("%d%d%d", &M, &N, &H);
	vector<vector<vector<int>>> tomato(H, vector<vector<int>>(N, vector<int>(M)));
	queue<pair<int, pair<int,int>>> q;
	pair<int, pair<int, int>> u;
	for(int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				scanf("%d", &tomato[k][i][j]);
				if (tomato[k][i][j] == 1) {
					q.push({ k,{i,j} });
					tomato[k][i][j] = 0;
				}
				else if (tomato[k][i][j] == 0) {
					tomato[k][i][j] = 2147483647;
					nums++;
				}
		}
	while (!q.empty()) {
		u = q.front();
		q.pop();
		if (_max < tomato[u.first][u.second.first][u.second.second]) 
			_max = tomato[u.first][u.second.first][u.second.second];
		if (u.second.first > 0 && tomato[u.first][u.second.first - 1][u.second.second] > tomato[u.first][u.second.first][u.second.second] + 1) {
			tomato[u.first][u.second.first - 1][u.second.second] = tomato[u.first][u.second.first][u.second.second] + 1;
			q.push({ u.first,{ u.second.first - 1, u.second.second } });
			nums--;
		}
		if (u.second.first < N - 1 && tomato[u.first][u.second.first + 1][u.second.second] > tomato[u.first][u.second.first][u.second.second] + 1) {
			tomato[u.first][u.second.first + 1][u.second.second] = tomato[u.first][u.second.first][u.second.second] + 1;
			q.push({ u.first, { u.second.first + 1, u.second.second } });
			nums--;
		}
		if (u.second.second > 0 && tomato[u.first][u.second.first][u.second.second - 1] > tomato[u.first][u.second.first][u.second.second] + 1) {
			tomato[u.first][u.second.first][u.second.second - 1] = tomato[u.first][u.second.first][u.second.second] + 1;
			q.push({ u.first ,{ u.second.first, u.second.second - 1 } });
			nums--;
		}
		if (u.second.second < M - 1 && tomato[u.first][u.second.first][u.second.second + 1] > tomato[u.first][u.second.first][u.second.second] + 1) {
			tomato[u.first][u.second.first][u.second.second + 1] = tomato[u.first][u.second.first][u.second.second] + 1;
			q.push({ u.first, { u.second.first, u.second.second + 1 } });
			nums--;
		}
		if (u.first > 0 && tomato[u.first - 1][u.second.first][u.second.second] > tomato[u.first][u.second.first][u.second.second] + 1) {
			tomato[u.first - 1][u.second.first][u.second.second] = tomato[u.first][u.second.first][u.second.second] + 1;
			q.push({ u.first - 1, u.second });
			nums--;
		}
		if (u.first < H - 1 && tomato[u.first + 1][u.second.first][u.second.second] > tomato[u.first][u.second.first][u.second.second] + 1) {
			tomato[u.first + 1][u.second.first][u.second.second] = tomato[u.first][u.second.first][u.second.second] + 1;
			q.push({ u.first + 1, u.second });
			nums--;
		}
	}
	if (nums) printf("-1", _max);
	else printf("%d", _max);
}
