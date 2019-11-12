#include<bits/stdc++.h>
#define ll long int
using namespace std;
void check(ll arr[],ll n){
    ll min=-1;
    set<ll> s;
    for(ll i=n-1;i>=0;i--){
        if(s.find(arr[i])!=s.end()){
            min=i;
        }
        else{
            s.insert(arr[i]);
        }
    }
    if(min==-1){
        cout<<-1<<endl;
    }
    else{
        cout<<min+1<<endl;
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[1000000];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        check(arr,n);
    }
    return 0;
}
