#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,d,r;
    cin >> n >> d >> r;
    while(n+d+r != 0){
        int paid = 0, costo = 0;
        int edato, mdato;
        vector<int> morning;
        vector<int> evening;
        for(int i = 0; i < n; i++){
            cin >> mdato;
            morning.push_back(mdato);
        }
        for(int j = 0; j < n; j++){
            cin >> edato;
            evening.push_back(edato);
        }
        sort(morning.begin(),morning.end());
        sort(evening.begin(), evening.end());
        int resultado = 0;
        for(int k = 0; k < n; k++){
                if(morning[k]+evening[n-1-k]-d >= 0){
                    resultado += (morning[k]+evening[n-1-k]-d);
                }
        }
        
        cout << resultado*r << endl;
        cin >> n >> d >> r;
    }
    return 0;
}