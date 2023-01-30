#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>

#include <iostream>
#include <vector>

using namespace std;

int one = 0, zero = 0, mone = 0;

void div(int n, int y, int x, vector<vector<int>>& paper) {
	bool tf = true;
	int is = paper[y][x];
	for (int i = y; tf && i - y < n; i++)
		for (int j = x; tf && j - x <n; j++)
			if (is != paper[i][j]) tf = false;
	if (tf) {
		if (is == 0) zero++;
		else if (is == 1) one++;
		else mone++;
		return;
	}
	else {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				div(n / 3, y + n * i / 3, x + n * j / 3, paper);
		return;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<int>> paper(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) scanf("%d", &paper[i][j]);
	}
	div(N, 0, 0, paper);
	printf("%d\n%d\n%d", mone, zero, one);

}
