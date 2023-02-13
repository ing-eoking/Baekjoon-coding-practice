#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main()
{
	int K;
	scanf("%d", &K);
	while (K--) {
		int V, E, u, v;
		bool tf = true;
		scanf("%d%d", &V, &E);
		vector<vector<int>> vtx(V + 1);
		vector<bool> visit(V + 1);
		set<int> edge,s[2];
		for(int i = 0; i < E; i++){
			scanf("%d%d", &u, &v);
			vtx[u].push_back(v);
			vtx[v].push_back(u);
			edge.insert(v);
			edge.insert(u);
		}
		queue<pair<int,int>> q;
		pair<int, int> idx;
		while (!edge.empty() && tf) {
			if (q.empty()) {
				while (!edge.empty() &&visit[*edge.begin()]) edge.erase(*edge.begin());
				if (edge.empty()) break;
				q.push({ *edge.begin(), 0 });
				edge.erase(*edge.begin());
			}
			idx = q.front();
			q.pop();
			visit[idx.first] = true;
			s[idx.second].insert(idx.first);
			for (int i : vtx[idx.first]) {
				if (s[idx.second].find(i) != s[idx.second].end()) {
					tf = false;
					break;
				}
				else {
					if (!vtx[i].empty()) {
						s[(idx.second + 1) % 2].insert(i);
						q.push({ i, (idx.second + 1) % 2 });
					}
				}
			}
			vtx[idx.first].clear();
		}
		if (tf) printf("YES\n");
		else printf("NO\n");
	}

}
