/*
Josue Alejandro Perez Lara 
josue.perez@cimat.mx

Este problema esta dividido en dos partes, primeramente calcular la string s y  posteriormente pasarla a decimal.
Para la primera parte para no ir quitando elementos del medio de la string (pues seria demasiado costoso) se crearon "apuntadores"
que nos indican a donde deberiamos mover la nueva mitad. La complejidad de esta parte es O(n), con n la longitud de la string dada.

Posteriormente para calcular el residuo modulo 1e9+7 se realizo un precalculo de cuales son los residuos de todas las potencias de dos en este modulo.
Luego, para cada elemento de la string se ve si es 1 se suma el residuo corresponmdiene al resultado. Se otro modo pasamos a la siguiente potencia.
Nuevamente esta segunda parte del algoritmo tiene complejidad O(n).

Concluimos que la complejidad total del ejercicio es O(tn), con t la cantidad de casos a resolver.
*/


#include <bits/stdc++.h>
using namespace std;

//Algortimo para modulos grandes
int getMod(string str, long long n, long long k){
	// pwrTwo[i] will store ((2^i) % k)
	long long pwrTwo[n];
	pwrTwo[0] = 1 % k;
	for (int i = 1; i < n; i++){
		pwrTwo[i] = pwrTwo[i - 1] * 2;
		pwrTwo[i] %= k;
	}

	// To store the result
	long long res = 0;
	long long i = 0, j = n - 1;
	while (i < n){
		// If current bit is 1
		if (str[j] == '1'){
			// Add the current power of 2
			res += (pwrTwo[i]);
			res %= k;
		}
		i++;
		j--;
	}
	return res;
}

void solve(int t){
	string a, s;
	cin>>a;
	
	int left, right;
	int m1, m2;
	
	if(a.size()%2==1){
		m1=a.size()/2;
		m2=m1;
	}else{
		m1=a.size()/2-1;
		m2=m1+1;
	}
	left=m1-1;
	right=m2+1;
	
	while(m1!=m2 || (m1!=0 && m1!=a.size()-1)){
		if(m1==m2){
			s.push_back(a[m1]);
			m1=left; m2=right;
			left--; right++;
		}else{
			if(a[m1]==a[m2]){
				s.push_back(a[m2]);
				m2=m1;
			}else if(a[m1]=='1' && a[m2]=='0'){
				s.push_back('1');
				m1=m2;
			}else if(a[m1]=='0' && a[m2]=='1'){
				s.push_back('1');
				m2=m1;
			}
		}
	}
	s.push_back(a[m1]);
	
	cout<<"Case #"<<t<<": "<<getMod(s, s.size(), 1000000007)<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    for(int i=1; i<=t; i++)
    	solve(i);
	
	return 0;
}
