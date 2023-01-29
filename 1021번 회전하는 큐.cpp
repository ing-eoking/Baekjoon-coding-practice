#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
	int N, M, n, answer = 0;
	deque<int> q;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) q.push_back(i);
	while (M--) {
		scanf("%d", &n);
		int dist = distance(q.begin(), find(q.begin(), q.end(), n));
		if (dist <= q.size()/2) {
			while (dist--) {
				q.push_back(q.front());
				q.pop_front();
				answer++;
			}
			q.pop_front();
		}
		else {
			dist = q.size() - dist;
			while (dist--) {
				q.push_front(q.back());
				q.pop_back();
				answer++;
			}
			q.pop_front();
		}

	}
	printf("%d", answer);
}
