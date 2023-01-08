#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set<int> s;
int self(int n) {
	if (n > 10000) return 0;
	s.erase(self(n+n/1000+(n%1000)/100+(n%100)/10+n%10));
	return n;
}

int main() {
	for (int i = 1; i <= 10000; i++) s.insert(i);
	for (int i = 1; i <= 10000; i++) self(i);
	for (auto i : s)
		printf("%d\n", i);
	return 0;
}
