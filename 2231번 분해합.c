#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, i;
	scanf("%d", &N);
	char str[10];
	for (i = 1; i <= N; i++) {
		sprintf(str, "%d", i);
		unsigned long long sum = i;
		for (int s = 0; s < strlen(str); s++) {
			sum += (unsigned long long)(str[s] - '0');
		}
		if (sum == (unsigned long long)N) break;
	}
	if (i == N+1) printf("0");
	else printf("%d", i);
}
