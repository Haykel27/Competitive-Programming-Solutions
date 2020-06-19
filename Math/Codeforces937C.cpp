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
#define vi vector<int>
#define ma 1000000
#define mod 1000000007
#define Nmax 1000000

using namespace std;
ll a[100000];
vector<pli> v;
int Binary_search(int d,int f,ll x){
    while(d<=f){
        int mid=(d+f)/2;
        if(v[mid].first>=x) {
                if(mid<(int)v.size()-1 && v[mid+1].first<x)
                    return mid+1;
                else if(mid==(int)v.size()-1) return -1;
                else d=mid+1;
        }
        else if(v[mid].first<=x){
            if(mid>0 && v[mid-1].first>x) return mid;
            else if(mid==0) return 0;
            else f=mid-1;
        }
    }
    return -1;

}
int main()
{
    cout.precision(22);
    ll k;double t;ll d;
    cin>>k>>d>>t;
    ll a=(k/d)*d+(k%d!=0)*d;
    double b=k+(a-k)/2.0;
    ll nbre=(ll)t/b;
    t-=nbre*b;
    double res=nbre*a;
    if(t>k) {t-=k;res+=k;res+=2*t;}
    else{res+=t;}
    cout<<res<<endl;
    return 0;
}
