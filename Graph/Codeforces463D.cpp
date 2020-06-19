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
#define vli std::vector<std::list<int>>
#define li std::list<int>
#define ma 1000000
#define mod 1000000007
using namespace std;
bool visited[1000];
int Best[1000];
int res=0;

vli Edgelist;
void  dfs(int u){
    visited[u]=true;
    for(li::iterator i=Edgelist[u].begin();i!=Edgelist[u].end();++i){
        if(!visited[*i])
            dfs(*i);
        Best[u]=max(Best[u],Best[*i]+1);

    }
    res=max(res,Best[u]);

}
int main()
{
    int n,k;cin>>n>>k;
    int t[k][n];
    int pos[k][n];
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++) {si(t[i][j]);t[i][j]--;pos[i][t[i][j]]=j;}
    }
    for(int i=0;i<n;i++) Edgelist.pb({});

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bool dimabaadou=true;
            for(int h=0;h<k;h++){
                if(pos[h][j]<=pos[h][i]){dimabaadou=false;break;}
            }
            if(dimabaadou) Edgelist[i].push_back(j);
        }
    }
    memset(visited,false,sizeof visited);
    for(int i=0;i<n;i++) Best[i]=1;
    for(int i=0;i<n;i++){
            if(!visited[i]) dfs(i);
    }
    cout<<res<<endl;


    return 0;

}
