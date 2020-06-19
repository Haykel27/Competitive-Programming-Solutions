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
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define vli std::vector<std::list<int>>
#define li std::list<int>
#define lvi list<vi>
#define Endl printf("\n")
#define ma 1000000
#define mod 1000000007

using namespace std;
int main()
{
    int n;cin>>n;
    char c;int x,y,z,M=0,m=0;
    for(int i=0;i<n;i++){
        cin>>c;si(x);si(y);
        z=x;
        x=min(x,y);
        y=max(z,y);
        if(c=='?'){
           if(x>=m && y>=M) printf("YES\n");
           else printf("NO\n");
        }
        else{
            m=max(m,x);
            M=max(M,y);
        }
    }

    return 0;
}
