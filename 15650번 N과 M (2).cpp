#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> v;
	set<set<int>> s;
	for (int i = 1; i <= N; i++) v.push_back(i);
	do {
		s.insert(set<int>(v.begin(), v.begin() + M));
	} while (next_permutation(v.begin(), v.end()));
	for (auto i : s) {
		for (auto j : i) printf("%d ", j);
		printf("\n");
	}
}
