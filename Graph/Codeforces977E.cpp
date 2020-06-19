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
vli Edgelist;
vi v1;
int taille;
bool visited[200000];
int dfs(int u){
    visited[u]=true;
    int a=(Edgelist[u].size()==2);
    for(li::iterator i=Edgelist[u].begin();i!=Edgelist[u].end();++i)
        if(!visited[*i]) a=min(a,dfs(*i));

    return a;

}
int main()
{

    int n,m;cin>>n>>m;
    Edgelist.resize(n,li {});
    int u,v;
    for(int i=0;i<m;i++){
        si(u);si(v);
        u--;v--;
        Edgelist[u].push_back(v);
        Edgelist[v].push_back(u);
    }
    memset(visited,false,sizeof visited);
    int res=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            taille=0;v1.clear();
            if(dfs(i)) res++;


        }
    }
    cout<<res<<endl;

    return 0;
}
