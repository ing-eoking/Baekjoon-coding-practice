#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ULL;

vector<vector<ULL>> dp;

int main() {
	int N, M, C;
	scanf("%d%d%d", &N, &M, &C);
	vector<vector<ULL>> W(C + 1, vector<ULL>(C + 1));
	for (int i = 1; i <= C; i++)
		for (int j = 1; j <= C; j++)
			scanf("%llu", &W[i][j]);
	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < M; i++) scanf("%d", &B[i]);
	dp = vector<vector<ULL>>(N + 1, vector<ULL>(M + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(W[A[N - i]][B[M - j]] + dp[i - 1][j - 1], dp[i - 1][j]);
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
		}
	}

	printf("%llu", dp[N][M]);

}
