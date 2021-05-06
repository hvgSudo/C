#include<stdio.h>
#include<stdlib.h>
#define SIZE 40

struct Queue {
	int items[SIZE];
	int front;
	int rear;
};

struct Queue* createQueue();
void enqueue(struct Queue* q, int);
int dequeue(struct Queue* q);
void display(struct Queue* q);
int isEmpty(struct Queue* q);
void printQueue(struct Queue* q);

struct Node {
	int vertex;
	struct Node* next;
};

struct Node* createNode(int);

struct Graph {
 	int numberOfVertices;
 	struct Node** adjacencyLists;
 	int* visited;
 }; 

 // Breadth First Search Recursive Algorithm
 void bfs(struct Graph* graph, int startVertex) {
 	struct Queue* q = createQueue();
 	graph->visited[startVertex] = 1;
 	enqueue(q, startVertex);

 	while (!isEmpty(q)) {
 		printQueue(q);
 		int currentVertex = dequeue(q);
 		printf("%d ", currentVertex);
 		struct Node* temp = graph->adjacencyLists[currentVertex];

 		while (temp) {
 			int visited = temp->vertex;
 			if (graph->visited[visited] == 0) {
 				graph->visited[visited] = 1;
 				enqueue(q, visited);
 			}
 			temp = temp->next;
 		}
 	}
 }

 // Creating a node
 struct Node* createNode(int vertex) {
 	struct Node* newNode = malloc(sizeof(struct Node));
 	newNode->vertex = vertex;
 	newNode->next = NULL;
 	return newNode;
 }

 // Creating a Graph
 struct Graph* createGraph(int vertices) {
 	struct Graph* graph = malloc(sizeof(struct Graph));
 	graph->numberOfVertices = vertices;
 	graph->adjacencyLists = malloc(vertices * sizeof(struct Node*));
 	graph->visited = malloc(vertices * sizeof(int));
 	int i;
 	for (i = 0; i < vertices; ++i) {
 		graph->adjacencyLists[i] = NULL;
 		graph->visited[i] = 0;
 	}
 	return graph;
 }

 // Add edge
 void addEdge(struct Graph* graph, int source, int destination) {
 	// Add edge from source to destination
 	struct Node* newNode = createNode(destination);
 	newNode->next = graph->adjacencyLists[source];
 	graph->adjacencyLists[source] = newNode;

 	// Add edge from destination to source
 	newNode = createNode(source);
 	newNode->next = graph->adjacencyLists[destination];
 	graph->adjacencyLists[destination] = newNode;
 }

 // Create a queue
 struct Queue* createQueue() {
 	struct Queue* q = malloc(sizeof(struct Queue));
 	q->front = -1;
 	q->rear = -1;
 	return q;
 }

 // Check if queue is empty
 int isEmpty(struct Queue* q) {
 	if (q->rear == -1)
 		return 1;
 	return 0;
 }

 // Adding elements into the queue
 void enqueue(struct Queue* q, int value) {
 	if (q->rear == SIZE - 1) {
 		printf("\nQueue is full");
 		return;
 	}
 	if (q->front == -1)
 		q->front = 0;
 	q->rear++;
 	q->items[q->rear] = value;
 }

 // Removing elements from the queue
 int dequeue(struct Queue* q) {
 	int item;
 	if (isEmpty(q)) {
 		printf("\nQueue is empty");
 		item = -1;
 	} else {
 		item = q->items[q->front];
 		q->front++;
 		if (q->front > q->rear) {
 			printf("\nResetting queue ");
 			q->front = q->rear = -1;
 		}
 	}
 	return item;
 }

 // Print the queue
 void printQueue(struct Queue* q) {
 	int i = q->front;
 	if (isEmpty(q)) {
 		printf("\nQueue is empty");
 		return;
 	}
 	printf("\nQueue contains\n");
 	for (i = q->front; i < q->rear + 1; i++) 
 		printf("%d ", q->items[i]);
 }

// Take input from file and write output to file
 void initCode() {
 	#ifndef BreadthFirstSearch
 		// For getting input from input.txt file
	    freopen("D:/Codes/C/input.txt", "r", stdin);
	  
	    // Printing the Output to output.txt file
	    freopen("D:/Codes/C/output.txt", "w", stdout);
 	#endif
 }

 // Main method
 int main() {
 	initCode();
 	struct Graph* graph = createGraph(6);
  	addEdge(graph, 0, 1);
  	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);

  	bfs(graph, 0);

 	return 0;
 }