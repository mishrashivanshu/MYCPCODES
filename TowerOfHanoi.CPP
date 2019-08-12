#include<bits/stdc++.h>
using namespace std;
void towers(int n,char frompeg,char topeg,char auxpeg){
	if(n==1){
		cout<<"Move disk "<<n<<" from peg "<<frompeg<<" to peg "<<topeg<<endl;
		return;
	}
	towers(n-1,frompeg,auxpeg,topeg);
	cout<<"Move disk "<<n<<" from peg "<<frompeg<<" to peg "<<topeg<<endl;
	towers(n-1,auxpeg,topeg,frompeg);
	return;
}
int main(){
	int n;
	cin>>n;
	towers(n,'A','B','C');
	return 0;	
}
