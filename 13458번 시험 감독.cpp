#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;


int main() {
	int N, B, C;
	scanf("%d", &N);
	vector<long long> A(N);
	long long answer = N;
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	scanf("%d %d", &B, &C);
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			answer += (long long)(A[i] / C);
			if (A[i] % C > 0) answer++;
		}
	}
	printf("%lld", answer);

}
