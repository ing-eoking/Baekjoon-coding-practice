#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, string> m;
unordered_map<string, int> nm;

inline string find(string root) {
	while (root != m[root]) root = m[root];
	return root;
}

int main() {
	int T, n;
	char buf1[21], buf2[21];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s %s", buf1, buf2);
			if (m.find(buf1) == m.end()) { m[buf1] = buf1; nm[buf1]++; }
			if (m.find(buf2) == m.end()) { m[buf2] = buf2; nm[buf2]++; }
			string pa = find(buf1), pb = find(buf2);
			if (pa == pb) printf("%d\n", nm[pa]);
			else if (pa < pb) {
				m[pb] = pa;
				nm[pa] += nm[pb];
				printf("%d\n", nm[pa]);
			}
			else {
				m[pa] = pb;
				nm[pb] += nm[pa];
				printf("%d\n", nm[pb]);
			}
		}
		m.clear();
		nm.clear();
	}
}
