#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int N, K;
	scanf("%d%d", &N, &K);
	vector<pair<int, int>> pos(100001);
	queue<int> q;
	pos[N] = { 1,-1 };
	q.push(N);
	int cur, dist;
	while (true) {
		cur = q.front();
		q.pop();
		if (cur == K) break;
		dist = pos[cur].first + 1;
		if (cur > 0 && pos[cur - 1].first == 0) {
			pos[cur - 1] = { dist, cur };
			q.push(cur - 1);
		}
		if (cur < 100000 && pos[cur + 1].first == 0) {
			pos[cur + 1] = { dist, cur };
			q.push(cur + 1);
		}
		if (cur * 2 <= 100000 && pos[cur * 2].first == 0) {
			pos[cur * 2] = { dist, cur };
			q.push(cur * 2);
		}
	}
	vector<int> answer(pos[K].first);
	printf("%d\n", pos[K].first - 1);
	int idx = answer.size() - 1;
	while (cur != -1) {
		answer[idx--] = cur;
		cur = pos[cur].second;
	}
	for (int i : answer) printf("%d ", i);
}
