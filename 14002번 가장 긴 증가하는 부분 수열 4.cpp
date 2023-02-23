#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, mmax = 0, imax = 0;
	scanf("%d", &N);
	vector<int> nums(N, 0);
	for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
	vector<vector<int>> dp(N, vector<int>());
	dp[0].push_back(0);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++)
			if (nums[i] > nums[j]) {
				if (dp[j].size() + 1 > dp[i].size()) dp[i] = dp[j];
				if (mmax < dp[i].size() + 1) {
					mmax = dp[i].size() + 1;
					imax = i;
				}
			}
		dp[i].push_back(i);
	}
	printf("%d\n", dp[imax].size());
	for (int i : dp[imax]) printf("%d ", nums[i]);
}
