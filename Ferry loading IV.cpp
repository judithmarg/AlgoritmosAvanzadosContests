#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int metros,cantidad;
        cin >>metros;
        cin >> cantidad;
        metros = metros * 100;
        queue<int> izqs;
        queue<int> ders;
        
        for(int j = 0; j < cantidad; j++){
            int valor;
            string pos;
            cin >> valor;
            cin >> pos;
            if(pos =="left"){
                izqs.push(valor);
            }else{
                ders.push(valor);
            }
        }
        int solution=0;
        int aux, lado=1;
        while(!(izqs.empty() && ders.empty())){
            int limite = 0;
            if(lado&1){
                while(!izqs.empty() && limite + izqs.front() <= metros){
                    limite += izqs.front();
                    izqs.pop();
                }
            }else{
                while(!ders.empty() && limite + ders.front() <= metros){
                    limite += ders.front();
                    ders.pop();
                }
            }
            solution += 1;
            lado += 1;
        }
        cout << solution << endl;
    }
	return 0;
}
