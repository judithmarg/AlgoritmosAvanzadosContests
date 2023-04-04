#include <bits/stdc++.h>
using namespace std;

void rotar(vector<string> &square,int n){
    vector<string> twice(n, string(n, ' '));
    for(int i=0; i<n; i++){
        for(int j=0; j <n; j++){
            twice[j][n-i-1] = square[i][j];
        }
    }
    square = twice;
}


string mostrarResultado(int n, bool c){
    string res;
    if(!c){
        res = "improperly transformed.";
    }else{
        if(n==0){   res="preserved.";}
        else if(n==1){   res="rotated 90 degrees.";}
        else if(n==2){   res="rotated 180 degrees.";}
        else if(n==3){   res="rotated 270 degrees.";}
        else if(n==4){   res="reflected vertically.";}
        else if(n>=5){   res="reflected vertically and " + mostrarResultado(n-4,c);}
    }
    return res;
}

int main(){
    int larray, ncases=1;
    while(cin >>larray){
        vector<string> square1; 
        vector<string> square2; 
        for(int i = 0; i < larray; i++){
            string sq1, sq2;
            cin >> sq1;
            cin >> sq2;
            square1.push_back(sq1);
            square2.push_back(sq2);
        }
        bool cumple = false;
        int combinaciones = 0;
        cumple = square1 == square2;
    
        while(!cumple && combinaciones < 4){
            rotar(square1,larray);
            cumple = square1 == square2;
            combinaciones++;
        }
        if(!cumple){
            for(int y=0; y < larray/2; y++){
                swap(square1[y],square1[larray-y-1]);
            }
            cumple = square1 == square2;
        }
        
        while(!cumple && combinaciones < 7){
            rotar(square1,larray);
            cumple = square1 == square2;
            combinaciones++;
        }
        
        string resultado = mostrarResultado(combinaciones,cumple);
        cout << "Pattern "<< ncases<<" was "<< resultado << endl;
        ncases +=1;
    }
    return 0;
}