#include<stdio.h>
#include<stdlib.h>

/*void initCode() {
	#ifndef A
 	// For getting input from input.txt file
    freopen("D:/Codes/C/inputC.txt", "r", stdin);
  
    // Printing the Output to output.txt file
    freopen("D:/Codes/C/outputC.txt", "w", stdout);
  
	#endif
}*/

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
	int i;
	for (i = 0; i < graph->numberOfVertices; ++i) {
		struct Node* temp = graph->adjacencyLists[i];
		printf("\nVertex %d: ", i);
		while (temp) {
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

void printMenu() {
	printf("\n1. Create the graph");
	printf("\n2. Insert into the graph"); 
	printf("\n3. Print the graph");
	printf("\n4. Depth First Search");
	printf("\n5. Exit");
	printf("\nEnter your choice: ");
}
 
// Main method
int main() { 
	// initCode();
	int exit = 0, stop;
	int choice, vertices, vertex, s, d, i;
	struct Graph* graph;
	while (exit != 1) {
		stop = 0;
		printMenu();
		scanf("%d", &choice);
		// printf("%d", choice);
		switch(choice) {
			case 1:
				printf("\nHow many vertices do you want in the graph: ");
				scanf("%d", &vertices);
				graph = createGraph(vertices);
				while(1) {
					printf("\nEnter -1 to stop");
					printf("\nSource: ");
					scanf("%d", &s);
					if (s == -1)
						break;
					printf("Destination: ");
					scanf("%d", &d);
					addEdge(graph, s, d);
				}
				break;
			case 2:
				while(1) {
					printf("\nEnter -1 to stop");
					printf("\nSource: ");
					scanf("%d", &s);
					if (s == -1)
						break;
					printf("Destination: ");
					scanf("%d", &d);
					addEdge(graph, s, d);
				}
				break;
			case 3:
				printf("\nThe Adjacency List of the graph is ");
				printGraph(graph);
				break;
			case 4:
				printf("\nEnter the starting vertex: ");
				scanf("%d", &vertex);
				printf("Depth First Search is \n");
				DFS(graph, vertex);
				break;
			case 5:
				exit = 1;
				break;
			default:
				printf("\nWrong choice");
		}
	}
	
	/*addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 1);

	printf("\nThe graph is");
	printGraph(graph);

	printf("\nDepth First search is\n");
	DFS(graph, 1);*/
	return 0;
}