#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, maxi = -1;
int in[50][9];

int main() {
	queue<int> roo;
	int sc, st, out;
	scanf("%d", &N);
	int pro[8] = { 1,2,3,4,5,6,7,8 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 9; j++) scanf("%d", &in[i][j]);
	do {
		int score[9] = { 0, };
		for (int i = 0; i < 3; i++) score[i] = pro[i];
		score[3] = 0;
		for (int i = 3; i < 8; i++) score[i + 1] = pro[i];
		sc = st = 0;
		for (int i = 0; i < N; i++) {
			out = 3;
			queue<int> roo;
			roo.push(0); roo.push(0); roo.push(0);
			while (out > 0) {
				int cur = in[i][score[st]];
				if (cur) {
					if (roo.front()) sc++;
					roo.pop(); roo.push(1);
					for (int j = 1; j < cur; j++)
					{
						if (roo.front()) sc++;
						roo.pop(); roo.push(0);
					}
				}
				else out--;
				st = (st + 1) % 9;
			}
		}
		if(maxi < sc) maxi = sc;
	} while (next_permutation(pro, pro + 8));
	printf("%d", maxi);
}
