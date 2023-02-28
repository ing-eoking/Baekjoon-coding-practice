#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<pair<int, int>, pair<int, int >> PII;

int main() {
	int N, W, a, b, mmin = 999999999;
	PII idx;
	scanf("%d %d", &N, &W);
	vector<map<PII, pair<int, PII>>> step(W + 1);
	pair<int, int> cur;
	vector<int> answer(W);
	vector<pair<int, int>> input(W);
	step[0][{ {1, 1}, { N, N } }] = { 0, {{0,0},{0,0}} };
	for (int i = 1; i <= W; i++) {
		scanf("%d%d", &cur.first, &cur.second);
		input[i - 1] = cur;
		for (auto j : step[i - 1]) {
			int dist = j.second.first + abs(cur.first - j.first.first.first) + abs(cur.second - j.first.first.second);
			PII temp = {cur, j.first.second };
			if (step[i][temp].first == 0 || step[i][temp].first > dist)
				step[i][temp] = { dist, j.first};
			if (i == W && mmin > dist) {
				mmin = dist;
				idx = temp;
			}
			temp = { j.first.first, cur };
			dist = j.second.first + abs(cur.first - j.first.second.first) + abs(cur.second - j.first.second.second);
			if (step[i][temp].first == 0 || step[i][temp].first > dist)
				step[i][temp] = { dist, j.first };
			if (i == W && mmin > dist) {
				mmin = dist;
				idx = temp;
			}
		}
	}
	printf("%d\n", step[W][idx].first);
	for (int i = W; i > 0; i--) {
		if (step[i][idx].second == idx) {
			if (input[i - 1] == idx.first) answer[i - 1] = 1;
			else answer[i - 1] = 2;
		}
		else if (step[i][idx].second.first == idx.first) answer[i - 1] = 2;
		else answer[i - 1] = 1;
		idx = step[i][idx].second;
	}
	for (int i = 0; i < W; i++) printf("%d\n", answer[i]);
}
