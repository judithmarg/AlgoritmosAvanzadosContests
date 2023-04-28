#include <bits/stdc++.h>
using namespace std;

vector<int> setPrincipal;
int _find(int x){
    if(setPrincipal[x]==x){
        return x;
    }
    return setPrincipal[x]=_find(setPrincipal[x]);
}
int unionDS(int x,int y,int peso){
    x=_find(x);
    y=_find(y);
    if(x==y){
        return 0;
    }else{
        P[x]=y;
        return peso;
    }
}
int main(){
    int nVertices, nAristas;
    cin >> nVertices >> nAristas;
    priority_queue<pair<int, pair<int,int>>> c;
    for(int i = 0; i <= nVertices; i++){
        setPrincipal.push_back(i);
    }
    for(int j = 0; j < nAristas; j++){
        int c1, v1, v2;
        cin >> c1>> v1 >> v2;
        c.push(make_pair(c1, make_pair(v1,v2)));
    }
    int resp = 0;
    for(int k = 0; k < nAristas; k++){
        int aux = resp;
        cout << c[i].second.first << " " << c[i].second.second << endl;
        resp += unionDS(c[i].first,c[i].second.first,c[i].second.second);
        cout << resp-aux << endl;
    }
    cout << resp << endl;
    return 0;
}
