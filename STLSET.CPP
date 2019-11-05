#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        s.insert(t);
    }
    for(auto itr=s.begin();itr!=s.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
    //cout<<"Enter the value to find: ";
    int f;
    cin>>f;
    if(s.find(f)!=s.end()){
        cout<<f<<" "<<"is present."<<endl;
    }
    else{
        cout<<f<<" "<<"is not present."<<endl;
    }
    return 0;
}
