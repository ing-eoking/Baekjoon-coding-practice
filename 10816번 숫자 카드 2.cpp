#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int N, t;
	scanf("%d", &N);
	unordered_map<int, int> m;
	while (N--) {
		scanf("%d", &t);
		m[t]++;
	}
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &t);
		printf("%d ", m[t]);
	}
}
