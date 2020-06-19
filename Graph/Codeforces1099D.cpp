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
#define lpi list<pii>
#define vlpi vector<lpi>
#define ma 1000000
#define mod 1000000007
#define vli vector<list<int>>
#define li list<int>
#define Endl printf("\n")
#define vi std::vector<int>

using namespace std;
vlpi EdgeList;
bool visited[100000];
ll dist[100000];
ll a[100000];
int depth[100000];
ll b[100000];
void dfs(int u){
    visited[u]=true;
    if(depth[u]%2==0){
        ll ans=1E14;
        for(lpi::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
            if(!visited[i->first]){
                dfs(i->first);
                ans=min(ans,dist[i->first]);
                if(dist[i->first]==1E14) dist[i->first]=dist[u];
            }
        }
        dist[u]=ans;
    }
    else{
        dist[u]=a[u];
        for(lpi::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
            if(!visited[i->first]){
                dfs(i->first);
                if(dist[i->first]==1E14) dist[i->first]=dist[u];

            }
        }

    }



}
void dfs2(int u){
    visited[u]=true;
    for(lpi::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
        b[i->first]=dist[i->first]-dist[u];
        if(!visited[i->first]){
            dfs2(i->first);
        }
    }

}
int main()
{
    int n;cin>>n;
    EdgeList.resize(n,lpi {});
    int p;
    depth[0]=1;
    for(int i=1;i<n;i++){
        si(p);p--;
        depth[i]=depth[p]+1;
        EdgeList[p].push_back(make_pair(i,depth[i]));
    }
    for(int i=0;i<n;i++) sll(a[i]);
    dist[0]=a[0];
    dfs(0);
    memset(visited,false,sizeof visited);
    dfs2(0);
    b[0]=a[0];
    ll sum=0;
    for(int i=0;i<n;i++){
        if(b[i]<0) return cout<<-1<<endl,0;
        sum+=b[i];
    }
    cout<<sum<<endl;



    return 0;
}
