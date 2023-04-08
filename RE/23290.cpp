#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

int dir[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int sdir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

vector<vector<vector<int>>> v(4, vector<vector<int>>(4));
vector<vector<int>> smell(4, vector<int>(4));
vector<int> shark(2);

void print(vector<vector<vector<int>>> & arr) {
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << arr[i][j].size() << " ";
		cout << endl;
	}
}
void prints() {
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << smell[i][j] << " ";
		cout << endl;
	}
}

int main() {
	int M, S;
	scanf("%d%d", &M, &S);
	int r, c, d;
	while (M--) {
		scanf("%d%d%d", &r, &c, &d);
		r--; c--; d--;
		v[r][c].push_back(d);
	}
	scanf("%d%d", &shark[0], &shark[1]);
	shark[0]--; shark[1]--;
	while (S--) {
		vector<vector<vector<int>>> temp(4, vector<vector<int>>(4)), cpy = v;
		for(int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < v[i][j].size(); k++) {
					bool tf = true;
					for (int di = 0; di < 8; di++) {
						int dd = (v[i][j][k] - di + 8) % 8;
						int mr = i + dir[dd][0], mc = j + dir[dd][1];
						if (mr >= 0 && mr < 4 && mc >= 0 && mc < 4
							&& (mr != shark[0] || mc != shark[1])
							&& (smell[mr][mc] == 0)) {
							tf = false;
							temp[mr][mc].push_back(dd);
							break;
						}
					}
					if (tf) temp[i][j].push_back(v[i][j][k]);
				}
				
			}
		v = temp;
		int maxi = -1;
		vector<vector<int>> mov;
		for (int i = 0; i < 4; i++) {
			int ir = shark[0] + sdir[i][0], ic = shark[1] + sdir[i][1];
			if (ir < 0 || ir >= 4 || ic < 0 || ic >= 4) continue;
			for (int j = 0; j < 4; j++) {
				int jr = ir + sdir[j][0], jc = ic + sdir[j][1];
				if (jr < 0 || jr >= 4 || jc < 0 || jc >= 4) continue;
				for (int k = 0; k < 4; k++) {
					int kr = jr + sdir[k][0], kc = jc + sdir[k][1];
					if (kr < 0 || kr >= 4 || kc < 0 || kc >= 4) continue;
					int fish = v[ir][ic].size() + v[jr][jc].size() + v[kr][kc].size() * (ir != kr || ic != kc);
					if (fish > maxi) {
						maxi = fish;
						mov = { {ir, ic}, {jr, jc}, {kr, kc} };
					}
				}
			}
		}
		for (vector<int> i : mov) {
			if(v[i[0]][i[1]].size()) smell[i[0]][i[1]] = 3;
			v[i[0]][i[1]].clear();
		}
		shark[0] = mov[2][0];
		shark[1] = mov[2][1];
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (smell[i][j]) smell[i][j]--;
				v[i][j].insert(v[i][j].end(), cpy[i][j].begin(), cpy[i][j].end());
			}
	}
	int allf = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			allf += v[i][j].size();
	printf("%d", allf);
}
