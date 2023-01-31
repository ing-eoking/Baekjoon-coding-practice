#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;
typedef vector<vector<LL>> VVec;
typedef vector<LL> Vec;

int N;

VVec mult(const VVec& A, const VVec& B) {
	VVec C(N, Vec(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 1000;
	return C;
}

VVec divide(LL b, const VVec& A) {
	if (b == 1) return A;
	VVec temp = divide(b / 2, A);
	if (b % 2) return mult(mult(temp, temp), A);
	else return mult(temp, temp);
}


int main() {
	LL B;
	scanf("%d%llu", &N, &B);
	VVec A(N, Vec(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) scanf("%d", &A[i][j]);
	VVec result = divide(B, A);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) printf("%d ", result[i][j] % 1000);
		printf("\n");
	}
}
