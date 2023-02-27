#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	char buf[1001];
	scanf("%s", buf);
	string A(buf);
	scanf("%s", buf);
	string B(buf);
	int NA = A.length() + 1, NB = B.length() + 1;
	vector<vector<int>> dp(NB, vector<int>(NA));
	for (int b = 1; b < NB; b++) {
		for (int a = 1; a < NA; a++) {
			if(A[a - 1] == B[b - 1]) dp[b][a] = dp[b - 1][a - 1] + 1;
			else dp[b][a] = max(dp[b - 1][a], dp[b][a - 1]);
		}
	}
	printf("%d\n", dp[--NB][--NA]);
	string answer = "";
	while (NA > 0 && NB > 0) {
		if (A[NA - 1] == B[NB - 1]) {
			answer += A[NA - 1];
			NA--;
			NB--;
		}
		else {
			if (dp[NB-1][NA] > dp[NB][NA-1]) NB--;
			else NA--;
		}
	}
	reverse(answer.begin(), answer.end());
	printf("%s", answer.c_str());
}
