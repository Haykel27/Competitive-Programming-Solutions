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
#define li std::list<int>
#define Endl printf("\n")
#define ma 1000000
#define mod 1000000007
#define Nmax 10000000000000000

using namespace std;
vli EdgeList;
bool visited[100000];
int dist[100000];
ll Pow(ll a,ll b){
    if(b==0) return 1;
    else{
        ll c=Pow(a,b/2);
        if(b%2) return c*c*a;
        else return c*c;
    }
}
int dfs(int u){
    visited[u]=true;
    dist[u]=0;
    int a=0;
    for(li::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
        if(!visited[*i]){
            dfs(*i);
            dist[u]+=dist[*i];

        }
    }
    dist[u]+=(dist[u]==0);
    return dist[u];
}
int main()
{

    int n;cin>>n;
    EdgeList.resize(n,li {});
    int x;
    for(int i=1;i<n;i++){
            si(x);x--;
            EdgeList[x].push_back(i);
    }
    dfs(0);
    sort(dist,dist+n);
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";

    return 0;
}
