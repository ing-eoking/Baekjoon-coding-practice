#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *A;
int N, K, num = 0, answer = -1;
void merge(int p, int q, int r) {
	int i = p, j = q + 1, t = 1;
	int* tmp = (int*)malloc(sizeof(int) * (r+2));
	while (i <= q && j <= r)
		if (A[i] <= A[j]) tmp[t++] = A[i	++];
		else tmp[t++] = A[j++];
	while (i <= q) tmp[t++] = A[i++];
	while (j <= r) tmp[t++] = A[j++];
	i = p; t = 1;
	while (i <= r) {
		A[i++] = tmp[t++];
		if (++num == K) answer = A[i - 1];
	}
	free(tmp)
}
void merge_sort(int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(p, q);
		merge_sort(q + 1, r);
		merge(p, q, r);
	}
}

int main() {
	scanf("%d%d", &N, &K);
	A = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	merge_sort(0, N - 1);
	printf("%d", answer);
  free(A);
}
