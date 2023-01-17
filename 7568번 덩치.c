#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int arr[50][2];
	for (int i = 0; i < N; i++)
		scanf("%d%d", &arr[i][0], &arr[i][1]);
	for (int i = 0; i < N; i++) {
		int c = 0;
		for (int j = 0; j < N; j++)
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) c++;
		printf("%d ", c+1);
	}
}
