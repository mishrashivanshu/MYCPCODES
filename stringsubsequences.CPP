#include<bits/stdc++.h>
using namespace std;
void subsequences(string str,string curr=" ",int index=0){
    if(index==str.size()){
        cout<<curr<<" ";
        return ;
    }
    subsequences(str,curr,index+1);
    subsequences(str,curr+str[index],index+1);
}
int main(){
    string c;
    cin>>c;
    subsequences(c);
    cout<<endl;
    return 0;
}
