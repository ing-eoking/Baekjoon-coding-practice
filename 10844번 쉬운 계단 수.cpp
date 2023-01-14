#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

#define MOD 1000000000

int main() {
	int N;
	scanf("%d", &N);
	vector<vector<ULL>> v(N + 1, vector<ULL>(11, 0));
	for (int i = 1; i < 10; i++) v[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j > 0) v[i][j] += v[i - 1][j - 1] % MOD;
			v[i][j] += v[i - 1][j + 1] % MOD;
		}
	}
	ULL sum = 0;
	for (int i = 0; i < 10; i++) sum += v[N][i]%MOD;

	printf("%llu\n", sum%MOD);
}
