#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N, K, n;
	scanf("%d%d", &N, &K);
	vector<int> coin;
	while (N--) {
		scanf("%d", &n);
		if (n <= K) coin.push_back(n);
	}
	n = 0;
	for (int i = coin.size() - 1; K > 0 && i >= 0; i--) {
		n += K / coin[i];
		K %= coin[i];
	}
	printf("%d", n);
}
