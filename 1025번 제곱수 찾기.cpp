#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool isSQRT(int num) {
	int i = 0;
	while (i * i < num) i++;
	return i * i == num || num == 0;
}

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	char temp[10];
	vector<string> arr;
	int _max = -1;
	for (int i = 0; i < N; i++) {
		scanf("%s", temp);
		arr.push_back(temp);
	}
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			for (int a = -N+1; a < N; a++) 
				for (int b = -M+1; b < M; b++) {
					if (a == 0 && b == 0) {
						int c = arr[i][j] - '0';
						if (isSQRT(c) && _max < c) _max = c;
						continue;
					}
					string cur = "";
					int y = i, x = j;
					while (true) 
						if (y < 0 || y >= N || x < 0 || x >= M) break;
						else {
							cur += arr[y][x];
							int tt = stoi(cur);
							if (isSQRT(tt) && _max < tt) _max = tt;
							y += a;
							x += b;
						}
				}
	printf("%d", _max);
}
