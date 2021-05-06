#include<stdio.h>
#include<stdlib.h>

void initCode() {
	#ifndef A
  
    // For getting input from input.txt file
    freopen("D:/Codes/C/input.txt", "r", stdin);
  
    // Printing the Output to output.txt file
    freopen("D:/Codes/C/output.txt", "w", stdout);
  
	#endif
}

struct Node {
	int vertex;
	struct Node* next;
};

struct Graph {
	int numberOfVertices;
	int *visited;
	// 2D array for adjacency list
	struct Node** adjacencyLists;
};

// Depth First Search recursive Algorithm
void DFS(struct Graph* graph, int vertex) {
	struct Node* List = graph->adjacencyLists[vertex];
	struct Node* temp = List;

	graph->visited[vertex] = 1;
	printf("%d ", vertex);

	while (temp) {
		int connectedVertex = temp->vertex;
		if (graph->visited[connectedVertex] == 0)
			DFS(graph, connectedVertex);
		temp = temp->next;
	}
}

// Create a Node
struct Node* createNode(int vertex) {
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->vertex = vertex;
	newNode->next = NULL;
	return newNode;
}

// Create a Graph
struct Graph* createGraph(int vertices) {
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numberOfVertices = vertices;
	graph->adjacencyLists = malloc(vertices * sizeof(struct Node));
	graph->visited = malloc(vertices * sizeof(int));

	int i;
	for (i = 0; i < vertices; i++) {
		graph->adjacencyLists[i] = NULL;
		graph->visited[i] = 0;
	}

	return graph;
}

// Add edge
void addEdge(struct Graph* graph, int source, int destination) {
	// Add edge from source to detination
	struct Node* newNode = createNode(destination);
	newNode->next =  graph->adjacencyLists[source];
	graph->adjacencyLists[source] = newNode;

	// Add edge from destination to source
	newNode = createNode(source);
	newNode->next = graph->adjacencyLists[destination];
	graph->adjacencyLists[destination] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
	int v;
	for (v = 0; v < graph->numberOfVertices; ++v) {
		struct Node* temp = graph->adjacencyLists[v];
		printf("\nVertex %d: ", v);
		while (temp) {
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}
 
int main() {
	initCode();
	struct Graph* graph = createGraph(4);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 1);

	printf("\nThe graph is");
	printGraph(graph);

	printf("\nDepth First search is\n");
	DFS(graph, 1);
	return 0;
}