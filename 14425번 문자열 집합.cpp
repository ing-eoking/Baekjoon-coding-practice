#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	unordered_set<string> s;
	char str[501];
	int c = 0;
	while (N--) {
		scanf("%s", str);
		s.insert(str);
	}
	while (M--) {
		scanf("%s", str);
		if (s.find(str) != s.end()) c++;
	}
	printf("%d", c);
}
