#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, count = 1;
  cin >> n;
  while(n != 0){
    vector<int> vestimenta, accesorios;
    for(int i = 0; i < n; i++){
      int a;
      cin >> a;
      vestimenta.push_back(a);
    }
    for(int j = 0; j < n; j++){
      int b;
      cin >> b;
      accesorios.push_back(b);
    }
    //int nvestimenta = sizeof(nvestimenta)/sizeof(nvestimenta[0]);
    //int naccesorios = sizeof(naccesorios)/sizeof(naccesorios[0]);
    
    sort(vestimenta.begin(), vestimenta.end());
    sort(accesorios.begin(), accesorios.end());
    
    int balanceo[n];
    for(int i = 0; i < n; i++){
      balanceo[i] = vestimenta[i] + accesorios[n-i-1]; 
    }
    int minim = INT_MAX;
    int maxim = INT_MIN;
    for(int j=0; j < n; j++){
      minim = min(minim, balanceo[j]);
      maxim = max(maxim, balanceo[j]);
    }
    double resp = (minim+maxim)/2.0;
    cout << fixed;
    cout <<  setprecision(1);
    cout << "Caso "<<count << ": " << resp << endl;
    count ++;
    cin >> n;
  }
  return 0;
}
