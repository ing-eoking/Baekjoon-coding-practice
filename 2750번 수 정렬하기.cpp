#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int N, t=0;
	scanf("%d", &N);
	set<int> s;
	while (N--) {
		scanf("%d", &t);
		s.insert(t);
	}
	for (auto i : s)
		printf("%d\n", i);

}
