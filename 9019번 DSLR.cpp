#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

inline int D(int n) { return (n * 2) % 10000;}
inline int S(int n) { return (n > 0) ? (n - 1) : (9999);}
inline int L(int n) { return (n * 10) % 10000 + n / 1000;}
inline int R(int n) { return n / 10 + (n % 10) * 1000;}

int main() {
	int T;
	scanf("%d", &T);	
	vector<vector<char>> answer;
	unordered_map<int, pair<int, char>> m;
	int A, B, cur, d, s, l, r, dist;
	while (T--) {
		scanf("%d%d", &A, &B);
		queue<int> q;
		q.push(A);
		m[A] = { -1, -1};
		while (true) {
			cur = q.front();
			q.pop();
			d = D(cur); s = S(cur); l = L(cur); r = R(cur);
			if (m[d].second == 0) {
				m[d] = {cur, 'D'};
				if (d == B) break;
				q.push(d);
			}
			if (m[s].second == 0) {
				m[s] = {cur, 'S'};
				if (s == B) break;
				q.push(s);
			}
			if (m[l].second == 0) {
				m[l] = {cur, 'L' };
				if (l == B) break;
				q.push(l);
			}
			if (m[r].second == 0) {
				m[r] = {cur, 'R' };
				if (r == B) break;
				q.push(r);
			}
		}
		cur = B;
		answer.push_back(vector<char>());
		while (cur != A) {
			answer[answer.size() - 1].push_back(m[cur].second);
			cur = m[cur].first;
		}
		m.clear();
	}
	for (int i = 0; i < answer.size(); i++) {
		for (int j = answer[i].size() - 1; j >= 0; j--) {
			printf("%c", answer[i][j]);
		}
		printf("\n");
	}
}
