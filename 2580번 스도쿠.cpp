#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sq(9, vector<int>(9));
vector<pair<int, int>> emp;

#define SS(a) (((int)(a/3))*3)

bool isC(int y, int x) {
	int sy = (SS(y)), sx = (SS(x));
	for (int i = 0; i < 9; i++) {
		if (i != y && sq[y][x] == sq[i][x])return false;
		if (i != x && sq[y][x] == sq[y][i])return false;
		if (sq[y][x] == sq[sy + i / 3][sx + i % 3])
			if(y != sy + i/3 && x != sx + i % 3) return false;
	}
	return true;
}
bool dfs(int n) {
	if (n == emp.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) printf("%d ", sq[i][j]);
			printf("\n");
		}
		return true;
	}
	
	int y = emp[n].first, x = emp[n].second;
	for (int i = 1; i <= 9; i++) {
		sq[y][x] = i;
		if (isC(y, x)) if(dfs(n + 1)) return true;
	}
	sq[y][x] = 0;
	return false;
}

int main() {
	int n;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &n);
			sq[i][j] = n;
			if (n == 0) emp.push_back({ i, j });
		}
	}
	dfs(0);
}
