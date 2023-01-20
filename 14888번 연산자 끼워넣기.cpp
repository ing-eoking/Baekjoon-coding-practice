#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string calc[4] = { "+","-","*","/" };

int main() {
	int N,n, max = -1000000000, min = 1000000000;
	scanf("%d", &N);
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) scanf("%d", &v[i]);
	string s = "";
	for (int i = 0; i < 4; i++) {
		scanf("%d", &n);
		if (i != 2) while (n--) s += calc[i];
		else while (n--) s = calc[i] + s;
	}
	do {
		int cur = v[0];
		for (int i = 0; i < s.length(); i++)
		{
			switch (s[i]) {
			case '+': cur += v[i + 1]; break;
			case '-': cur -= v[i + 1]; break;
			case '/': cur /= v[i + 1]; break;
			case '*': cur *= v[i + 1]; break;
			}
		}
		if (cur > max) max = cur;
		if (cur < min) min = cur;
	} while (next_permutation(s.begin(), s.end()));
	printf("%d\n%d", max, min);
}
