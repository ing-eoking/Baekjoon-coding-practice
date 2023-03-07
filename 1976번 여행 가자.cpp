#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	int N, M, num;
	scanf("%d %d", &N, &M);
	vector<vector<bool>> v(N + 1, vector<bool>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		v[i][i] = true;
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num);
			v[j][i] = v[i][j] = v[j][i] | v[i][j] | num;
		}
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				v[i][j] = v[i][j] | (v[i][k] & v[k][j]);
	vector<int> plan(M);
	scanf("%d", &plan[0]);
	bool tf = true;
	for (int i = 1; i < M; i++) {
		scanf("%d", &plan[i]);
		if (!v[plan[i]][plan[i - 1]]) tf = false;
	}
	if (tf) printf("YES");
	else printf("NO");

}
