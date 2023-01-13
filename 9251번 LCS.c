#include <stdio.h>
#include <string.h>

#define MAX(a,b) a > b ? a : b

int main() {
	char A[1000], B[1000];
	scanf("%s%s", A, B);
	int NA = strlen(A)+1, NB = strlen(B)+1;
	int** arr = (int**)malloc(sizeof(int*) * (NB));
	for (int i = 0; i < NB; i++) {
		arr[i] = (int*)malloc(sizeof(int) * (NA));
		memset(arr[i], 0, sizeof(arr[i]));
	}
	int max = 0;
	for (int b = 1; b < NB; b++)
		for (int a = 1; a < NA; a++) {
			if (A[a - 1] == B[b - 1]) arr[b][a] = arr[b - 1][a - 1] + 1;
			else arr[b][a] = MAX(arr[b - 1][a], arr[b][a - 1]);
			if (arr[b][a] > max) max = arr[b][a];
		}
	printf("%d\n", max);
}
