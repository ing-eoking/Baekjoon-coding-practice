#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>

using namespace std;

const char color[6] = { 'w', 'y', 'r','o','g','b' };
int side[6][4] = { {2,4,3,5},{5,3,4,2},{0,5,1,4},{1,5,0,4},{3,1,2,0}, {3,0,2,1} };


void rotate(vector<string>& v, bool clock) {
	vector<string> temp = v;
	if (clock) {
		for (int i = 0; i < 3; i++) {
			temp[0][i] = v[2 - i][0];
			temp[2 - i][0] = v[2][2 - i];
			temp[2][2 - i] = v[i][2];
			temp[i][2] = v[0][i];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			temp[0][2-i] = v[2 - i][2];
			temp[2 - i][2] = v[2][i];
			temp[2][i] = v[i][0];
			temp[i][0] = v[0][2-i];
		}
	}
	v = temp;
}

int main() {
	int T;
	unordered_map<char, int> hash;
	hash.insert({ 'U', 0 });
	hash.insert({ 'D', 1 });
	hash.insert({ 'F', 2 });
	hash.insert({ 'B', 3 });
	hash.insert({ 'L', 4 });
	hash.insert({ 'R', 5 });
	scanf("%d", &T);
	while (T--) {
		int n, idx;
		char buf[3];
		scanf("%d", &n);
		vector<vector<string>> cube(6);
		deque<char*> rot[6];
		for (int i = 0; i < 6; i++)
			cube[i] = vector<string>(3, string(3, color[i]));
		for(int i = 0; i < 4; i++)
			for (int j = 0; j < 3; j++) {
				rot[0].push_back(&cube[side[0][i]][0][2 - j]);
				rot[1].push_back(&cube[side[1][i]][2][j]);
				if (i == 0) {
					rot[5].push_back(&cube[side[4][i]][j][0]);
					rot[4].push_back(&cube[side[5][i]][2 - j][2]);
				}
				else {
					rot[5].push_back(&cube[side[4][i]][2 - j][2]);
					rot[4].push_back(&cube[side[5][i]][j][0]);
				}
				switch (i) {
				case 0:
					rot[2].push_back(&cube[side[2][i]][2][j]);
					rot[3].push_back(&cube[side[3][i]][2][j]);
					break;
				case 1:
					rot[2].push_back(&cube[side[2][i]][j][0]);
					rot[3].push_back(&cube[side[3][i]][2-j][2]);
					break;
				case 2:
					rot[2].push_back(&cube[side[2][i]][0][2-j]);
					rot[3].push_back(&cube[side[3][i]][0][2-j]);
					break;
				case 3:
					rot[2].push_back(&cube[side[2][i]][2-j][2]);
					rot[3].push_back(&cube[side[3][i]][j][0]);
					break;
				}
			}
		while (n--) {
			scanf(" %s", buf);
			idx = hash[buf[0]];
			string cs;
			for (int i = 0; i < 12; i++) cs.push_back(*rot[idx][i]);
			if (buf[1] == '+') {
				rotate(cube[idx], true);
				for (int i = 0; i < 3; i++) {
					rot[idx].push_back(rot[idx].front());
					rot[idx].pop_front();
				}
				for (int i = 0; i < 12; i++) *rot[idx][i] = cs[i];
			}
			else {
				rotate(cube[idx], false);
				for (int i = 0; i < 3; i++) {
					rot[idx].push_front(rot[idx].back());
					rot[idx].pop_back();
				}
				for (int i = 0; i < 12; i++) *rot[idx][i] = cs[i];
			}
		}
		for (int i = 0; i < 3; i++) {
			printf("%s\n", cube[0][i].c_str());
		}
	}
}
