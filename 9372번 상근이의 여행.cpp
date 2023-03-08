#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, M, a, b;
		scanf("%d%d", &N, &M);
		for (int i = 1; i <= M; i++) scanf("%d%d", &a, &b);
		printf("%d\n", N - 1);
	}
}
