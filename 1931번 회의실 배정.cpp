#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, s, e;
	vector<pair<int, int>> v;
	vector<pair<int, int>> c;
	unsigned int is = 0;
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d", &s, &e);
		v.push_back({ e,s });
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		if (!c.empty() && c.back().first > i.second) continue;
		c.push_back(i);
	}
	printf("%d", c.size());
}
