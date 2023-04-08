#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> hole;
char buf[11];
int N, M, mini = 999999999;
map<vector<string>, int> f;


void dfs(vector<string> &v, int cur) {
	if (cur > 10 || v[0][0] == 'B') return;
	if (f.find(v) == f.end()) f[v] = cur;
	else if (f[v] > cur) f[v] = cur;
	else return;
	if (v[0][0] == 'R') {
		if (mini > cur) mini = cur;
		return;
	}
	vector<string> l = v, r = v, u = v, d = v;
	for(int i = 1; i < N -1; i++)
		for (int j = 1; j < M - 1; j++)
			if (v[i][j] == 'B' || v[i][j] == 'R') {
				int k = j - 1;
				while (k > 0 && l[i][k] == '.') k--;
				if (l[i][k] == 'O') {
					l[i][j] = '.';
					if (l[0][0] != 'B') l[0][0] = v[i][j];
				}
				else swap(l[i][k + 1], l[i][j]);
				k = i - 1;
				while (k > 0 && u[k][j] == '.') k--;
				if (u[k][j] == 'O') {
					u[i][j] = '.';
					if (u[0][0] != 'B') u[0][0] = v[i][j];
				}
				else swap(u[k + 1][j], u[i][j]);
			}
	for (int i = N - 2; i > 0; i--)
		for (int j = M - 2; j > 0; j--)
			if (v[i][j] == 'B' || v[i][j] == 'R') {
				int k = j + 1;
				while (k < M - 1 && r[i][k] == '.') k++;
				if (r[i][k] == 'O') {
					r[i][j] = '.';
					if (r[0][0] != 'B') r[0][0] = v[i][j];
				}
				else swap(r[i][k - 1], r[i][j]);
				k = i + 1;
				while (k < N - 1 && d[k][j] == '.') k++;
				if (d[k][j] == 'O') {
					d[i][j] = '.';
					if (d[0][0] != 'B') d[0][0] = v[i][j];
				}
				else swap(d[k - 1][j], d[i][j]);
			}
	dfs(l, cur + 1);
	dfs(r, cur + 1);
	dfs(u, cur + 1);
	dfs(d, cur + 1);
}

int main() {
	scanf("%d %d", &N, &M);
	vector<string> v;
	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		v.push_back(buf);
	}
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			if (v[i][j] == 'O') {
				hole = { i, j };
				break;
			}
	dfs(v, 0);
	if (mini == 999999999) printf("-1");
	else printf("%d", mini);
}
