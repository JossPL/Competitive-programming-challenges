#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;getline(cin,s);
	int d=0;
	auto j =s.rbegin();
	
	for(auto i=s.begin() ; ( i !=  s.end() ) && ( j != s.rend() ) ;i++,j++)
		if( *i != *j)
			d++;
	
	if(d==2 || (d==0  &&  s.length()%2==1))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
		
	return 0;
}
