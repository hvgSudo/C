#include<stdio.h>
#include<stdlib.h>

// Code to take input from a file and write output to a file
void initCode() {
	#ifndef adjacencyList
  
    // For getting input from input.txt file
    freopen("D:/Codes/C/inputC.txt", "r", stdin);
  
    // Printing the Output to output.txt file
    freopen("D:/Codes/C/outputC.txt", "w", stdout);
  
	#endif
}

struct Node {
	int vertex;
	struct Node* next;
};

struct Graph {
	int numberOfVertices;
	// 2D array for adjacency list
	struct Node** adjacencyLists;
};

// Create a Node
struct Node* createNode(int vertex) {
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->vertex = vertex;
	newNode->next = NULL;
	return newNode;
}

//Create a graph
struct Graph* createGraph(int vertices) {
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numberOfVertices = vertices;

	graph->adjacencyLists = malloc(vertices * sizeof(struct Node*));

	int i;
	for (i = 0; i < vertices; i++)
		graph->adjacencyLists[i] = NULL;

	return graph;
}

// Add edge
void addEdge(struct Graph* graph, int s, int d) {
	// from s to d
	struct Node* newNode = createNode(d);
	newNode->next = graph->adjacencyLists[s];
	graph->adjacencyLists[s] = newNode;

	// from d to s
	newNode = createNode(s);
	newNode->next = graph->adjacencyLists[d];
	graph->adjacencyLists[d] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
	int v;
	for (v = 0; v < graph->numberOfVertices; ++v) {
		struct Node* temp = graph->adjacencyLists[v];
		printf("\n Vertex %d: ", v);
		while (temp) {
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() { // Main Function
	initCode();
	struct Graph* graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 3);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 0);

 	printGraph(graph);
	return 0;
}