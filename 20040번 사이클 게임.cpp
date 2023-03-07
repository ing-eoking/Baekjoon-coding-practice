#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int find(int r) {
	while (r != v[r]) r = v[r];
	return r;
}

int main() {
	int N, M, a, b, pa, pb, answer = 0;
	bool tf = true;
	scanf("%d%d", &N, &M);
	v = vector<int>(N);
	for (int i = 0; i < N; i++) v[i] = i;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &a, &b);
		if (tf) {
			pa = find(a);
			pb = find(b);
			if (pa == pb) {
				answer = i;
				tf = false;
			}
			else if (pa < pb) v[pb] = pa;
			else v[pa] = pb;
		}
	}
	printf("%d", answer);
}
