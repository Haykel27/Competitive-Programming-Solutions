#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,int>
#define psi std::pair<string,int>
#define pli std::pair<ll,int>
#define pll std::pair<ll,ll>
#define pci std::pair<char,int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define pb push_back
#define vll std::vector<ll>
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define ma 1000000
#define mod 1000000007
using namespace std;
vvi res,v1,v2,v3;
vvi LCS(vi t1,vi t2){
    vvi t[t1.size()+1][t1.size()+1];
    for(int i=0;i<=t1.size();i++){
        for(int j=0;j<=t1.size();j++){
            t[i][j].pb({});
        }
    }
    for(int i=1;i<=t1.size();i++){
        for(int j=1;j<=t1.size();j++){
            if(t1[i-1]==t2[j-1]){

                for(int h=0;h<(int)t[i-1][j-1].size();h++){
                    v1.pb(t[i-1][j-1][h]);
                }
                for(int h=0;h<(int)v1.size();h++) v1[h].pb(t1[i-1]);
                t[i][j]=v1;
                v1.clear();
            }
            else{
                v1=t[i-1][j];v2=t[i][j-1];
                if(v1[0].size()>v2[0].size()) t[i][j]=v1;
                else if(v2[0].size()>v1[0].size()) t[i][j]=v2;
                else{
                    for(int h=0;h<(int)v2.size();h++) {if(find(v1.begin(),v1.end(),v2[h])==v1.end()) v1.pb(v2[h]);}
                    t[i][j]=v1;
                }
                v1.clear();v2.clear();
            }
        }
    }

   return t[t1.size()][t1.size()];

}
int main()
{  ll n;cin>>n;
    int res=0;

    ll a=1,b=1,c;
    int i=0;
    while(a<=n){
        c=a;
        a=a+b;
        b=c;
        i++;
    }
    cout<<i-1<<endl;


    return 0;

}
