#include<bits/stdc++.h>
#define print(c) for(int i=0;i<c.size();i++){cout<<c[i]<<" ";}
using namespace std;
int countvowels(string g){
    int count1=0;
    for(int i=0;i<g.size();i++){
        if(g[i]=='a'||g[i]=='e'||g[i]=='i'||g[i]=='o'||g[i]=='u'){
            count1++;
        }
    }
    return count1;
}
int countconsonants(string g){
    int count2=0;
    for(int i=0;i<g.size();i++){
        if(g[i]!='a'&&g[i]!='e'&&g[i]!='i'&&g[i]!='o'&&g[i]!='u'){
            count2++;
        }
    }
    return count2;
}
//string ko char me change karne ke liye
vector<char> toconvert(vector<string> j){
    vector<char> new1;
    for(int i=0;i<j.size();i++){
        string h=j[i];
        for(int o=0;o<h.size();o++){
            new1.push_back(h[o]);
        }
    }
    return new1;
}
//unique banane ke liye
vector<char> makeunique(vector<char> v){
    sort(v.begin(),v.end());
    vector<char> f;
    for(int u=0;u<v.size();u++){
        if(v[u]!=v[u+1]){
            f.push_back(v[u]);
        }
    }
    return f;
}
//kya contain karti hai?
bool does(string aorb, char x){
    for(int i=0;i<aorb.size();i++){
        if(aorb[i]==x){
            return true;
        }
    }
    return false;
}
//no of recepies that contain c
int no(vector<string> f, char c){
    int count1=0;
    for(int i=0;i<f.size();i++){
        if(does(f[i],c)){
            count1++;
        }
    }
    return count1;
}
//total number of occurences ka square
int totaloccurences(vector<string> v,char c){
    int count1=0;
    for(int i=0;i<v.size();i++){
        string h=v[i];
        for(int j=0;j<h.size();j++){
            if(h[j]==c){
                count1++;
            }
        }
    }
    return count1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int l;
        cin>>l;
        vector<string> c;
        while(l--){
            string g;
            cin>>g;
            c.push_back(g);
        }
        vector<string> a;
        vector<string> b;
        for(int i=0;i<c.size();i++){
            if(countvowels(c[i])>=countconsonants(c[i])){
                a.push_back(c[i]);
            }
            else{
                b.push_back(c[i]);
            }
        }
        /*print(a);
        cout<<endl;
        print(b);
        cout<<endl;*/
            int n=a.size();//alice ki recepies
            int m=b.size();//bob ki recepies
           // cout<<n<<" "<<m<<endl;
            vector<char> a1=toconvert(a);
            vector<char> b1=toconvert(b);
            vector<char> ua=makeunique(a1);
            vector<char> ub=makeunique(b1);
            vector<double> foralicexc;
            vector<double> forbobxc;
            for(int i=0;i<ua.size();i++){
                foralicexc.push_back(no(a,ua[i]));
            }
            for(int i=0;i<ub.size();i++){
                forbobxc.push_back(no(b,ub[i]));
            }
            vector<double> foralicefx;
            vector<double> forbobfx;
            for(int i=0;i<ua.size();i++){
                foralicefx.push_back(pow(totaloccurences(a,ua[i]),n));
            }
            for(int i=0;i<ub.size();i++){
                forbobfx.push_back(pow(totaloccurences(b,ub[i]),m));
            }
            double sca=1.0;
            for(int i=0;i<ua.size();i++){
                double t=foralicexc[i]/foralicefx[i];
                sca=sca*(t);
            }
            double scb=1.0;
            for(int i=0;i<ub.size();i++){
                double t1=forbobxc[i]/forbobfx[i];
                scb=scb*(t1);
            }
           /*print(foralicexc);
            cout<<endl;
            print(foralicefx);
            cout<<endl;
            print(forbobxc);
            cout<<endl;
            print(forbobfx);
            cout<<endl;*/
            //cout<<endl;
            //cout<<sca<<" "<<scb<<endl;
            if(sca/scb<=10000000){
            printf("%0.7f", sca/scb);
            printf("\n");
            }
            else{
                cout<<"Infinity"<<endl;
            }
            //cout<<sca/scb<<endl;
    }
    return 0;
}
