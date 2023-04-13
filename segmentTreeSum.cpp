#include <bits/stdc++.h>
using namespace std;
//segment tree para sumas y menor numero
/*struct item{
    int m, c;
};
*/
struct segtree{
    int size;
    vector<long long> sums;
    vector<int> values;
    /*vector<item> vlues;
    
    item NEUTRAL_ELEMENT = {INT_MAX, 0};
    item merge(item a, item b){
        if(a.m < b.m) return a;
        if(a.m > b.m) return b;
        return {a.m, a.c+b.c}
    }

    item single(int v){
        return {v,c};
    }
    */
    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;   //values.resize(2*size)
        }
        sums.assign(2*size, 0LL);
    }

    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){   //si es hojita
            if(lx < (int)a.size()){
                sums[x] = a[lx];
                // values[x] = set(a[lx]);
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a, 2*x+1, lx,m);
        build(a, 2*x+2, m, rx);
        sums[x] = sums[2*x+1] + sums[2*x+2];
        values[x]= min(values[2*x+1],values[2*x+2]);
        //values[x] = merge(values[2*x+1],values[2*x+2]);
    }

    void build(vector<int> &a){
        build(a,0,0,size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            sums[x] = v;
            //values[x] = single(v);
            return;
        }
        int m = (lx+rx) / 2;
        if(i < m){
            set(i,v,2*x+1,lx,m);
        }else{
            set(i,v,2*x+2,m,rx);
        }
        sums[x] = sums[2*x+1] + sums[2*x+2];
        values[x] = min(values[2*x+1], values[2*x+2]);
        //values[x] = merge(values[2*x+1], values[2*x+2]);
    }

    void set(int i, int v){
        set(i,v,0,0,size);
    }

    int calc(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){  //case 1 no esta dentro del rango
            return INT_MAX;  //NEUTRSL_ELEMENT
        }
        if(lx >= l && rx <= r){  //case 2 si esta dentro del rango completamente
            return sums[x];     //valor del nodito
        }
        int m = (lx+rx)/2;
        int s1 = calc(l,r,2*x+1, lx, m);
        int s2 = calc(l,r,2*x+1, m, rx);
        return min(s1,s2);
    }

    int calc(int l, int r){  
        return calc(l,r,0,0,size);
    }

    long long sum(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){  //case 1 no esta dentro del rango
            return 0;
        }
        if(lx >= l && rx <= r){  //case 2 si esta dentro del rango completamente
            return sums[x];     //valor del nodito
        }
        int m = (lx+rx)/2;
        long long s1 = sum(l,r,2*x+1, lx, m);
        long long s2 = sum(l,r,2*x+1, m, rx);
        return s1 + s2;
    }

    long long sum(int l, int r){  
        return sum(l,r,0,0,size);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    st.build(a);
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        } else{
            int l,r;
            cin >> l >> r;
            //auto res = st.calc(l,r);
            // cout << res.m << res.c << endl;
            cout << st.calc(l,r) << "\n";
        }
    }
    return 0;
}