#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        // int n;
        // cin>>n;
        string s;
        cin>>s;
        int x; cin>>x;
        vector<char> a(s.size(),'9');
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(i-x>=0){
                    a[i-x]='0';
                }
                if(i+x<s.size()){
                    a[i+x]='0';
                }
            }
        }
        int c=0;
        for(int i=0;i<a.size();i++){
            if(s[i]=='1'){
                if(i-x>=0 && a[i-x]!='0'){
                    a[i-x]='1';
                }
                else if(i+x<s.size() && a[i+x]!='0'){
                    a[i+x]='1';
                }
                else{
                    c=1;
                    break;
                }
            }
        }
        if(c==1){
            cout<<-1<<"\n";
            continue;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]=='9'){
                a[i]='0';
            }
        }
        for(int i=0;i<a.size();i++){
            cout<<a[i];
        }
        cout<<"\n";
    }
    return 0;
}
