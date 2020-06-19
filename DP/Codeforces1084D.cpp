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
#define mod 1000000007
#define Nmax 10000000000000000

using namespace std;
vlpli EdgeList;
bool visited[300000];
ll dist[300000];
ll gasoil[300000];
ll Pow(ll a,ll b){
    if(b==0) return 1;
    else{
        ll c=Pow(a,b/2);
        if(b%2) return c*c*a;
        else return c*c;
    }
}
ll dfs(int u){
    visited[u]=true;
    ll max1=0,max2=0;
    ll a;
    for(lpli::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
        if(!visited[(*i).first]){
            a=dfs((*i).first)+gasoil[(*i).first]-(*i).second;
            if(a>=max1){max2=max1;max1=a;}
            else if(a>max2){max2=a;}

        }
    }
    dist[u]+=max1+max2;
    return max1;

}
int main()
{

    int n;cin>>n;
    EdgeList.resize(n,lpli {});
    for(int i=0;i<n;i++) sll(gasoil[i]);
    int u,v;ll w;
    pli p;
    for(int i=0;i<n-1;i++){
            si(u);si(v);u--;v--;sll(w);p.first=v;p.second=w;
            EdgeList[u].push_back(p);
            p.first=u;
            EdgeList[v].push_back(p);
    }
    for(int i=0;i<n;i++) {dist[i]=gasoil[i];}
    dfs(0);
    sort(dist,dist+n);
    cout<<dist[n-1]<<" ";

    return 0;
}
