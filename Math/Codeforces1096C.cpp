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
using namespace std;

int main()
{
    int T;cin>>T;
    int n;
    for(int t=0;t<T;t++){
        si(n);
        int i=3;
        bool trouve=true;
        while(trouve) {
            long double h=(long double)360.0/(long double)(2*i);
            long double r=n/h;
            if(r*h==n && r==(int)r &&r<i-1) break;
            i++;
        }
        cout<<i<<endl;
    }
    return 0;
}
