#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

char buf[101];

int main(){
	int N;
	scanf("%d", &N);
	vector<int> nums(N);
	scanf("%s", buf);
	string math(buf);
	stack<double> ret;
	for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
	for (char s : math) {
		if (s >= 'A' && s <= 'Z') ret.push((double)(nums[s - 'A']));
		else {
			double r = ret.top(); ret.pop();
			double l = ret.top(); ret.pop();
			if (s == '+') ret.push(l + r);
			else if (s == '-') ret.push(l - r);
			else if (s == '*') ret.push(l * r);
			else if (s == '/') ret.push(l / r);
		}
	}
	printf("%.2f", ret.top());

}
