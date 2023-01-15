#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int N, x, y;
	scanf("%d", &N);
	multiset<pair<int, int>> s;
	while (N--) {
		scanf("%d%d", &x, &y);
		s.insert({ x,y });
	}
	for (auto i : s)
		printf("%d %d\n", i.first, i.second);
}
