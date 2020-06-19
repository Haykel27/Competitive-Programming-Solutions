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
#define Endl printf("\n")
#define ma 1000000
#define mod 1000000007
using namespace std;
vector<list<int>> EdgeList;
bool visited[1000000];
int region[1000000];
int reg=0;
vector<int> a;
int n,m;
vector<string> v;
int res=0;
void dfs(int i,int j){
    visited[m*i+j]=true;
    region[m*i+j]=reg;
    if(i>0 && v[i-1][j]=='*') res++;
    if(i<n-1 && v[i+1][j]=='*') res++;
    if(j>0 && v[i][j-1]=='*') res++;
    if(j<m-1 && v[i][j+1]=='*') res++;
    if(i>0 && v[i-1][j]=='.' && !visited[(i-1)*m+j]) dfs(i-1,j);
    if(i<n-1 && v[i+1][j]=='.' && !visited[(i+1)*m+j]) dfs(i+1,j);
    if(j>0 && v[i][j-1]=='.' && !visited[i*m+j-1]) dfs(i,j-1);
    if(j<m-1 &&  v[i][j+1]=='.' && !visited[i*m+j+1]) dfs(i,j+1);

}

int main()
{
   int k;cin>>n>>m>>k;

   string s;
   for(int i=0;i<n;i++){
    cin>>s;
    v.push_back(s);
   }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(v[i][j]=='.' && !visited[i*m+j]) {res=0;dfs(i,j);a.push_back(res);reg++;}
    }
   }
   int u,v;
   for(int i=0;i<k;i++){
    si(u);si(v);u--;v--;
    printf("%d\n",a[region[u*m+v]]);
   }
    return 0;
}
