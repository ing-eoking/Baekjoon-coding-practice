#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hanoi(int n, int st, int ed) {
	if (n == 1) {
		printf("%d %d\n", st, ed);
		return;
	}
	hanoi(n - 1, st, 6 - st - ed);
	printf("%d %d\n", st, ed);
	hanoi(n - 1, 6 - st - ed, ed);
}

int main() {
	int N;
	scanf("%d", &N);
	printf("%d\n", (1 << N) - 1);
	hanoi(N, 1, 3);
}
