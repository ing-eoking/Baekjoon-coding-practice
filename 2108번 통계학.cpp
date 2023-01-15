#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

bool com(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main() {
	int N, t=0;
	int sum =0;
	scanf("%d", &N);
	map<int, int> m;
	multiset<int> s;
	while (N--) {
		scanf("%d", &t);
		m[t]++;
		sum += t;
		s.insert(t);
	}
	N = s.size();
	vector<pair<int, int>> v(m.begin(), m.end());
	vector<int> vs(s.begin(), s.end());
	sort(v.begin(), v.end(), com);
	printf("%d\n", (int)round((double)sum/N));
	printf("%d\n", vs[vs.size() / 2]);
	if (v.size() > 1 && v[0].second == v[1].second) printf("%d\n", v[1].first);
	else printf("%d\n", v[0].first);
	printf("%d", vs[vs.size() - 1] - vs[0]);


}
