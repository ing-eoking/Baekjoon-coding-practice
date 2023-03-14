#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, _max = 0;

void comb(vector<int>& v) {
	if (v.size() < 2) return;
	int st = 0, mov = 1, tmp;
	while (st != N - 1) {
		while (mov < N-1 && v[mov] == 0) mov++;
		tmp = v[mov];
		v[mov] = 0;
		if (v[st] == tmp) v[st++] += tmp;
		else if (v[st] == 0) v[st] = tmp;
		else v[++st] = tmp;
		if (st == mov) mov++;
	}
}


void dfs(vector<vector<int>> block, int num) {
	if (num == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (block[i][j] > _max) _max = block[i][j];
		return;
	}
	vector<int> temp;
	vector<vector<int>> v;
	for (int i = 0; i < N; i++) {
		temp = block[i];
		comb(temp);
		v.push_back(temp);
	}
	dfs(v, num + 1);
	for (int i = 0; i < N; i++) {
		temp = block[i];
		reverse(temp.begin(), temp.end());
		comb(temp);
		reverse(temp.begin(), temp.end());
		v[i] = temp;
	}
	dfs(v, num + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) temp[j] = block[j][i];
		comb(temp);
		for (int j = 0; j < N; j++) v[j][i] = temp[j];
	}
	dfs(v, num + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) temp[N-1-j] = block[j][i];
		comb(temp);
		for (int j = 0; j < N; j++) v[N-1-j][i] = temp[j];
	}
	dfs(v, num + 1);
}

int main() {
	scanf("%d", &N);
	vector<vector<int>> block(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &block[i][j]);
	dfs(block, 0);
	printf("%d", _max);
}
