#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int N,k, t=0, sum = 0;
	scanf("%d%d", &N, &k);
	multiset<int> s;
	while (N--) {
		scanf("%d", &t);
		s.insert(t);
	}
	vector<int> v(s.begin(), s.end());
	printf("%d\n", v[v.size()-k]);

}
