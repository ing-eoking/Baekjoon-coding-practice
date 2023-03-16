#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
deque<bool> dq[4];
void rot(int n, int d, vector<bool> &tf) {
	tf[n] = true;
	if (n < 3 && dq[n + 1][6]^dq[n][2] && !tf[n+1]) rot(n + 1, -d, tf);
	if (n > 0 && dq[n - 1][2]^dq[n][6] && !tf[n-1]) rot(n - 1, -d, tf);
	if (d == -1) {
		dq[n].push_back(dq[n].front());
		dq[n].pop_front();
	}
	else if (d == 1) {
		dq[n].push_front(dq[n].back());
		dq[n].pop_back();
	}

}

int main() {
	char buf[10];
	for (int i = 0; i < 4; i++) {
		scanf(" %s", buf);
		for(int j = 0; j < 8; j++) dq[i].push_back(buf[j] - '0');
	}
	int K, n, d;
	scanf("%d", &K);
	while (K--) {;
		scanf(" %d%d", &n, &d);
		vector<bool> tf(4);
		rot(n-1, d, tf);
	}
	int score = 0;
	for (int i = 0; i < 4; i++) score += dq[i].front() * (1 << i);
	printf("%d", score);


}
