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
#define vlp vector<list<pli>>
#define ma 1000000
#define mod 1000000007
#define Nmax 1000000

using namespace std;

int main()
{
    int n,m;cin>>n>>m;
    vector<ll> a(n);
    ll x;
    for(int i=0;i<n;i++){
        sll(x);a[i]=x;
    }
    vector<pii> v(m);
    int l,r;
    for(int i=0;i<m;i++){
        si(l);si(r);l--;r--;
        v[i]=make_pair(l,r);
    }
    ll res=0;
    vector<int> res_pos;
    for(int i=0;i<n;i++){
        vector<ll> b=a;
        vector<int> pos;
        for(int j=0;j<m;j++){
            if(i<v[j].first || i>v[j].second){
                for(int k=v[j].first;k<=v[j].second;k++) b[k]--;
                pos.push_back(j);
            }

        }
        ll M=-10000000,m=1000000;
        for(int j=0;j<n;j++){
            M=max(b[j],M);
            m=min(m,b[j]);
        }
        if(M-m>res){
            res_pos=pos;
            res=M-m;
        }
    }
    cout<<res<<endl;
    cout<<res_pos.size()<<endl;
    for(int i=0;i<(int)res_pos.size();i++) cout<<res_pos[i]+1<<" ";
    return 0;
}
