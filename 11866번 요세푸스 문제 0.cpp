#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N, K;
	queue<int> q;
	bool tf = false;
	scanf("%d%d", &N, &K);
	printf("<");
	for (int i = 1; i <= N; i++) q.push(i);
	while (!q.empty()) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		if (tf) printf(", ");
		else tf = !tf;
		printf("%d", q.front());
		q.pop();
	}
	printf(">");


}
