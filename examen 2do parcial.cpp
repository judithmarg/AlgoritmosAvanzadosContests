#include <bits/stdc++.h>
using namespace std;
#define N 202
 
int capacidades[N][N];
int flujoRecorrido[N][N];
vector<int> grafo[N];
int anteriores[N];       
int caminoCapacidad[N];  
 
int bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    anteriores[s] = -2;
    caminoCapacidad[s] = 999;
 
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0; i<grafo[v].size(); i++) {
            int x = grafo[v][i];
            if(anteriores[x] == -1){
                if(capacidades[v][x] - flujoRecorrido[v][x] > 0){
                    anteriores[x] = v;
                    caminoCapacidad[x] = min(caminoCapacidad[v], 
                    capacidades[v][x] - flujoRecorrido[v][x]);
                    if(x == t){
                        return caminoCapacidad[t];
                    }
                    q.push(x);
                }
            }
        }
    }
    return 0;
}
 
int edmondsKarp(int s, int t) {
    int maximoFlujo = 0;
    while(true) {
        memset(anteriores, -1, sizeof(anteriores));
        memset(caminoCapacidad, 0, sizeof(caminoCapacidad));
        int flow = bfs(s, t);
        if (flow == 0) {
            break;
        }
        maximoFlujo += flow;
        int v = t;
        while(v != s) {
            int u = anteriores[v];
            flujoRecorrido[u][v] += flow;
            flujoRecorrido[v][u] -= flow;
            v = u;
        }
    }
    return maximoFlujo;
}
int main() {
    int n, m;
    cin>>n>>m;
    int s=0, t=n+m+1;
    for(int i=1; i <= n; i++){
        int a;
        cin >> a;
        capacidades[0][i]=a;
        grafo[0].push_back(i);
    }
    for(int e = n+1; e < n+m+1; e++){
        int k;
        cin >> k;
        for(int i=0; i<k; i++){
            int u;
            cin >> u;
            capacidades[u][e] = 1;
            grafo[u].push_back(e);
            grafo[e].push_back(u);
        }
        capacidades[e][t] = 1;
        grafo[e].push_back(t);
    }
    int maximoFlujo = edmondsKarp(s, t);
    cout<<maximoFlujo<<endl;
}