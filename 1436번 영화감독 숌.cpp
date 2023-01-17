#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	string s;
	scanf("%d", &N);
	for (int i = 1; N > 0; i++)
		if ((s = to_string(i)).find("666") != string::npos) N--;
	printf("%s", s.c_str());
}
