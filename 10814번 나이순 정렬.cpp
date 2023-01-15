#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int main() {
	int N,n;
	char str[100];
	scanf("%d", &N);
	map<int, vector<string>> m;
	while (N--) {
		scanf("%d%s", &n,str);
		m[n].push_back(str);
	}
	for (auto i : m)
		for(auto j : i.second)
		printf("%d %s\n", i.first,j.c_str());
}
