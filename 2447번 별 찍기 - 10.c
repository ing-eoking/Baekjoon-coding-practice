#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void star(int i, int j, int n) {
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1) printf("%c", ' ');
	else if (n / 3) star(i, j,n / 3);
	else printf("%c", '*');
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			star(i, j, N);
		printf("\n");
	}

}
