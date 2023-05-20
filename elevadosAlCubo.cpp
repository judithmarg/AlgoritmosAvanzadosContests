#include<bits/stdc++.h>
using namespace std;

int elevados[500];
int evaluados[500];

int solve(int x){
  if(x == 1){
    return 1;
  }
  if(x==0){
    return 0;
  }
  if(evaluados[x]){
    return elevados[x];
  }
  int count = 1;
  int termino = 1;
  while(termino <= x){
    count++;
    termino = pow(count,3);
  }
  cout << termino <<"**";
  int res =  solve(x-pow(count-1,3)) + 1;
  evaluados[x] = true;
  elevados[x] = res;
  return res;
}

int main(){
  int ncases;
  cin >> ncases;
  while(ncases--){
    int num, resp;
    cin >> num;
    resp = solve(num);
    cout << resp << endl;
  }
  return 0;
}