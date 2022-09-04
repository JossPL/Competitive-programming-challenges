#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string a="h-;;_dsfj",b="s____---;;;sdd;;___--",c="d;;;____-----as_;;__--";
	//getline(cin,a);getline(cin,b);getline(cin,c);
	
	// a-z = 97-122
	// A-Z = 65-90
	// _ = 95, ; = 56, - = 45
	
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	
	for(int i=0;i<a.length();i++){
		if(a[i]=='_' || a[i]==';' || a[i]=='-'){
			a.erase( a.begin()+i );
			i--;
		}
	}
		
	for(int i=0;i<b.length();i++){
		if(b[i]=='_' || b[i]==';' || b[i]=='-'){
			b.erase( b.begin()+i );
			i--;
		}
	}
	
	for(int i=0;i<c.length();i++){
		if(c[i]=='_' || c[i]==';' || c[i]=='-'){
			c.erase( c.begin()+i );
			i--;
		}
	}
	
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	
	
	
	return 0;
}
