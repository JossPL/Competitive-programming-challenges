/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Hacemos uso de una pila de los nombres de cada persona, notese que 
-test es equivalente a consultar el tope de la pila, que es la ultima persona que se durmio
-sleep es equivalente a insertar a una persona nueva a la pila
-kick es despertar a alguien, es decir, remover el tope de la pila, que es la ultima persona que se durmio
*/

#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    stack<string> names;

    string s1,s2;
    for(int i=0; i<n; i++){
        cin>>s1;
        if(s1.compare("Sleep")==0){
            cin>>s2;
            names.push(s2);
        }else if(s1.compare("Test")==0){
            if(!names.empty()) cout<<names.top()<<endl;
            else cout<<"Not in a dream\n";
        }else if(s1.compare("Kick")==0)
            if(!names.empty()) 
				names.pop();
    }
}

int main(){
    int n; cin>>n;
    solve(n);
    return 0;
}
