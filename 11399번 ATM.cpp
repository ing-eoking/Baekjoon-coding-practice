#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, sum = 0, cur = 0;
	scanf("%d", &N);
	vector<int> v(N);
	while (N--) scanf("%d", &v[N]);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) sum += (cur += v[i]);
	printf("%d", sum);
}
