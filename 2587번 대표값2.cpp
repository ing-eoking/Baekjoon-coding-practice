#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int N =5, t=0, sum = 0;
	multiset<int> s;
	while (N--) {
		scanf("%d", &t);
		s.insert(t);
		sum += t;
	}
	vector<int> v(s.begin(), s.end());
	printf("%d\n", sum / 5);
	printf("%d", v[2]);

}
