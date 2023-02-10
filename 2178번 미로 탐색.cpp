#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int M, N;
vector<string> miro;
vector<vector<int>> dist;

const int mov[2] = { 1, -1 };

void dfs(int i, int j) {
	if (i > 0 && miro[i-1][j] == '1' && dist[i - 1][j] > dist[i][j] + 1) {
		dist[i - 1][j] = dist[i][j] + 1;
		dfs(i - 1, j);
	}
	if (i < N - 1 && miro[i + 1][j] == '1' && dist[i + 1][j] > dist[i][j] + 1) {
		dist[i + 1][j] = dist[i][j] + 1;
		dfs(i + 1, j);
	}
	if (j > 0 && miro[i][j - 1] == '1' && dist[i][j-1] > dist[i][j] + 1) {
		dist[i][j - 1] = dist[i][j] + 1;
		dfs(i, j - 1);
	}
	if (j < M - 1 && miro[i][j+1] == '1' && dist[i][j+1] > dist[i][j] + 1) {
		dist[i][j + 1] = dist[i][j] + 1;
		dfs(i, j + 1);
	}

}

int main()
{
	scanf("%d%d", &N, &M);
	char buf[101];
	dist = vector<vector<int>> (N, vector<int>(M, 9999999));
	dist[0][0] = 1;
	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		miro.push_back(buf);
	}
	dfs(0, 0);
	printf("%d", dist[N-1][M-1]);
}
