#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int N, M, T, num, x, d, k;
	scanf("%d %d %d", &N, &M, &T);
	vector<deque<int>> circle(N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			circle[i].push_back(num);
		}
	while (T--) {
		scanf("%d%d%d", &x, &d, &k);
		for (int i = x - 1; i < N; i += x) {
			for (int j = 0; j < k; j++) {
				if (d) {
					circle[i].push_back(circle[i].front());
					circle[i].pop_front();
				}
				else {
					circle[i].push_front(circle[i].back());
					circle[i].pop_back();
				}
			}
		}
		vector<deque<int>> t = circle;
		int sum = 0, n = 0;
		bool eq = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j]) {
					sum += circle[i][j];
					n++;
					int l = (j + M - 1) % M, r = (j + 1) % M;
					if (circle[i][j] == circle[i][l]) t[i][j] = t[i][l] = eq = 0;
					if (circle[i][j] == circle[i][r]) t[i][j] = t[i][r] = eq = 0;
					if (i < N - 1 && circle[i][j] == circle[i + 1][j]) t[i][j] = t[i + 1][j] = eq = 0;
					if (i > 0 && circle[i][j] == circle[i - 1][j]) t[i][j] = t[i - 1][j] = eq = 0;
				}
			}
		}
		if (eq && n > 0) {
			double avg = (double)sum / n;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)
					if (circle[i][j]) {
						if ((double)circle[i][j] > avg) t[i][j]--;
						else if((double)circle[i][j] < avg) t[i][j]++;
					}
		}
		circle = t;
	}
	int ss = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			ss += circle[i][j];
	}
	printf("%d", ss);

}
