#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef long long LL;

using namespace std;

int main() {
	int N, n;
	scanf("%d", &N);
	vector<int> v;
	map<int, LL> m;
	while (N--) {
		scanf("%d", &n);
		v.push_back(n);
		m[n] = 0;
	}
	int a = 0;
	auto i = m.begin();
	while(i != m.end()) (i++)->second = a++;
	for (int i = 0; i < v.size(); i++) {
		printf("%d", m[v[i]]);
		if (i != v.size() - 1) printf(" ");
	}
}
