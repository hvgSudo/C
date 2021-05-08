#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 5

void initCode() {
	#ifndef PrimsAlgorithm
		freopen("D:/Codes/C/inputC.txt", "r", stdin);
		freopen("D:/Codes/C/outputC.txt", "w", stdout);
	#endif
}

// Find vertex with minimum key value
int minKey(int key[], bool mstSet[]) {
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; ++i)
		if (mstSet[i] == false && key[i] < min)
			min = key[i], min_index = i;
	return min_index;
}

// Print MST 
int printMST(int parent[], int graph[V][V]) {
	printf("Edge \t Weight\n");
	int i;
	for (i = 1; i < V; ++i)
		printf("%d - %d \t %d \n", parent[i], i, graph[i][parent[i]]);
}

// Construct and print MST
void primMST(int graph[V][V]) {
	int parent[V];
	int key[V];
	bool mstSet[V];

	int i, count, v;
	for (i = 0; i < V; ++i)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;

	for (count = 0; count < V - 1; ++count) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (v = 0; v < V; ++v)
			if (graph[u][v] && mstSet[v] == false && 
				graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph);
}

// Main function
int main() {
	initCode();
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);
	return 0;
}