#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

vector<LL> hist;

LL divide(LL st, LL size) {
	if (size == 1) return hist[st];
	LL mmax = max(divide(st, size / 2), divide(st + size / 2 + size % 2, size / 2));
	LL l = st + size / 2 - 1 + size % 2, r = st + size / 2, cur = 999999999;
	while (st <= l && r < st + size) {
		cur = min({ hist[r], hist[l], cur });
		mmax = max(mmax, cur * (r - l + 1));
		if (l == st) r++;
		else if (r == st + size - 1) l--;
		else if (hist[l - 1] < hist[r + 1]) r++;
		else l--;
	}
	return mmax;
}

int main() {
	LL N;
	while (true) {
		scanf("%llu", &N);
		if (N == 0) break;
		hist = vector<LL>(N);
		for (int i = 0; i < N; i++) scanf("%llu", &hist[i]);
		printf("%llu\n", divide(0, N));
	}
}
