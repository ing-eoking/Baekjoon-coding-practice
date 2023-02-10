#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<string> map;

int dfs(int i, int j) {
	if (i < 0 || i >= map.size()) return 0;
	if (j < 0 || j >= map[0].length()) return 0;
	if (map[i][j] == '0') return 0;
	map[i][j] = '0';
	return dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1) + 1;

}

int main()
{
	int N;
	scanf("%d", &N);
	char buf[26];
	while (N--) {
		scanf("%s", buf);
		map.push_back(buf);
	}
	vector<int> result;
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].length(); j++) {
			if (map[i][j] == '1') result.push_back(dfs(i, j));
		}
	}
	printf("%d\n", result.size());
	sort(result.begin(), result.end());
	for (int i : result)
		printf("%d\n", i);
}
