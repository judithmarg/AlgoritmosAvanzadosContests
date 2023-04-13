#include <bits/stdc++.h>
using namespace std;

string busquedaBinaria(string str, int num, int den, pair<int,int> limInf,pair<int,int> limSup){
    double numComparar = (double)num/den;
    pair<int,int> raiz = make_pair(limInf.first+limSup.first, limInf.second+limSup.second);
    double raizComparar = (double)raiz.first / raiz.second;
    
    if(numComparar == raizComparar){
        str = str;
    }else if (numComparar < raizComparar){
        str += "L"+busquedaBinaria(str, num, den, limInf, raiz); 
    }else if (numComparar > raizComparar){
        str += "R"+busquedaBinaria(str, num, den, raiz, limSup);
    }
    return str;

}

int main(){
    int numerador, denominador;
    cin >> numerador >> denominador;
    while(numerador != 1 && denominador != 1){
        string res = busquedaBinaria("", numerador, denominador, make_pair(0,1),make_pair(1,0));
        cout << res << "\n";
        cin >> numerador >> denominador;
    }
    return 0;
}