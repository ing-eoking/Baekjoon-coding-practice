#include <stdio.h>
#include <string.h>

#define MIN(a,b) a > b ? b : a

int main() {
	int N;
	scanf("%d", &N);
	int** arr = (int**)malloc(sizeof(int*) * (N+1));
	arr[0] = (int*)malloc(sizeof(int) * 3);
	memset(arr[0], 0, sizeof(int)*3);
	for (int i = 1; i <= N; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 3);
		scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
		arr[i][0] += MIN(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += MIN(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += MIN(arr[i - 1][0], arr[i - 1][1]);
	}
	printf("%d\n", MIN(arr[N][0],(MIN(arr[N][1],arr[N][2]))));
}
