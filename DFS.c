#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int numberOfVertices;
    int *visited;
    struct Node** adjList;
};


// create a new node
struct Node* createNode(int vertex) {
    // get required memory for the new node
    struct Node* newNode = malloc(sizeof(struct Node));
    // initializing vertex to data and NULL to next
    newNode->data = vertex;
    newNode->next = NULL;
    return newNode; // return newly created node
}

// create a graph
struct Graph* createGraph(int vertices) {
    // get required memory for the new graph
    struct Graph* newGraph = malloc(sizeof(struct Graph));  
    // initialize number of vetices
    newGraph->numberOfVertices = vertices;
    // get required memory for visited vertices and adjacency list
    newGraph->visited = malloc(vertices * sizeof(int));
    newGraph->adjList = malloc(vertices * sizeof(struct Node));
    // inititalize vertices to 0 and adjacency list to NULL
    for (int i = 0; i < vertices; ++i) {
        newGraph->visited[i] = 0;
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

// DFS Code
void DFS(struct Graph* graph, int vertex) {
    // getting the vertex
    struct Node* n = graph->adjList[vertex];
    struct Node* temp = n;

    // initializing visited to 1 for that vertex
    graph->visited[vertex] = 1;
    printf(" %d ", vertex);

    // going till the node with no outgoing edges
    while (temp) {
        // if the vertex is unvisited then make a recursive call to 
        // the function with the vertex to print it and go for next
        // vertex 
        if (graph->visited[temp->data] == 0)
            DFS(graph, temp->data);
        temp = temp->next;
    }
}

// add Edges to the graph
void addEdge(struct Graph* graph, int s, int d) {
    // adding edge from source to destination
    struct Node* temp = createNode(d);
    temp->next = graph->adjList[s];
    graph->adjList[s] = temp;
    // adding edge from destination to source
    temp = createNode(s);
    temp->next = graph->adjList[d];
    graph->adjList[d] = temp;
}

// print the graph
void printGraph(struct Graph* graph) {
    struct Node* temp;
    for (int i = 0; i < graph->numberOfVertices; ++i) {
        temp = graph->adjList[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Action menu
void printMenu() {
    printf("\n1. Create the graph");
    printf("\n2. Print the graph");
    printf("\n3. Depth First Search for the graph");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
}

// Method to call createGraph and initialize the graph
struct Graph* create(struct Graph* graph) {
    int vertices;
    int s = 0;
    int d = 0;
    printf("\nEnter the total number of vertices: ");
    scanf("%d", &vertices);
    graph = createGraph(vertices);
    while (true) {
        printf("\nEnter -1 to stop");
        printf("\nSource: ");
        scanf("%d", &s);
        if (s == -1)
            break;
        printf("Destination: ");
        scanf("%d", &d);
        if (d == -1)
            break;
        addEdge(graph, s, d);
    }
    return graph;
}

// Main method
int main() {
    bool exit = false;
    int choice;
    struct Graph* graph;
    int vertex;
    while (!exit) {
        printMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                graph = create(graph);
                break;
            case 2:
                printGraph(graph);
                break;
            case 3:
                printf("\nEnter the root vertex: ");
                scanf("%d", &vertex);
                printf("\nDepth first Search Traversal is ");
                DFS(graph, vertex);
                break;
            case 4:
                exit = true;
                break;
            default:
                printf("\nWrong choice!!!");
        }
    }
    return 0;
}