#include<bits/stdc++.h>
using namespace std;
#define N 102

int n,m;
int grafores[N][N];

//encuentra un camino cualquiera de la fuente al  sumidero
bool bfs(int (&rGraph)[N][N], int s, int t, int anteriores[]) {
  bool visitado[n+m+2];
  memset(visitado, 0, sizeof(visitado));
  queue<int> q;
  q.push(s);
  visitado[s] = true;
  anteriores[s] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < n+m+2; v++) {
      if (visitado[v] == false && rGraph[u][v] > 0) {
        q.push(v);
        anteriores[v] = u;
        visitado[v] = true;
      }
    }
  }
  return visitado[t];
}

int fordFulkerson(int (&matrizAdy)[N][N],int s,int t){
  int u,v;
  int rGraph[N][N];
  for(u=0;u <n+m+2; u++){
    for(v=0; v< n+m+2;v++){
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
      grafores[u][v] = matrizAdy[u][v] - rGraph[u][v];
    }
    max_flow += path_flow;
  }

  return max_flow;
}

int main( ){
  cin >>n >> m;
  int matrizAdy[N][N];
  int s = 0, t = n+m+2;
  memset(matrizAdy, 0, sizeof(matrizAdy));
  for(int i=1; i <= n; i++){
    int c;
    cin >> c;
    matrizAdy[0][i]=c;
  }
  for(int j=n+1; j <= n+m+1; j++){
    int k;
    cin >> k;
    for(int y=0; y < k; y++){
      int u;
      cin >> u;
      matrizAdy[u][j] = 1;
    }
    matrizAdy[j][t]=1;
  }
  for(int i=0; i < n+m+2; i++){
    for(int j=0; j < n+m+2; j++){
      cout << matrizAdy[i][j] <<" ";
    }
    cout <<"\n";
  }
  int flujo = fordFulkerson(matrizAdy,s,t);
  cout << flujo  <<endl;
  return 0;
}