#include <bits/stdc++.h>
using namespace std;

int main(){
    int g,p;
    cin >> g;
    cin >> p;
    while(g != 0 && p!= 0){
        vector<pair<int,int>> pilots;
        for(int i= 0; i < g; i++){
            for(int j= 0; j < p; j++){
                int pilot;
                cin>>pilot;
                pilots.push_back({pilot,j});
            }
        }
        int s;
        cin >> s;
        sort(pilots.begin(), pilots.end());
        for(int u= 0; u < s; u++){
            int res[p];
            for(int a = 0; a < p; a++){
                res[a] = 0;
            }
            int k,ind=0;
            cin >> k;
            for(int j= 0; j < k; j++){
                int aux;
                cin >> aux;
                for(int y = 0; y < g; y++){
                    int scd = pilots[ind].second;
                    res[scd] += aux;
                    ind++;
                }
            }
            int resp = -1,count = 0;
            for(int o = 0; o < p; o++ ){
                resp = max(res[o],resp);
            }
            for(auto e : res){
                if(e == resp){
                    count++;
                }
            }
            for(int u = 0; u < p; u++ ){
                if(resp == res[u]){
                    cout << u+1;
                    if(count > 1){    
                        cout <<" ";
                        count--;
                    }
                }
            }
            cout <<"\n";
            
        }
        cin >> g;
        cin >> p;
    }
    return 0;
}