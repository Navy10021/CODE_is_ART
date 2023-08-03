/* 
Tree : 무방향이면서 사이클이 없는 연결 그래프(Undirected Acyclic Connected Graph)
주요성질 : V개의 정점을 가지고, V-1개의 간선을 가지는 연결 그래프 + 임의의 두 점을 연결하는 Simple path가 유일한 그래프
simple path : 정점이 중복해서 나오지 않는 경로 

BFS 알고리즘 : Graph와 동일
- 시작점을 Root로 정해서 트리를 재배치했을 때 높이 순으로 방문! 
- 부모 정점을 제외하고, 나머지를 전부 Queue에 넣으면 된다. -> visited array 불필요 && 부모 노드만 알면 된다
*/

