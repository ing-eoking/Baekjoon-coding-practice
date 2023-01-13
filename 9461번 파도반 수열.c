#include <stdio.h>

long long arr[101] = { 0,1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12,};

long long DP(int n) {
	if (arr[n]) return arr[n];
	return arr[n] = DP(n-2) + DP(n-3);
}

int main() {
	int T, N;
	scanf("%d", &T);
	while (T-- > 0) {
		scanf("%d", &N);
		printf("%lld\n", DP(N));
	}
}
