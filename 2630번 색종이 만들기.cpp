#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> div(int n, int y, int x, vector<vector<bool>>& paper) {
	bool tf = true, is = paper[y][x];
	for (int i = y; tf && i - y < n; i++)
		for (int j = x; tf && j - x <n; j++)
			if (is != paper[i][j]) tf = false;
	if (tf) {
		if (is) return { 1,0 };
		else return { 0,1 };
	}
	else {
		pair<int, int> temp[4];
		temp[0] = div(n / 2, y, x, paper);
		temp[1] = div(n / 2, y + n / 2, x, paper);
		temp[2] = div(n / 2, y, x + n / 2, paper);
		temp[3] = div(n / 2, y + n / 2, x + n / 2, paper);
		return { temp[0].first + temp[1].first + temp[2].first + temp[3].first,
			temp[0].second + temp[1].second + temp[2].second + temp[3].second };
	}
}

int main() {
	int N, n;
	scanf("%d", &N);
	vector<vector<bool>> paper(N, vector<bool>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &n);
			paper[i][j] = (bool)n;
		}
	pair<int, int> answer = div(N, 0, 0, paper);
	printf("%d\n%d", answer.second, answer.first);

}
