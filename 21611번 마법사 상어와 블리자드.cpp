#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dir[4][2] = { {-1,0}, {1, 0}, {0,-1}, {0, 1} };

vector<int*> order;
vector<vector<int>> wall;
int N, score = 0;
void init() {
	int r, c, stx = N / 2, sty = N / 2, w = 1;
	int add[2][2] = { {0, -1}, {1, 0} };
	while (stx != 0 || sty != 0) {
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= w; j++) {
				r = stx + add[i][0] * j;
				c = sty + add[i][1] * j;
				if (r < 0 || r >= N || c < 0 || c >= N) {
					r = stx + add[i][0] * (j - 1);
					c = sty + add[i][1] * (j - 1);
					break;
				}
				order.push_back(&wall[r][c]);
			}
			stx = r;
			sty = c;
			if (stx == 0 && sty == 0) break;
			add[i][0] *= -1;
			add[i][1] *= -1;
		}
		w++;
	}
}
void move() {
	for (int i = order.size() - 1; i >= 0; i--) 
		if (*order[i] == 0) {
			for (int k = i + 1; k < order.size(); k++)
				if (*order[k] != 0)
					swap(*order[k - 1], *order[k]);
				else break;
		}
}
bool bomb() {
	int cur, sz;
	bool tf = false;
	for (int i = 0; i < order.size();) {
		cur = *order[i];
		for (sz = 0; i + sz < order.size(); sz++)
			if (*order[i + sz] != cur) break;
		if (cur != 0 && sz >= 4) {
			tf = true;
			score += cur * sz;
			for (int j = 0; j < sz; j++)
				*order[i + j] = 0;
		}
		i += sz;
	}
	return tf;
}
void change() {
	vector<int> temp;
	int cur, sz;
	for (int i = 0; i < order.size();) {
		cur = *order[i];
		for (sz = 0; i + sz < order.size(); sz++)
			if (*order[i + sz] != cur) break;
		if (cur != 0) {
			temp.push_back(sz);
			temp.push_back(cur);
		}
		i += sz;
	}
	while (temp.size() < order.size()) temp.push_back(0);
	while (temp.size() > order.size()) temp.pop_back();
	for (int i = 0; i < order.size(); i++)
		*order[i] = temp[i];

}

int main() {
	int M,d, s;
	scanf("%d %d", &N, &M);
	int center = N / 2;
	wall = vector<vector<int>> (N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &wall[i][j]);
	init();
	while (M--) {
		scanf("%d%d", &d, &s);
		d--;
		for (int i = 1; i <= s; i++)
			wall[center + dir[d][0] * i][center + dir[d][1] * i] = 0;
		move();
		while (bomb()) move();
		change();
	}
	printf("%d", score);

}
