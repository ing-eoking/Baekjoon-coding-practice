#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	int* fib = (int*)malloc(sizeof(int) * (N + 1));
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i <= N; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	printf("%d", fib[N]);
}
