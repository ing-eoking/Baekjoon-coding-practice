#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N, M;
	char str[21];
	scanf("%d%d", &N, &M);
	unordered_map<string, int> m;
	vector<string> v;
	while (N--) {
		scanf("%s", str);
		v.push_back(str);
		m[str] = v.size();
	}
	while (M--) {
		scanf("%s", str);
		if(isdigit(str[0])) printf("%s\n", v[stoi(str) - 1].c_str());
		else printf("%d\n", m[str]);
	}
}
