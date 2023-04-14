#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main() {
	set<int> s;
	int N, child;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &child);
		auto it = s.insert(child).first;
		it++;
		if (it != s.end()) s.erase(it);
	}
	printf("%d", N - s.size());


}
