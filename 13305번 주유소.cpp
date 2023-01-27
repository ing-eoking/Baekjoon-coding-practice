#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, n;
	scanf("%d", &N);
	vector<int> road(N-1);
	set<pair<int, int>> s;
	for(int i = 0; i < N - 1; i++) scanf("%d", &road[i]);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		s.insert({ n, i });
	}
	long long cost = 0;
	for (auto i : s) {
		for (int j = i.second; j < road.size(); j++) {
			if (road[j] == 0) break;
			cost += (long long)road[j] * i.first;
			road[j] = 0;
		}
		if (i.second == 0) break;
	}
	printf("%lld", cost);

}
