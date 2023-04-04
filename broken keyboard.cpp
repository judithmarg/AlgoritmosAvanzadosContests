#include <bits/stdc++.h>
using namespace std;

int main(){
    string cad;
    while(cin >> cad){
        vector<char> each;
        vector<char> beiju;
        bool parenthesis = false;
        for(int i = 0; i < size(cad); i++){
            if(cad[i] == '['){
                parenthesis = true;
            }else if(cad[i] == ']'){
                parenthesis = false;
            }else if(parenthesis){
                beiju.push_back(cad[i]);
            }else{
                each.push_back(cad[i]);
            }
        }
        vector<char>::iterator sol;
        for(sol=beiju.begin(); sol<beiju.end(); sol++){
            cout <<*sol;
        }
        for(sol = each.begin(); sol<each.end(); sol++){
            cout <<*sol;
        }
        cout<<"\n";
    }
    return 0;
}