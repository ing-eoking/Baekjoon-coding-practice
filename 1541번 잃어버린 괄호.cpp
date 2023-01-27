#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int main() {
	char str[51];
	scanf("%s", str);
	istringstream is(str);
	string buf1, buf2;
	vector<int> v;
	while (getline(is, buf1, '-')) {
		int tsum = 0;
		istringstream tis(buf1);
		while (getline(tis, buf2, '+')) tsum += stoi(buf2);
		v.push_back(tsum);
	}
	int sum = v[0];
	for (int i = 1; i < v.size(); i++) sum -= v[i];
	printf("%d", sum);

}
