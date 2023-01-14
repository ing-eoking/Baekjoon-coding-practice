#include <iostream>
#include <vector>

using namespace std;

#define MIN(a,b) a > b ? b : a

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v(N+2);
	v[3] = v[2] = 1;
	for (int i = 4; i <= N; i++) {
		int A = v[i - 1] + 1;
		if (i % 3 == 0) A = MIN(A, v[i / 3] + 1);
		if (i % 2 == 0) A = MIN(A, v[i / 2] + 1);
		v[i] = A;
	}

	printf("%d\n", v[N]);
}
