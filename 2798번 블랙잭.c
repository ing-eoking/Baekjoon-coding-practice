#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, M;
	scanf("%d%d", &N, &M);
	int* card = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) scanf("%d", &card[i]);
	int min = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			if(i != j)
				for(int k = 0; k < N; k++)
					if (i != k && j != k) {
						int sum = card[i] + card[j] + card[k];
						if (M >= sum && M - sum < M - min)
							min = sum;
					}
	printf("%d", min);
}
