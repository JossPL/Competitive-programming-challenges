#include <iostream>

using namespace std;

void Numbers_on_whiteboard(){
	
	int n;cin>>n;
	cout<<"2"<<endl;
	if(n>1)
		cout<<n<<" "<<n-1<<endl;
		
	for(int i=n;0<i-2;i--){
		cout<<i<<" "<<i-2<<endl;
	}
}

int main(){
	
	int y;cin>>y;
	while(y--)
		Numbers_on_whiteboard();
	
	return 0;
}
