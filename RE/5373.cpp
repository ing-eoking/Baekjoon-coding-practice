#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

char buf[3];

vector<vector<string>> cube =
{
	{"www","www","www"}, //윗면
	{"yyy","yyy","yyy"}, //아랫면
	{"rrr","rrr","rrr"}, //앞면
	{"ooo","ooo","ooo"}, //뒷면
	{"ggg","ggg","ggg"}, //왼쪽면
	{"bbb","bbb","bbb"}, //오른쪽면
};

deque<char*> L = {&cube[0][0][0], &cube[0][1][0], &cube[0][2][0],
				&cube[2][0][0], &cube[2][1][0],&cube[2][2][0], 
				& cube[1][0][0],& cube[1][1][0],& cube[1][2][0], 
				& cube[3][2][0],& cube[3][1][0],& cube[3][0][0] };
deque<char*> R = { &cube[0][2][2], &cube[0][1][2], &cube[0][0][2],
				&cube[3][0][2], &cube[3][1][2],&cube[3][2][2],
				&cube[1][2][2],&cube[1][1][2],&cube[1][0][2],
				&cube[2][2][2],&cube[2][1][2],&cube[2][0][2] };
deque<char*> U = { &cube[4][0][2], &cube[4][0][1], &cube[4][0][0],
				&cube[3][0][0], &cube[3][0][1],&cube[3][0][2],
				&cube[5][0][2],&cube[5][0][1],&cube[5][0][0],
				&cube[2][0][2],&cube[2][0][1],&cube[2][0][0] };
deque<char*> D = { &cube[4][2][0], &cube[4][2][1], &cube[4][2][2],
				&cube[2][2][0], &cube[2][2][1],&cube[2][2][2],
				&cube[5][2][0],&cube[5][2][1],&cube[5][2][2],
				&cube[3][2][2],&cube[3][2][1],&cube[3][2][0], };
deque<char*> F = { &cube[0][2][0], &cube[0][2][1], &cube[0][2][2],
				&cube[5][0][0], &cube[5][1][0],&cube[5][2][0],
				&cube[1][0][2],&cube[1][0][1],&cube[1][0][0],
				&cube[4][2][2],&cube[4][1][2],&cube[4][0][2], };
deque<char*> B = { &cube[0][0][2], &cube[0][0][1], &cube[0][0][0],
				&cube[4][0][0], &cube[4][1][0],&cube[4][2][0],
				&cube[1][2][0],&cube[1][2][1],&cube[1][2][2],
				&cube[5][2][2],&cube[5][1][2],&cube[5][0][2], };

void print() {
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << cube[0][i] << endl;
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << cube[4][i] << " " << cube[2][i] << " " << cube[5][i] << " " << cube[3][i] << endl;
	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << cube[1][i] << endl;
}
void rotate(int s, bool clock) {
	vector<string> temp = cube[s];
	if (clock) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp[i][j] = cube[s][2 - j][i];
	}
	else {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				temp[i][j] = cube[s][j][2 - i];
	}
	cube[s] = temp;
}

int main() {
	int T;
	scanf("%d", &T);
	vector<vector<string>> bcube = cube;
	while (T--){
		int n;
		cube = bcube;
		scanf("%d", &n);
		while (n--) {
			
			scanf("%s", buf);
			vector<char> backup;
			switch (buf[0]) {
			case 'L':
				for (int i = 0; i < 12; i++) backup.push_back(*L[i]);
				if (buf[1] == '-') {
					rotate(4, false);
					for (int i = 0; i < 3; i++) {
						L.push_front(L.back());
						L.pop_back();
					}
				}
				else if (buf[1] == '+') {
					rotate(4, true);
					for (int i = 0; i < 3; i++) {
						L.push_back(L.front());
						L.pop_front();
					}
				}
				for (int i = 0; i < 12; i++)
					*L[i] = backup[i];
				break;
			case 'R':
				for (int i = 0; i < 12; i++) backup.push_back(*R[i]);
				if (buf[1] == '-') {
					rotate(5, false);
					for (int i = 0; i < 3; i++) {
						R.push_front(R.back());
						R.pop_back();
					}
				}
				else if (buf[1] == '+') {
					rotate(5, true);
					for (int i = 0; i < 3; i++) {
						R.push_back(R.front());
						R.pop_front();
					}
				}
				for (int i = 0; i < 12; i++)
					*R[i] = backup[i];
				break;
			case 'U':
				for (int i = 0; i < 12; i++) backup.push_back(*U[i]);
				if (buf[1] == '-') {
					rotate(0, false);
					for (int i = 0; i < 3; i++) {
						U.push_front(U.back());
						U.pop_back();
					}
				}
				else if (buf[1] == '+') {
					rotate(0, true);
					for (int i = 0; i < 3; i++) {
						U.push_back(U.front());
						U.pop_front();
					}
				}
				for (int i = 0; i < 12; i++)
					*U[i] = backup[i];
				break;

			case 'D':
				for (int i = 0; i < 12; i++) backup.push_back(*D[i]);
				if (buf[1] == '-') {
					rotate(1, false);
					for (int i = 0; i < 3; i++) {
						D.push_front(D.back());
						D.pop_back();
					}
				}
				else if (buf[1] == '+') {
					rotate(1, true);
					for (int i = 0; i < 3; i++) {
						D.push_back(D.front());
						D.pop_front();
					}
				}
				for (int i = 0; i < 12; i++)
					*D[i] = backup[i];
				break;
			case 'F':
				for (int i = 0; i < 12; i++) backup.push_back(*F[i]);
				if (buf[1] == '-') {
					rotate(2, false);
					for (int i = 0; i < 3; i++) {
						F.push_front(F.back());
						F.pop_back();
					}
				}
				else if (buf[1] == '+') {
					rotate(2, true);
					for (int i = 0; i < 3; i++) {
						F.push_back(F.front());
						F.pop_front();
					}
				}
				for (int i = 0; i < 12; i++)
					*F[i] = backup[i];
				break;
			case 'B':
				for (int i = 0; i < 12; i++) backup.push_back(*B[i]);
				if (buf[1] == '-') {
					rotate(3, true);
					for (int i = 0; i < 3; i++) {
						B.push_front(B.back());
						B.pop_back();
					}
				}
				else if (buf[1] == '+') {
					rotate(3, false);
					for (int i = 0; i < 3; i++) {
						B.push_back(B.front());
						B.pop_front();
					}
				}
				for (int i = 0; i < 12; i++)
					*B[i] = backup[i];
				break;
			}
		}
		for (int i = 0; i < 3; i++)
			printf("%s\n", cube[0][i].c_str());

	}
}
