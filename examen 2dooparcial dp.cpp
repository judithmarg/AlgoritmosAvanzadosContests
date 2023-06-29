#include<bits/stdc++.h>
using namespace std;

int valoresMay[500];
//int valoresMen[500];
//int visitadosmen[500];
int visitadosmay[500];
int n;

int solve(int x, int nums[], int ond){
  cout << "****"<<x<<endl;
  if(x == n){
    return 0;
  }if(visitadosmay[x] == 1){
    cout <<"deberia entrar";
    return valoresMay[x];
  }
  //}if(ond == 0 && visitadosmen[x] == 1){
  //  return valoresMen[x];
  //}
  cout << "VALUE"<<nums[x]<<endl; 
  int resmay = INT_MIN;
  int resmin = INT_MIN;

  for(int i=x+1; i < n; i++){
    if(ond==1){
      if(nums[x] < nums[i]){
        resmay= solve(i,nums,0)+ 1;
        visitadosmay[x]=1;
        valoresMay[x] = max(resmay, valoresMay[x]);
      }else{
        //resmin = solve(i,nums,1)+1;
        //visitadosmen[x] = 1;
        //valoresMen[x] =max(resmin, valoresMen[x]);
      }
    }else{   //aca comienza
      if(nums[x] > nums[i]){
        resmay= solve(i,nums,1) +1;
        visitadosmay[x] = 1;
        valoresMay[x] = max(valoresMay[x], resmay);
      }else{
        //resmin = solve(i,nums,0)+1;
        //visitadosmen[x] = 1;
        //valoresMen[x] = max(resmin,valoresMen[x]);
      }
    }
  }
  if(x == n-1){
      valoresMay[x] = 0;// puede faltar
      //valoresMen[x] = 0;
  }
  cout<<"valoresMay: "<<valoresMay[x]<<endl; //"     valoresMen: "<<valoresMen[x]<<endl;
  return valoresMay[x];
}
  


int main(){
  cin >> n;
  int nums[n];
  for(int i = 0; i < n ; i++){
    cin >> nums[i];
  }
  memset(visitadosmay, 0, sizeof(visitadosmay));
  //memset(visitadosmen, 0, sizeof(visitadosmen));
  //memset(valoresMen, INT_MIN, sizeof(valoresMen));
  memset(valoresMay, INT_MIN, sizeof(valoresMay));
  int result = 0;
  for(int j = 0; j < n; j++){
    result = max(result, solve(j,nums,0));
  }
  cout << result+1<< endl;
  return 0;
}
