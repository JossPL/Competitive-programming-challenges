#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

void Sequence_with_digits(){
	
	long long a, K;		cin>>a>>K;
	
	for(int i=1;i<K;i++){		
		string Sa=to_string(a);
		sort(Sa.begin(),Sa.end());

		int min_dig= Sa[0]-48, max_dig=Sa[Sa.size()-1]-48;
		a=a+max_dig*min_dig;
	}
	
	cout<<a<<endl;
	
}

int main(){
	int t;cin>>t;
	while(t--)
		Sequence_with_digits();
	return 0;
}
