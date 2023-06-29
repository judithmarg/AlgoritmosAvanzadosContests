#include <bits/stdc++.h>
using namespace std;

int main() {
  string p, t;  //patron y texto
  
  while(getline(cin, p) && getline(cin, t)){
    int m = t.length();
    int n = p.length();
    int arrayKMP[n];
    if(m >= n){
      //construccion del array sufijo mas largo como prefijo
      /*arrayKMP[0] = 0;
      arrayKMP[1] = 0;
      int coincidencia = 0;
      int indice = 0;
      for(int i = 2; i < n; i++){
        if(p[i] == p[indice]){
          coincidencia++;
          arrayKMP[i] = coincidencia;
          indice++;
        }else{
          arrayKMP[i] = 0;
          coincidencia = 0;
          indice = 0;
        }
      }*/
    //***para eliminarj
      arrayKMP[0] = 0;
      int j=0;
      for(int i =1; i < n; i++){
        while(j && p[i] != p[j]){
          j= arrayKMP[j-1];
        }
        if(p[i]==p[j]){
          j++;
        }
        arrayKMP[i] = j;
      }
    //*
      /*for(int j = 0; j < n; j++){
        cout<<arrayKMP[j]<<"*" <<endl;
      }*/
      j = 0;//habia int
      for(int i = 0; i < m; i++){
        /*if(t[i] == p[j]){
          j++;
          if(j == n){
            int res = i-n+1; 
            j = arrayKMP[n-1];
            cout << res << " ";
          }
        }else if(j > 0){
          j = arrayKMP[j-1];
          i--;
        }*/
        while(j && t[i] != p[j]){
          j = arrayKMP[j-1];
        }
        if(t[i]==p[j]){
          j++;
        }if(j == n){
          cout << i-n+1<< " ";
          j = arrayKMP[j-1];
        }
      }
      cout << "\n";
    }else{
      cout << "\n";
    }  
  }
  return 0;

}