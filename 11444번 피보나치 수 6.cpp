#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;
typedef vector<vector<LL>> VVec;
typedef vector<LL> Vec;

#define MOD 1000000007

VVec mult(const VVec& A, const VVec& B) {
	VVec C(2, Vec(2));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
	return C;
}

VVec divide(LL b, const VVec& A) {
	if (b == 1) return A;
	VVec temp = divide(b / 2, A);
	if (b % 2) return mult(mult(temp, temp), A);
	else return mult(temp, temp);
}


int main() {
	LL n;
	scanf("%llu", &n);
	VVec A({ {1,1},{1,0} });
	VVec result = divide(n, A);
	printf("%llu", result[0][1] % MOD);
}
