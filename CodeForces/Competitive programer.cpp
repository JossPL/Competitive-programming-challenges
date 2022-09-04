#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Competitive_programer(){
	
	char digit;
	bool zero=false, three=false, todo_zero=true;
	int sum=0,par=0;
	
	digit=getchar();
	
	while(digit != '\n'){
		
		if(digit == '0')
			zero=true;
		else
			todo_zero=false;
		
		if( digit % 2 == 0)
			par++;	
		sum+=digit-48;
		
		digit=getchar();
	}

	if(sum % 3==0)
		three=true;
	
	if(zero && par>1 && three || todo_zero)
		cout<<"red"<<endl;
	else 
		cout<<"cyan"<<endl;
}

int main(){
	int n;cin>>n;
	getchar();
	while(n--)
		Competitive_programer();
	
	return 0;
}
