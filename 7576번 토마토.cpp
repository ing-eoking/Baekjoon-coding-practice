#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int M, N, nums = 0, _max = 0;
	scanf("%d%d", &M, &N);
	vector<vector<int>> tomato(N, vector<int>(M));
	queue<pair<int,int>> q;
	pair<int, int> u;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				q.push({ i,j });
				tomato[i][j] = 0;
			}
			else if (tomato[i][j] == 0) {
				tomato[i][j] = 2147483647;
				nums++;
			}
		}
	while (!q.empty()) {
		u = q.front();
		q.pop();
		if (_max < tomato[u.first][u.second]) _max = tomato[u.first][u.second];
		if (u.first > 0 && tomato[u.first - 1][u.second] > tomato[u.first][u.second] + 1) {
			tomato[u.first - 1][u.second] = tomato[u.first][u.second] + 1;
			q.push({ u.first - 1, u.second });
			nums--;
		}
		if (u.first < N - 1 && tomato[u.first + 1][u.second] > tomato[u.first][u.second] + 1) {
			tomato[u.first + 1][u.second] = tomato[u.first][u.second] + 1;
			q.push({ u.first + 1, u.second });
			nums--;
		}
		if (u.second > 0 && tomato[u.first][u.second - 1] > tomato[u.first][u.second] + 1) {
			tomato[u.first][u.second - 1] = tomato[u.first][u.second] + 1;
			q.push({ u.first, u.second - 1 });
			nums--;
		}
		if (u.second < M - 1 && tomato[u.first][u.second + 1] > tomato[u.first][u.second] + 1) {
			tomato[u.first][u.second + 1] = tomato[u.first][u.second] + 1;
			q.push({ u.first, u.second + 1 });
			nums--;
		}
	}
	if (nums) printf("-1", _max);
	else printf("%d", _max);
}
