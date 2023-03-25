#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N, K, turn, fix = 0;
	scanf("%d %d", &N, &K);
	deque<pair<int, bool>> c(2 * N);
	for (int i = 0; i < 2 * N; i++)
		scanf("%d", &c[i].first);

	for (turn = 1; true; turn++) {
		c.push_front(c.back());
		c.pop_back();
		c[N - 1].second = false;
		for (int i = N-2; i >= 0; i--) {
			if (c[i].second && !c[i + 1].second && c[i+1].first >= 1) {
				c[i + 1].first--;
				if (c[i + 1].first == 0) fix++;
				c[i].second = false;
				c[i + 1].second = true;
			}
		}
		c[N - 1].second = false;
		if (c[0].first != 0) {
			c[0].second = true;
			c[0].first--;
			if (c[0].first == 0) fix++;
		}
		if (fix >= K) break;
	}
	printf("%d", turn);
}
