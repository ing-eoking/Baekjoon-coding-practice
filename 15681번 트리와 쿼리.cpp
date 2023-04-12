#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> connect, childNode;
vector<int> parentNode, sizeNode;

void makeTree(int currentNode, int parent) {
	for(int Node : connect[currentNode])
		if (Node != parent) {
			childNode[currentNode].push_back(Node);
			parentNode[Node] = currentNode;
			makeTree(Node, currentNode);
		}
}
void countSubtreeNodes(int currentNode) {
	sizeNode[currentNode] = 1;
	for (int Node : childNode[currentNode]) {
		countSubtreeNodes(Node);
		sizeNode[currentNode] += sizeNode[Node];
	}
}


int main() {
	int N, R, Q;
	scanf("%d%d%d", &N, &R, &Q);
	childNode = connect = vector<vector<int>>(N);
	sizeNode  = parentNode = vector<int>(N);
	int U, V;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d", &U, &V);
		U--; V--;
		connect[U].push_back(V);
		connect[V].push_back(U);
	}
	makeTree(R-1, -1);
	countSubtreeNodes(R-1);
	for (int i = 0; i < Q; i++) {
		scanf("%d", &U); U--;
		printf("%d\n", sizeNode[U]);
	}
}
