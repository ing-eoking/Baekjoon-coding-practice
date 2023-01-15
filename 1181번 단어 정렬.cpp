#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int main() {
	int N;
	char str[50];
	scanf("%d", &N);
	map<int, set<string>> m;
	while (N--) {
		scanf("%s", str);
		m[strlen(str)].insert(str);
	}
	for (auto i : m)
		for(auto j : i.second)
			printf("%s\n", j.c_str());
}
