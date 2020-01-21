#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
#define int cpp_int
#define F first
#define S second
#define pb push_back
#define p pair
#define ld long double
using namespace std;
using boost::multiprecision::cpp_int;
int fibo(int n){
	if(n==0||n==1){
		return n;
	}
	int a=0;
	int b=1;
	int c;
	for(int i=2;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	//O(n);
	return c;
}
void solve(){
	int n;
	cin>>n;
	cout<<fibo(n-1)<<endl;
	return;
}
int32_t main(){/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif*/
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
return 0;
}