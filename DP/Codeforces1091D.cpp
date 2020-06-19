#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,ll>
#define pli std::pair<ll,int>
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
#define vpi std::vector<std::pair<int,ll>>
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define vli std::vector<li>
#define vlpli vector<list<pli>>
#define lpli list<pli>
#define li std::list<int>
#define Endl printf("\n")
#define ma 1000000
#define mod 998244353
#define Nmax 10000000000000000
#define bitwise 1125899906842623
#define hi cout<<"hi"<<endl

using namespace std;
int x,y,d=1;
void extendedEuclid(int a, int b)
{   if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1; y = y1;
 }
int main()
{
   int n;cin>>n;
   if(n==1) cout<<1<<endl;
   else{
   ll res=0;
   ll fact=1;
   for(int i=1;i<=n;i++){
    fact*=i;
    fact%=mod;
   }
   res=(n-1)*fact;
   res%=mod;
   for(int i=2;i<n;i++){
    extendedEuclid(i,mod);
    ll k=x;
    if(k<0) k+=mod;
    fact=fact*k;
    fact%=mod;
    res-=fact;
    if(res<0) res+=mod;
   }
   cout<<res<<endl;}

    return 0;
}
