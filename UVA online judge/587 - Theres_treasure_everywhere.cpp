/*
Josue Alejandro Perez Lara
josue.perez@cimat.mx

Para cada una de las instrucciones se realizo el movinmiento que describe. 
Para calcular la distancia se calculo la hipotenusa del triangulo resultante despues de todos los pasos.

Este algoritmo tiene complejidad O(n) donde n es el numero de direcciones distintas que hay que moverse.
*/

#include<bits/stdc++.h>
#include<cmath>

using namespace std;

double x=0,y=0;

void apply_inst(string inst){
	// i guarda la posicion del ultimo digito
	int i;  for(i=inst.size()-1;'A'<=inst[i];i--);
	
	int pasos=stoi(inst.substr(0,i+1));
	string dir=inst.substr(i+1,inst.size()-i);
		
	if(dir=="N"){
		y+=pasos;
		return;
	}
	if(dir=="S"){
		y-=pasos;
		return;
	}
	if(dir=="W"){
		x-=pasos;
		return;
	}
	if(dir=="E"){
		x+=pasos;
		return;
	}
	//Avanzar un paso en alguna direccion diagonal significa aumentar 1/sqrt(2) a cada una de las direcciones.
	if(dir=="NE"){
		x+=(pasos/sqrt(2));
		y+=(pasos/sqrt(2));
		return;
	}
	if(dir=="SE"){
		x+=(pasos/sqrt(2));
		y-=(pasos/sqrt(2));
		return;
	}
	if(dir=="NW"){
		x-=(pasos/sqrt(2));
		y+=(pasos/sqrt(2));
		return;
	}
	if(dir=="SW"){
		x-=(pasos/sqrt(2));
		y-=(pasos/sqrt(2));
		return;
	}	
}

int main(){
	string s;cin>>s;
	int k=1;
	while(s!= "END"){
		int n=s.size();
		vector<string> vinstr;
		string instr;
		for(int i=0;i<n;i++){
			if(s[i]==','||s[i]=='.'){
				vinstr.push_back(instr);
				instr.clear();
				continue;
			}
			instr.push_back(s[i]);
		}
		
		for(int i=0;i<vinstr.size();i++)
			apply_inst(vinstr[i]);
		
		
		cout<<"Map #"<<k<<endl;
		cout<<fixed<<setprecision(3);
		cout<<"The treasure is located at ("<<x<<","<<y<<")."<<endl;
		cout<<"The distance to the treasure is "<<hypot(x,y)<<"."<<endl;
		cout<<endl;
		
		k++;
		x=0;y=0;
		cin>>s;
	}
	
	return 0;
}
