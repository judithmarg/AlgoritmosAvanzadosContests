#include <bits/stdc++.h>
using namespace std;

int divisor(int a,int i){
    while(a % i != 0){
        i++;
    }
    return i;
}

int euclidesExt(int a, int b){
    long long x,y,x1,y1,q,t;
    x = 0; y = 0;
    x1 = 0; y1 = 1; y = 0; x = 1;
    while(b != 0){
        q = a/b;
        t = b;
        b = a% b;
        a = t;
        t = x1; 
        x1 = x - q*x1; 
        x = t;
        t = y1;
        y1 = y- q*y1; 
        y = t;
    }
    int d = a*x+b*y;
    
    return d;
}

int main(){
    int ncasos;
    cin >> ncasos;
    for(int i = 0; i < ncasos; i++){
        int n, e;
        cin >> n; 
        cin >> e;
        int p = divisor(n,2);
        int q = n / p;
        int fn = (p-1)*(q-1);
        int d = euclidesExt(e,fn);
        if(d < 0){
            d = fn+(d%fn)%fn;
        }
        cout << d << endl; 
    }
    return 0;
}