#include <bits/stdc++.h>
using namespace std;

int n;
int values[100000];
const int INF = 1e9;

int sapito(int x, int piedras[]){
  if(x >= n){
    return INF;
  }
  if(values[x] != -1){
    return values[x];
    
  }
  int salto1=0;
  if(x < n-1){
    salto1 =  abs(piedras[x]-piedras[x+1])+sapito(x+1,piedras);
  }else if( x == n-1){
    salto1 =  abs(piedras[x]-piedras[x+1]);
  }
  int salto2=0;
  if(x < n-2){
    salto2 = abs(piedras[x]-piedras[x+2])+sapito(x+2,piedras);
  }else if(x== n-2) {
    salto2 = abs(piedras[x]-piedras[x+2]);
  }
  int minimo = min(salto1,salto2);
 
  values[x] =  minimo < INF && minimo > -1? minimo: 0;
  return values[x];
}

int main() {
  
    cin >> n;
    int piedras_values[n];
    for(int i=0; i < n; i++){
      cin >> piedras_values[i];
    }
    for(int i=0; i < n; i++){
      values[i] = -1;
    }
    values[n-1] = 0;
    int costo =  sapito(0,piedras_values);
    cout<<costo;
}