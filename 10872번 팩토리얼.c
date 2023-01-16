#include <stdio.h>

typedef long long LL;

int main() {
	int N;
	scanf("%d", &N);
	LL fac = 1;
	for (int i = 1; i <= N; i++) fac *= i;
	printf("%d", fac);
}
