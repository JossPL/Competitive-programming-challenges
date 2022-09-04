#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int n;cin>>n;
	
	vector <int> A (2);
	vector <int> B (2);
	vector <int> V (2);
	
	cin>>A[0]>>A[1]>>B[0]>>B[1]>>V[0]>>V[1];

	if(	( (B[0]-A[0]) * (V[0]-A[0])>0 )  &&   ( (B[1]-A[1]) * (V[1]-A[1])>0 ))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
		
	return 0;
}
