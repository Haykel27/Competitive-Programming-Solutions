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
#define Endl printf("\n");
#define vli std::vector<std::list<int>>
#define vvi std::vector<std::vector<int>>
#define vvll std::vector<std::vector<long long>>
#define li std::list<int>
#define ma 1000000
#define mod 1000000007
#define mod1 998244353

using namespace std;
ll C[2001][2001];
ll Pow(int x,int y){
    if(y==0) return 1;
    else{
        ll a=Pow(x,y/2);
        cout<<a<<endl;
        if(y%2) return ((a%mod1)*(a%mod1)*x)%mod1;
        else return ((a%mod1)*(a%mod1))%mod1;
    }
}
ll pow1(int x,int y){
    ll a=1;
    for(int i=0;i<y;i++) a=(a*x)%mod1;
    return a;
}
int main()
{   int n,m,k;cin>>n>>m>>k;
    memset(C,0,sizeof C);
    C[0][0]=1;
    for(int i=1;i<=n;i++) C[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod1;
        }
        C[i][i]=1;
    }
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) cout<<C[i][j]<<" ";
        cout<<endl;
    }*/
    if(k==0) cout<<m<<endl;
    else{
        ll a=(C[n-1][k]*m)%mod1;
        a=(a*pow1(m-1,k))%mod1;
        cout<<a<<endl;
        //cout<<pow1(m-1,k)<<endl;
    }

    return 0;
}
