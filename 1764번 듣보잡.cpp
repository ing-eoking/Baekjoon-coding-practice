#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

int main() {
	int N, M;
	char str[21];
	scanf("%d%d", &N, &M);
	unordered_set<string> s;
	set<string> r;
	while (N--) {
		scanf("%s", str);
		s.insert(str);
	}
	while (M--) {
		scanf("%s", str);
		if (s.find(str) != s.end()) r.insert(str);
	}
	printf("%d\n", r.size());
	for (auto i : r) printf("%s\n", i.c_str());
}
