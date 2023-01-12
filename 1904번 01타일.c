#include <stdio.h>

int* arr;

int DP(int n) {
	if (n < 2) return 1;
	if (n == 2) return 2;
	if (arr[n]) return arr[n]%15746;
	return arr[n] = (DP(n - 1) + DP(n - 2))%15746;
}

int main() {
	int N;
	scanf("%d", &N);
	arr = (int*)malloc(sizeof(int) * (N + 1));
	memset(arr, 0, (N + 1) * sizeof(int));
	printf("%d\n", DP(N)%15746);
}
