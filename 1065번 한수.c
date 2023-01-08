#include <stdio.h>
#include <stdint.h>

int isH(int n) {
	const int dif = (n % 100) / 10 - n % 10;
	while ((n /= 10) >= 10)
		if (dif != (n % 100) / 10 - n % 10) return 0;
	return 1;
}

int main() {
	int N, num = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) num += isH(i);
	printf("%d", num);
	return 0;
}
