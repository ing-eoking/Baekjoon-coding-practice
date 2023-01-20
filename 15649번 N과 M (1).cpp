#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> v;
	set<vector<int>> s;
	for (int i = 1; i <= N; i++) v.push_back(i);
	do {
		s.insert(vector<int>(v.begin(), v.begin() + M));
	} while (next_permutation(v.begin(), v.end()));
	for (auto i : s) {
		for (int j = 0; j < i.size(); j++) printf("%d ", i[j]);
		printf("\n");
	}
}
