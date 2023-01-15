#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long long ULL;

int main() {
	int N, t=0;
	scanf("%d", &N);
	map<int, int> m;
	while (N--) {
		scanf("%d", &t);
		m[t]++;
	}
	for (auto i : m)
		while (i.second--) printf("%d\n", i.first);
}
