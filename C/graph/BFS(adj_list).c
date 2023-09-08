#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NODES 100

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int numVertices;
    struct Node* adjList[MAX_NODES];
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'numVertices' vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    
    for (int i = 0; i < numVertices; ++i)
        graph->adjList[i] = NULL;
    
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
    
    // Add an edge from dest to src (uncomment this line for undirected graph)
    // newNode = createNode(src);
    // newNode->next = graph->adjList[dest];
    // graph->adjList[dest] = newNode;
}

// Function to perform BFS on the graph starting from a given vertex
bool visited[MAX_NODES] = { false };
int dist[MAX_NODES] = {-1};
void BFS(struct Graph* graph, int startVertex) {
    //bool visited[MAX_NODES] = { false };
    
    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    
    // Mark the current node as visited and enqueue it
    visited[startVertex] = true;
    dist[startVertex] = 0;
    queue[rear++] = startVertex;
    
    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int vertex = queue[front++];
        printf("%d(%d) -> ", vertex, dist[vertex]);    // 방문노드(거리) 표시
        
        // Get all adjacent vertices of the dequeued vertex
        struct Node* currentNode = graph->adjList[vertex];
        while (currentNode) {
            int adjVertex = currentNode->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
                dist[adjVertex] = dist[vertex] + 1;
            }
            currentNode = currentNode->next;
        }
    }
}

// 인접 리스트를 오름차순으로 정렬하는 함수
void sortAdjLists(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        // 선택 정렬을 사용하여 오름차순 정렬
        struct Node* current = graph->adjList[i];
        while (current != NULL) {
            struct Node* minNode = current;
            struct Node* temp = current->next;
            while (temp != NULL) {
                if (temp->data < minNode->data) {
                    minNode = temp;
                }
                temp = temp->next;
            }
            // minNode와 current를 교환
            int tempData = current->data;
            current->data = minNode->data;
            minNode->data = tempData;
            current = current->next;
        }
    }
}

// 인접리스트 뒤집기
void reverseAdjLists(struct Graph* graph){
    // 1. 모든 시작 정점을 돌면서
    for (int i=0; i < graph->numVertices; i++){
        struct Node* curr = graph->adjList[i];
        struct Node* prev = NULL;
        struct Node* next_node;

        while(curr != NULL){
            next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        graph->adjList[i] = prev;
    }
}



int main() {
    int numVertices = 6;
    struct Graph* graph = createGraph(numVertices);
    
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    
    // 내림차순 방문
    sortAdjLists(graph);
    reverseAdjLists(graph);
    
    //printf("Breadth-First Traversal (starting from vertex 0): ");
    //BFS(graph, 0);
    //printf("\n");
    
    // undirected visit
    for(int i=0; i < numVertices; i++){
        if (!visited[i]){
            BFS(graph, i);
            printf("\n");
        }
    }

    return 0;
}
