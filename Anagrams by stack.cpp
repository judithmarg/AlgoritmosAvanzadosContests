#include <bits/stdc++.h>
using namespace std;
// simular push y pop de una word para convertirla en wordWanted, este codigo no hace busqueda completa, no sirve para todos los casos

int main(){
    string word;
    while(cin >> word){
        cout << "[" << endl;
        string wordWanted;
        cin >> wordWanted;
        int indAux =  word.size()-1;
        
        for(int i = 0; i < word.size(); i++){
            stack<char> pila;
            int o = 0;
            string aux = "";
            while(o <= indAux){
                pila.push(word[o]);
                aux += "i";
                o++;
            }
            int ind = 0, j = pila.size();
            bool cumple = true;
            pila.pop();
            aux += "o";
            ind += 1;
            while(cumple && aux.size() < (word.size()*2)){
                if(pila.empty() && j < word.size()){
                    pila.push(word[j]);
                    aux += "i";
                    j = j+1;
                }else{
                    if(pila.top() == wordWanted[ind]){
                        pila.pop();
                        aux += "o";
                        ind += 1;
                    }else if(j < word.size()){
                        pila.push(word[j]);
                        aux += "i";
                        j = j+1;
                    }else{
                        cumple = false;
                    }    
                } 
                
            }
            if(cumple){
                cout << aux << endl;
            }
            indAux--;
            
        }
        cout << "]" << endl;
    }
}