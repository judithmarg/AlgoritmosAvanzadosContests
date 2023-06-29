#include<bits/stdc++.h>
using namespace std;
#define N 800

int revisados[N];
int visitados[N];
vector<int> grafo[N];
bool dfs(int a){
  for(int i=0; i < grafo[a].size(); i++){
    int x= grafo[a][i];
    if(!visitados[x]){
      visitados[x] = 1;
      if(revisados[x] == 0 || dfs(revisados[x]) ){
        revisados[x] = a;
        return true;
      }
    }
  }
  return false;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    for(int i=1; i <= n; i++){
      grafo[i].clear();
    }
    for(int j=0; j < m; j++){
      int a,b;
      cin >> a >> b;
      grafo[a].push_back(b);
    }
    memset(revisados,0,sizeof(revisados));
    int respuesta=0;
    for(int k=1; k <=n;k++){
      memset(visitados,0,sizeof(visitados));
      if(dfs(k)){
        respuesta++;
      }
    }
    cout << n-respuesta<<"\n";
  }
}