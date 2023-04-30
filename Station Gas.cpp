#include<bits/stdc++.h>
using namespace std;

int main(){
    int L, G;
    cin >> L >> G;
    while(L > 0 && G > 0){
        int x , r;
        vector<pair<int,int>> covered;
        for(int i = 0; i < G; i++){
            cin >> x >> r;
            covered.push_back(make_pair(x-r,x+r));
        }
        sort(covered.begin(), covered.end());
        vector<pair<int,int>> cantNeeded;
        int nextArea = 0,limiteArea = 0, ind=0,result;
        while(nextArea < L){
            result = -1;
            int i=0;
            while(covered[i].first <= limiteArea &&i <= covered.size()-1 ){
                if(covered[i].second > nextArea){
                    nextArea = covered[i].second;
                    result = i;
                }
                i++;
            }
            if(result == -1){
                break;
            }else{
                cantNeeded.push_back(covered[result]);
                limiteArea = covered[result].second;
            }
        }
        if(cantNeeded.empty() || cantNeeded.back().second < L){
            cout << "-1\n";
        }else{
            cout << G-cantNeeded.size() << "\n";
        }
    
        cin >> L >> G;
    }
    return 0;
}