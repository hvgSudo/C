#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 10

void initCode() {
	#ifndef PrimsAlgorithm
	freopen("inputC.txt", "r", stdin);
	freopen("outputC.txt", "w", stdout);
	#endif
}

// initialize adjacency matrix
void initializeMatrix(int graph[][MAX], int vertices) {
	int i, j;
	for (i = 0; i < vertices; ++i)
		for (j = 0; j < vertices; ++j)
			graph[i][j] = 0;
}

// Add Edge
void addEdge(int graph[][MAX], int source, int destination, int weight) {
	graph[source][destination] = weight;
	graph[destination][source] = weight;
}

// Print graph
void printGraph(int graph[][MAX], int vertices) {
	int i, j;
	for (i = 0; i < vertices; ++i) {
		printf("%d: ", i);
		for (j = 0; j < vertices; ++j)
			printf("%d ", graph[i][j]);
		printf("\n");
	}
}

// Find vertex with minimum key value
int minKey(int key[], bool mstSet[], int vertices) {
	int min = INT_MAX, min_index;
	for (int i = 0; i < vertices; ++i)
		if (mstSet[i] == false && key[i] < min)
			min = key[i], min_index = i;
	return min_index;
}

// Print MST 
int printMST(int parent[], int graph[][MAX], int vertices) {
	printf("Edge \t Weight\n");
	int i;
	for (i = 1; i < vertices; ++i) 
		printf("%d - %d \t %d \n", parent[i], i, graph[i][parent[i]]);
}

// Construct and print MST
void primMST(int graph[][MAX], int vertices) {
	int parent[vertices];
	int key[vertices];
	bool mstSet[vertices];

	int i, count, v;
	for (i = 0; i < vertices; ++i)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;

	for (count = 0; count < vertices - 1; ++count) {
		int u = minKey(key, mstSet, vertices);
		mstSet[u] = true;
		for(v = 0; v < vertices; ++v)
			if (graph[u][v] && mstSet[v] == false && 
				graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph, vertices);
}

void printMenu() {
	printf("\n1. Create Graph");
	printf("\n2. Insert into the graph");
	printf("\n3. Print the graph");
	printf("\n4. Get minimum spanning tree using Prim's Algorithm");
	printf("\n5. Exit");
	printf("\nEnter your choice: ");
}

// Main function
int main() {
	initCode();
	int exit = 0;
	int choice, vertices, vertex, s, d, i, weight;
	int graph[MAX][MAX];
	while (exit != 1) {
		printMenu();
		scanf("%d", &choice);
		printf("%d\n", choice);
		switch(choice) {
			case 1:
				printf("\nHow many vertices do you want in the graph: ");
				scanf("%d", &vertices);
				printf("%d", vertices);
				initializeMatrix(graph, vertices);
				while(1) {
					printf("\nEnter -1 to stop");
					printf("\nSource: ");
					scanf("%d", &s);
					printf("%d", s);
					if (s == -1)
						break;
					printf("\nDestination: ");
					scanf("%d", &d);
					printf("%d", d);
					printf("\nWeight: ");
					scanf("%d", &weight);
					printf("%d", weight);
					addEdge(graph, s, d, weight);
				}
				printf("\n");
				break;
			case 2:
				while(1) {
					printf("\nEnter -1 to stop");
					printf("\nSource: ");
					scanf("%d", &s);
					printf("%d", s);
					if (s == -1)
						break;
					printf("\nDestination: ");
					scanf("%d", &d);
					printf("%d", d);
					printf("\nWeight: ");
					scanf("%d", &weight);
					printf("%d", weight);
					addEdge(graph, s, d, weight);
				}
				printf("\n");
				break;
			case 3:
				printf("\nThe Adjacency Matrix of the graph is \n");
				printGraph(graph, vertices);
				break;
			case 4:
				primMST(graph, vertices);
				break;
			case 5:
				exit = 1;
				break;
			default:
				printf("\nWrong choice");
		}
	}
	/*int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);*/
	return 0;
}