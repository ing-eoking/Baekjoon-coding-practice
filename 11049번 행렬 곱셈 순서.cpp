#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> mat(N+1, { 0,0 });
	vector<vector<int>> mp(N+2, vector<int>(N+2, 0));
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &mat[i].first, &mat[i].second);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j + i <= N; j++) {
			mp[j][j + i] = 1000000000;
			for (int k = j; k <= j + i; k++) {
				mp[j][j + i] = min( mp[j][j + i],
					mp[j][k] + mp[k + 1][i + j] + mat[j].first * mat[k].second * mat[i + j].second);
			}
		}
	}
	printf("%d", mp[1][N]);
}
