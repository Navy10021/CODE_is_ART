#include <stdio.h>

#define MAX 10001
int Graph[MAX][MAX] = {0};  // u -> v; adj_matrix
int visited[MAX] = {0};
int visited2[MAX] = {0};
int queue[MAX];

void DFS(int u, int N){
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 1; v <= N; v++){
        if (Graph[u][v] == 1 && visited[v] != 1)
            DFS(v, N);
    }
    return;
}

void BFS(int u, int N){
    int front = 0;
    int rear = 0;
    int pop_val;

    printf("%d ", u);
    queue[0] = u;
    rear++;
    visited2[u] = 1;

    while(front < rear){        // Queue가 빌때까지
        pop_val = queue[front];
        front++;

        for (int v=1; v<=N; v++){
            if(Graph[pop_val][v] == 1 && visited2[v] !=1){
                printf("%d ", v);
                queue[rear] = v;
                rear++;
                visited2[v] = 1;
            }
        }
    }
    return;
}


int main(){
    int N, M, start; // 정점수, 간선수, 시작정점
    int u, v;         // u -> v
    scanf("%d %d %d", &N, &M, &start);
    
    for (int i=0; i<M; i++){
        scanf("%d %d", &u, &v);
        // Undirected adj_matrix
        Graph[u][v] = 1;
        Graph[v][u] = 1;
    }

    DFS(start, N);
    /*
    // 방문하지 않은 노드 확인(0 출력)
    for (int i=1; i<=N; i++){
        if (!visited[i])
            printf("%d", 0);
    }*/
    printf("\n");
    BFS(start, N);

}
