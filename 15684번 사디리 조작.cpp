#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;

bool tf = false;

void dfs(vector<vector<bool>>& w, int a, int b, int n) {
	if (n == 0) {
		for (int i = 1; i <= N; i++) {
			pair<int, int> cur = { 1, i };
			while (cur.first <= H) {
				if (w[cur.first][cur.second]) cur.second++;
				else if (w[cur.first][cur.second - 1]) cur.second--;
				cur.first++;
			}
			if (cur.second != i) {
				return;
			}
		}
		tf = true;
		return;
	}
	int j = 0;
	for (int i = a; i <= H; i++) {
		if (i == a) j = b;
		else j = 1;
		for (; j < N; j++) {
			if (w[i][j - 1] || w[i][j] || w[i][j + 1]) continue;
			w[i][j] = true;
			dfs(w, i, j, n - 1);
			w[i][j] = false;
			if (tf) return;
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &H);
	int a, b;
	tf = false;
	vector<vector<bool>> w(H+1, vector<bool>(N + 1, false));
	while (M--) {
		scanf("%d%d", &a, &b);
		w[a][b] = true;
	}
	int i;
	for (i = 0; i <= 3; i++) {
		dfs(w, 1, 1, i);
		if (tf) break;
	}
	if (tf) printf("%d", i);
	else printf("-1");


}
