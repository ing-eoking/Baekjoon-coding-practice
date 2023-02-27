#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int N, mmax = 0, imax = 0;
	scanf("%d", &N);
	vector<int> nums(N);
	vector<int> dp(N, -1);
	map<int, int> m;
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
		auto it = m.insert({ nums[i], m.size() + 1});
		if (it.second) {
			if (it.first != --m.end()) {
				dp[i] = (m[nums[i]] = (++it.first)->second);
				m.erase(it.first);
			}
			else dp[i] = m.size();
		}
	}
	int n = m.size();
	printf("%d\n", n);
	vector<int> answer(n);
	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == n) answer[(n--) - 1] = nums[i];
	}
	for (int i : answer) printf("%d ", i);
	printf("\n");
}
