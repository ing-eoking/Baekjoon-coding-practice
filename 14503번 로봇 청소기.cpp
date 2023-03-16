#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N, M;

int main() {
	scanf("%d%d", &N, &M);
	int r, c, d, cld = 0, num;
	scanf("%d%d%d", &r, &c, &d);
	vector<vector<bool>> area(N, vector<bool> (M));
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			scanf("%d", &num);
			area[i][j] = num;
		}
	vector<vector<bool>> clean = area;
	bool ed = true;
	int dr, dc;
	while (true) {
		if (!clean[r][c]) {
			clean[r][c] = true;
			cld++;
		}
		if (clean[r + 1][c] && clean[r - 1][c] && clean[r][c + 1] && clean[r][c - 1]) {
			dr = ((d + 1) % 2) * (-(d > 1) * 2 + 1);
			dc = (-d % 2) * (-(d > 1) * 2 + 1);
			if (area[r + dr][c + dc]) break;
			else {
				r += dr;
				c += dc;
			}
		}
		else {
			d = (d + 3) % 4;
			dr = -((d + 1) % 2) * (-(d > 1) * 2 + 1);
			dc = -(-d % 2) * (-(d > 1) * 2 + 1);
			if (!area[r + dr][c + dc] && !clean[r + dr][c + dc]) {
				r += dr;
				c += dc;
			}
		}
	}
	printf("%d", cld);

}
