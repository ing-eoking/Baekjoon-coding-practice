#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long LL;
LL A, B, C;
LL div(int B) {
	if (B == 0) return 1;
	if (B == 1) return A % C;
	LL temp = div(B / 2) % C;
	if (B % 2 == 0) return temp * temp % C;
	else return temp * temp % C * A % C;

}

int main() {
	scanf("%llu%llu%llu", &A, &B, &C);
	printf("%llu",div(B));
}
