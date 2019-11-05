#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,int> mp;
    mp.insert(pair<int, int>(1, 40));
    mp.insert(pair<int, int>(2, 30));
    mp.insert(pair<int, int>(3, 60));
    mp.insert(pair<int, int>(4, 20));
    mp.insert(pair<int, int>(5, 50));
    mp.insert(pair<int, int>(6, 50));
    mp.insert(pair<int, int>(7, 10));
    cout<<"KEY"<<"  "<<"ELEMENT"<<endl;
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        cout<<itr->first<<"     "<<itr->second<<endl;
    }
    return 0;
}
