#include <stdio.h>

#define MAX(a,b) a > b ? a : b

int main() {
	int N, max = 0;
	scanf("%d", &N);
	int** arr = (int**)malloc(sizeof(int*) * (N+1));
	arr[0] = (int*)malloc(sizeof(int) * 2);
	arr[0][0] = arr[0][1] = 0;
	for (int i = 1; i <= N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (i+2));
		arr[i][0] = arr[i][i + 1] = 0;
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += MAX(arr[i - 1][j - 1], arr[i - 1][j]);
			if (i == N) max = MAX(arr[i][j], max);
		}
	}
	printf("%d\n", max);
}
