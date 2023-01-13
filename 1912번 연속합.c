#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	long long cur, sum = 0, max_sum = -99999;
	while (n--) {
		scanf("%lld", &cur);
		sum += cur;
		if (max_sum < sum) max_sum = sum;
		if (sum < 0) sum = 0;
	}
	printf("%lld\n", max_sum);
}
