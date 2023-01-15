#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	char N[10];
	scanf("%s", N);
	sort(N, N + strlen(N), greater<>());
	printf("%s", N);

}
