#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	vector<int> dist(100001, -1);
	queue<int> q;
	dist[N] = 0;
	q.push(N);
	int u;
	while ((u = q.front()) != K) {
		q.pop();
		if (u > 0 && dist[u - 1] < 0) {
			q.push(u - 1);
			dist[u - 1] = dist[u] + 1;
		}
		if (u * 2 <= 100000 && dist[u * 2] < 0) {
			q.push(u * 2);
			dist[u * 2] = dist[u] + 1;
		}
		if (u < 100000 && dist[u + 1] < 0) {
			q.push(u + 1);
			dist[u + 1] = dist[u] + 1;
		}
	}
	printf("%d", dist[K]);

}
