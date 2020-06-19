#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,int>
#define psi std::pair<string,int>
#define pli std::pair<ll,int>
#define pll std::pair<ll,ll>
#define pci std::pair<char,int>
#define sll(x) scanf("%I64d",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define pb push_back
#define vll std::vector<ll>
#define ma 1000000
#define mod 1000000007

using namespace std;
int Binary_search(vector<ll> t,int d,int f,ll x){
    while(d<=f){
        int mid=(d+f)/2;
        if(t[mid]==x){
            return mid;
        }
        else if(t[mid]>x) f=mid-1;
        else d=mid+1;
    }
    return -1;
}

int main()
{   int n;cin>>n;
    ll a[n];
    for(int i=1;i<n;i+=2) sll(a[i]);
    ll sum=0;
    int k1=0;
    int k2=0;
    for(int i=1;i<n;i+=2){
        bool bol=true;
        for(ll j=(ll)sqrt(a[i]);j>=1;j--){
            if(a[i]%j==0){
                ll e=j,s=a[i]/j;
                ll a1=(s+e)/2,b1=(s-e)/2;
                a[i-1]=a1*a1-sum-a[i];
                if(b1*b1==sum+a[i-1] && a[i-1]<=10000000000000 && a[i-1]>0){
                    sum+=a[i]+a[i-1];
                    bol=false;
                    break;
                }
            }
        }
        if(bol) return cout<<"No"<<endl,0;

    }
    cout<<"Yes"<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
