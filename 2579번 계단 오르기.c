#include <stdio.h>

#define MAX(a,b) (a > b) ? (a) : (b)

int* stair;
int* dp;

int main() {
	int N;
	scanf("%d", &N);
	stair = (int*)malloc(sizeof(int) * (N+1));
	memset(stair, 0, sizeof(stair));
	dp = (int*)malloc(sizeof(int) * (N+1));
	memset(dp, 0, sizeof(stair));
	for (int i = 1; i <= N; i++)
		scanf("%d", &stair[i]);
	for (int i = 1; i <= 2; i++) dp[i] = dp[i - 1] + stair[i];
	for (int i = 3; i <= N; i++) 
		dp[i] = stair[i] + (MAX(dp[i - 2], stair[i - 1] + dp[i - 3]));
	printf("%d\n", dp[N]);
}
