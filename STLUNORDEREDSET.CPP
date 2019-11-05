#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> s;
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
    int y;
    cin>>y;
    if(s.find(y)!=s.end()){
        cout<<y<<" is present."<<endl;
    }
    else{
        cout<<y<<" is not present."<<endl;
    }
    return 0;
}
