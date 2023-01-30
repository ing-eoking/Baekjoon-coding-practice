#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>

#include <iostream>
#include <vector>

using namespace std;

string div(int n, int y, int x, vector<vector<bool>>& paper) {
	bool tf = true, is = paper[y][x];
	for (int i = y; tf && i - y < n; i++)
		for (int j = x; tf && j - x <n; j++)
			if (is != paper[i][j]) tf = false;
	if (tf) {
		if (is) return "1";
		else return "0";
	}
	else {
		string s = "(";
		s += div(n / 2, y, x, paper);
		s += div(n / 2, y, x + n / 2, paper);
		s += div(n / 2, y + n / 2, x, paper);
		s += div(n / 2, y + n / 2, x + n / 2, paper) + ")";
		return s;
	}
}

int main() {
	int N, n;
	char str[65];
	scanf("%d", &N);
	vector<vector<bool>> paper(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		scanf("%s", str);
		for (int j = 0; j < N; j++)
			paper[i][j] = (bool)(str[j] - '0');
	}
	
	printf("%s", div(N, 0, 0, paper).c_str());

}
