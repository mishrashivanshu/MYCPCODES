#include<bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &A) {
    A[A.size()]=0;
    int k=A[A.size()-1]+1;
    A[A.size()-1]=(k%10);
    if(floor(log10(k)+1)>1){
        int carry=1;
        for(int f=A.size()-2;f>=0;f--){
            int l=A[f]+carry;
            if(l>9){
                A[f]=0;
                carry=1;
            }
            else{
                A[f]=l;
                carry=0;
            }
        }
        if(carry==1){
            reverse(A.begin(), A.end());
            A.push_back(1);
            reverse(A.begin(), A.end());
        }
        return A;
    }
    return A;
}
int main(){
    int c;
    cin>>c;
    vector<int> u;
    for(int t=0;t<c;t++){
        int k;
        cin>>k;
        u.push_back(k);
    }
    vector<int> b=plusOne(u);
    for(int a=0;a<b.size();a++){
        cout<<b[a]<<" ";
    }
    return 0;
}
