#include <bits/stdc++.h>
using namespace std;

bool editarLimite(int n, string p, string pal){
  int lenp = p.length();
  int lenpal = pal.length();
  int levenstein[lenpal+1][lenp+1];
  for(int i=0; i <= lenpal; i++){
    for(int j = 0; j <= lenp; j++){
      if(j == 0){
        levenstein[i][j] = i;
      }else if(i == 0){
        levenstein[i][j] = j;
      }else{
        int izq = levenstein[i][j-1];
        int up = levenstein[i-1][j];
        int dia = levenstein[i-1][j-1];
        if(p[j-1] == pal[i-1]){
          int value = min(izq,min(up,dia));
          levenstein[i][j] = value;
        }else{
          int value = min(izq,min(dia,up)) +1;
          levenstein[i][j] = value;
        }
      }
    }
  }
  int nEdiciones = levenstein[lenpal][lenp];
  return nEdiciones<=n;
}

int main() {
  int x, n;
  string p;
  cin >> x >> n;
  cin >> p;
  int estaEnColeccion = 0;
  for(int i = 0; i < n; i++){
    string pal;
    cin >> pal;
    if(editarLimite(x,p,pal)){
      estaEnColeccion ++;
    }
  }
  cout << estaEnColeccion<< endl;
  return 0;
}
