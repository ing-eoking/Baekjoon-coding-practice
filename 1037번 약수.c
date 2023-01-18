#include<stdio.h>

int main() {
	int N, n, min = 1000001, max = 0;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &n);
		if (min > n) min = n;
		if (max < n) max = n;
	}
	printf("%d", min * max);
}
