#include<iostream>
#include <string>

using namespace std;

int main(){
	
	string s;getline(cin,s);
	int min=-1;
	
	for(int i=0;i<s.length();i++){
		if(s[i]>=97)
			min=i;
	}
	
	if(min<0){
		for(int i=0;i<s.length();i++)
				printf("%c",s[i]+32);
	}
	if(min==0){
		printf("%c",s[0]-32);
		for(int i=1;i<s.length();i++)
				printf("%c",s[i]+32);
	}
	if(min>0)
		cout<<s;
	
	return 0;
}
