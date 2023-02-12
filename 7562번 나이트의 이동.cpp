#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int T, I;
	scanf("%d", &T);
	int len[2][2] = { {2, 1}, {1, 2} };
	int calc[4][2] = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	while (T--) {
		scanf("%d", &I);
		vector<vector<int>> dist(I, vector<int>(I, -1));
		pair<int, int> knight, dest;
		queue<pair<int, int>> q;
		pair<int, int> u, temp;
		scanf("%d%d", &knight.first, &knight.second);
		scanf("%d%d", &dest.first, &dest.second);
		q.push(knight);
		dist[knight.first][knight.second] = 0;
		while ((u = q.front()) != dest) {
			q.pop();
			for (int i = 0; i < 4; i++) 
				for (int j = 0; j < 2; j++) {
					temp = { u.first + calc[i][0] * len[j][0], u.second + calc[i][1] * len[j][1] };
					if (temp.first >= 0 && temp.first < I && temp.second >= 0 && temp.second < I) 
						if (dist[temp.first][temp.second] < 0) {
							dist[temp.first][temp.second] = dist[u.first][u.second] + 1;
							q.push(temp);
						}
				}
		}
		printf("%d\n", dist[dest.first][dest.second]);
	}

}
