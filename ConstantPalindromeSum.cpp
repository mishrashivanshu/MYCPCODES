#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int flag=0;
        int j = arr[0]+arr[n-1];
        for(int i=0;i<n/2;i++)
        {
            if(arr[i]+arr[n-i-1] != j)
                flag=1;
        }
        if(flag == 1)
        {


        int x = k+1;

        ll coun = 0;
        for(int i=0;i<n/2;i++)
        {
            if(arr[i]+arr[n-i-1] != x)
            {
               coun++;
            }
        }
        cout<<coun<<endl;
        }
        else
            cout<<0<<endl;
    }
}
