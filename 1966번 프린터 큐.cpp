#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
	int T, n;
	scanf("%d", &T);
	while (T--) {
		int N, O, o;
		map<int, int> pm;
		queue<pair<int,int>> q;
		scanf("%d%d", &N, &O);
		for (int i = 0; i < N; i++) {
			scanf("%d", &n);
			q.push({ i, 9-n });
			pm[9-n]++;
		}
		for (o = 1; o <= N; o++) {
			while (pm.begin()->first != q.front().second) {
				q.push(q.front());
				q.pop();
			}
			if (q.front().first == O) break;
			pm.begin()->second--;
			if (pm.begin()->second == 0) pm.erase(pm.begin());
			q.pop();
		}
		printf("%d\n", o);
	}


}
