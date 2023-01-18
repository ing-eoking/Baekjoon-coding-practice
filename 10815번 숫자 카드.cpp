#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	int N, M, num;
	unordered_set<int> s;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &num);
		s.insert(num);
	}
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &num);
		printf("%d ", s.find(num) != s.end());
	}
}
