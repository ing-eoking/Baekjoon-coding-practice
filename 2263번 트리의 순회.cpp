#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> pos, post;

void front(int st, int ed, int piv) {
	if (st > ed) return;
	printf("%d ",post[piv]);
	int i = pos[post[piv]];
	front(st, i - 1, piv - ed + i - 1);
	front(i + 1,ed, piv - 1);
}

int main() {
	int N, num;
	scanf("%d", &N);
	post = vector<int>(N);
	pos = vector<int>(N + 1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		pos[num] = i;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &post[i]);
	}
	front(0, N - 1, N - 1);

}
