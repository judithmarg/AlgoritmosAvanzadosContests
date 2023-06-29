#include<bits/stdc++.h>
using namespace std;
#define MAXIMO 1000000009
#define N 1000

int mf,f,s,t,n;
int res[N][N], Red[N][N];
vector<vector<int>> edges;
vector<int> p;
void iniciar(){
  for(int i=0; i < n; i++){
    for(int j = 0; j < n; j++){
      res[i][j] = Red[i][j];
    }
  }
}
void aum(int v,int me){
  if(v==s){
    f = me;
    return;
  }if(p[v] != -1){
    aum(p[v], min(me, res[p[v]][v]));
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }
  return;
  
}
int maxflujo(){
  mf=0;
  while(1){
    f=0;
    vector<bool> vis(n,0);
    queue<int> q;
    vis[s]=0;
    q.push(s);
    p.assign(n, -1);
    while(!q.empty()){
      int u=q.front();
      q.pop();
      if(t == u){   break;}
      int z=edges[u].size();
      for(int i=0; i < z; i++){
        int v=edges[u][i];
        if(vis[v] == 0 && res[u][v]>0){
          vis[v] = 1, q.push(v), p[v]=u;
        }
      }
    }
    aum(t, MAXIMO);
    if(f==0){   break ;}
    mf += f;
    }
    return mf;
  
}
int main(){
  int m,T,contador=1;
  cin >> T;
  int a,b,c,B;
  double d,D;
  while(T--){
    edges.assign(N, vector<int>());
    cout <<"Case "<< contador<< ":";
    cin >> n >> d;
    c=n;
    d*=d;
    int x[n+1],y[n+1];
    for(int i=0; i <=(2*n+5); i++){
    for(int j=0; j <=(2*n+5); j++){
      Red[i][j] = 0;
       m=0;
    }}
    for(int i=1; i<=n; i++){
      cin >>x[i] >> y[i] >> a >> b;
      edges[0].push_back(i);
      Red[0][i]=a;
      m+=a;
      edges[i].push_back(i+n);
      edges[i+1].push_back(i);
      Red[i][n+i]=b;
    }
    for(int i=1; i <=n; i++){
      for(int j=1; j <=n; j++){
        D=pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2);
        if(D<=d &&(i!=j)){
          edges[i+n].push_back(j);
          edges[j].push_back(i+n);
          Red[i+n][j]=MAXIMO;
        }
      }
    }
    n*=2;
    n++;
    s=0;
    a=0;
    for(int i=1; i <=c; i++){
      B=Red[0][i];
      Red[0][i]=0;
      iniciar();
      t=i;
      if((maxflujo()+B)==m){
        a=1;
        cout << " "<<i-1;
      }
      Red[0][i]=B;
    }
    if(a==0){
      cout <<" -1";
    }  
    cout<<"\n";
    contador++;
  }
    
  
  return 0; 
}