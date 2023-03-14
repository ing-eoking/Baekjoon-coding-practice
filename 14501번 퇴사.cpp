#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> plan;

int dp(int st) {
	if (st > N - 1) return 0;
	return max(plan[st].second + dp(st + plan[st].first), dp(st + 1));
}

int main() {
	int t, p;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &t, &p);
		if (i + t > N) p = 0;
		plan.push_back({ t,p });
	}
	int answer = dp(0);
	printf("%d", answer);
}
