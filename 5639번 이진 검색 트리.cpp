#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree;

void front(int st, int ed) {
	if (st >= ed) return;
	if (st == ed - 1) {
		printf("%d\n", tree[st]);
		return;
	}
	int piv = upper_bound(tree.begin() + st+1, tree.begin() + ed, tree[st]) - tree.begin();
	front(st+1, piv);
	front(piv, ed);
	printf("%d\n", tree[st]);

}

int main() {
	int num;
	while(scanf("%d", &num) != EOF) {
		tree.push_back(num);
	}

	front(0, tree.size());

}
