#include <iostream>
#include <set>

using namespace std;

int main() {
	int N, x, y;
	scanf("%d", &N);
	multiset<pair<int, int>> s;
	while (N--) {
		scanf("%d%d", &x, &y);
		s.insert({ y,x });
	}
	for (auto i : s)
		printf("%d %d\n", i.second, i.first);
}
