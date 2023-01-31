#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

const LL P = 1000000007;

LL fact(LL n) {
	LL num = 1;
	for (LL i = 1; i <= n; i++) num = (num * i) % P;
	return num;
}

LL divide(LL n, LL k) {
	if (k == 0) return 1;
	if (k == 1) return n;
	LL temp = divide(n, k / 2) % P;
	if (k % 2) return (temp * temp % P) * n % P;
	else return temp * temp % P;
}

int main() {
	LL N, K;
	scanf("%llu%llu", &N, &K);
	LL div1 = fact(N), div2 = fact(N - K) * fact(K) % P;
	printf("%llu", div1 * (divide(div2, P - 2) % P) % P);

}
