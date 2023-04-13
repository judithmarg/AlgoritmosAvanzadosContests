
using namespace std;
#define LIMITE 1000005

int set1[LIMITE];

void construirSet(int n){
    for(int i=1; i < n; i++){
        set1[i] = i;
    }
}

int encontrar(int element){
    if(element == set1[element]){
        return element; 
    }
    return set1[element]= encontrar(set1[element]);
}

void setUnion(int x, int y){
    int x1, y1;
    x1 = encontrar(x);
    y1 = encontrar(y);
    if(x1 != y1){
        set1[x1] = y1;
    }
}

int main(){
    int ncases;
    cin >> ncases;
    for(int i = 0; i < ncases; i++){
        int ncomputers, c1, c2;
        cin >> ncomputers;
        getchar();
        construirSet(ncomputers);
        int nconectado = 0;
        int ndesconectado = 0;
        string s;
        while(getline(cin,s)){
            if(s.size()==0){    break;}
            stringstream ss;
            ss>>s>>c1>>c2;
            
            if(s == "c"){
                setUnion(c1,c2);
            }else{
                if(encontrar(c1)== encontrar(c2)){
                    nconectado ++;
                }else{
                    ndesconectado++;
                }
            }
        }
        cout << nconectado << ", " << ndesconectado << "\n";
        if(ncases){
            cout << "\n";
        }
    }
    return 0;    
}
