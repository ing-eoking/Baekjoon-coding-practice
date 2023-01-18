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
	while (N--) {
		scanf("%s", str);
		s.insert(str);
	}
	while (M--) {
		scanf("%s", str);
		if (!s.insert(str).second) s.erase(str);
	}
	printf("%d\n", s.size());
}
