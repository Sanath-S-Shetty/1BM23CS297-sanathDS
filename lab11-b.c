#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#define MAX 100 
 
void addEdge(int adj[MAX][MAX], int u, int v); 
void dfs(int adj[MAX][MAX], int V, int s, bool visited[MAX]); 
 
int main() { 
 int V = 5; 
 int adj[MAX][MAX] = {0}; 
 addEdge(adj, 0, 1); 
 addEdge(adj, 0, 2); 
 addEdge(adj, 1, 3); 
 addEdge(adj, 1, 4); 
 addEdge(adj, 2, 4); 
 printf("DFS starting from vertex 0:\n"); 
 bool visited[MAX] = {false}; 
 dfs(adj, V, 0, visited); 
 return 0; 
} 
 
void addEdge(int adj[MAX][MAX], int u, int v) { 
 adj[u][v] = 1; 
 adj[v][u] = 1; 
} 
 
void dfs(int adj[MAX][MAX], int V, int s, bool visited[MAX]) { 
 visited[s] = true; 
102 
 
 printf("%d ", s); 
 for (int i = 0; i < V; i++) { 
 if (adj[s][i] == 1 && !visited[i]) { 
 dfs(adj, V, i, visited); 
 } 
 } 
}