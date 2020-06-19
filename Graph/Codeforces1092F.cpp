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
#define hi cout<<"hi"<<endl

using namespace std;
vli EdgeList;
ll sum=0;
bool visited[300000];
int dist[300000];
ll cout_enfant[300000];
ll cost[300000];
int a[300000];
void dfs1(int u){
    visited[u]=true;
    for(li::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
        if(!visited[*i]){
            dfs1(*i);
            cout_enfant[u]+=cout_enfant[*i]+a[*i];
        }
    }
}
void dfs2(int u){
    visited[u]=true;
    for(li::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
        if(!visited[*i]){
            cost[0]+=cout_enfant[*i]+a[*i];
            dfs2(*i);
        }
    }

}
void dfs3(int u){
    visited[u]=true;
    for(li::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
        if(!visited[*i]){
            cost[*i]=cost[u]-2*cout_enfant[*i]-2*a[*i]+sum;
            dfs3(*i);
        }
    }

}


int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++){si(a[i]);sum+=a[i];}
    EdgeList.resize(n,li {});
    int u,v;
    for(int i=0;i<n-1;i++){
        si(u);si(v);u--;v--;
        EdgeList[u].push_back(v);
        EdgeList[v].push_back(u);
    }
    dfs1(0);
    memset(visited,false,sizeof visited);
    dfs2(0);
    memset(visited,false,sizeof visited);
    dfs3(0);
    sort(cost,cost+n);
    cout<<cost[n-1]<<endl;

    return 0;
}
