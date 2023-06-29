#include<bits/stdc++.h>
using namespace std;
#define N 500

int n;
int grafores[N][N];

//encuentra un camino cualquiera de la fuente al  sumidero
bool bfs(int (&rGraph)[N][N], int s, int t, int parent[]) {
  bool visited[n];
  memset(visited, 0, sizeof(visited));
  queue<int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < n; v++) {
      if (visited[v] == false && rGraph[u][v] > 0) {
        q.push(v);
        parent[v] = u;
        visited[v] = true;
      }
    }
  }
  return (visited[t] == true);
}

int fordFulkerson(int (&matrizAdy)[N][N],int s,int t){
  int u,v;
  int rGraph[N][N];
  for(u=0;u <n; u++){
    for(v=0; v< n;v++){
      rGraph[u][v] = matrizAdy[u][v];
    }
  }
  //copia de matrizAdy
  int parent[n];
  int max_flow = 0;
  while (bfs(rGraph, s, t, parent)) {
    int path_flow = INT_MAX;
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }
    //el menor valor del camino aumentante
    
    for (v = t; v != s; v = parent[v]) {
      u = parent[v];  //para analizar un camino en si,
      rGraph[u][v] -= path_flow; //camino original que va disminuyendo
      rGraph[v][u] += path_flow; //camino de la red residual donde se aumenta
      grafores[u][v] = rGraph[v][u];
    }
    max_flow += path_flow;
  }

  return max_flow;
}

int main( ){
  int m, s,t;
  cin >>n >> m >> s >> t;
  int matrizAdy[N][N];
  memset(matrizAdy, 0, sizeof(matrizAdy));
  for(int i=0; i < m; i++){
    int u, v, c;
    cin >> u >> v >> c;
    matrizAdy[u][v] = c;
    //matrizAdy[v][u] = c;
  }
  int flujo = fordFulkerson(matrizAdy,s,t);
  string edgesLeast1 = "";
  int contador = 0;
  for(int i=0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(grafores[i][j] >= 1){
        contador++;
        edgesLeast1 += to_string(i) + " " + to_string(j) + " " + to_string(grafores[i][j]) +"\n";
      }
    }
  }
  cout << n <<" " << flujo << " "<< contador <<endl;
  cout << edgesLeast1 ;
  return 0;
}