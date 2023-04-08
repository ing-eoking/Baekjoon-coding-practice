#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
vector<int*> mov;
int sr = 0, sc = 0, N = 0, M = 0, score = 0;

int dir[4][2] = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };

void print() {
	cout << endl;
	for (vector<int> i : v) {
		for (int j : i) cout << j << " ";
		cout << endl;
	}
}

void init() {
	int str = sr, stc = sc;
	int cur = -1;
	for (int m = 1; m <= N - 1; m++) {
		for (int i = 0; i < m; i++) {
			stc += cur;
			mov.push_back(&v[str][stc]);
		}
		cur *= -1;
		for (int i = 0; i < m; i++) {
			str += cur;
			mov.push_back(&v[str][stc]);
		}
	}
	for (int i = N - 2; i >= 0; i--) mov.push_back(&v[0][i]);
}

void pull() {
	for (int i = mov.size() - 1; i >= 0; i--) {
		if (*mov[i] == 0) {
			int cur = i;
			for (int j = i + 1; j < mov.size(); j++) {
				if (*mov[j] == 0) break;
				swap(*mov[cur], *mov[j]);
				cur = j;
			}
		}
	}
}

bool bomb() {
	bool tf = false;
	for (int i = 0; i < mov.size();) {
		int cur = *mov[i], st = i;
		if (cur == 0) break;
		while (i < mov.size() && *mov[i] == cur) i++;
		if (i - st >= 4) {
			tf = true;
			for (int j = st; j < i; j++)
				*mov[j] = 0;
			score += cur * (i - st);
		}

	}
	return tf;
}

void change() {
	vector<int> temp;
	for (int i = 0; i < mov.size();) {
		int cur = *mov[i], st = i;
		if (cur == 0) break;
		while (i < mov.size() && *mov[i] == cur) i++;
		temp.push_back(i - st);
		temp.push_back(cur);
	}
	while (temp.size() < mov.size()) temp.push_back(0);
	for (int i = 0; i < mov.size(); i++)
		*mov[i] = temp[i];
}

int main() {
	scanf("%d %d", &N, &M);
	sr = sc = N / 2;
	v = vector<vector<int>>(N, vector<int>(N));
	init();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &v[i][j]);
	while (M--) {
		int d, des;
		scanf("%d %d", &d, &des); d--;
		for (int i = 1; i <= des; i++)
			v[sr + dir[d][0] * i][sc + dir[d][1] * i] = 0;
		pull();
		while(bomb()) pull();
		change();
	}
	printf("%d", score);

}
