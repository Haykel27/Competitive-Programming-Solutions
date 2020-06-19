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
bool visited1[300000];
bool visited2[300000];
int dist1[300000];
int dist2[300000];
ll Pow(ll a,ll b){
    if(b==0) return 1;
    else{
        ll c=Pow(a,b/2);
        if(b%2) return c*c*a;
        else return c*c;
    }
}
ll dfs1(int u,int p){
    visited1[u]=true;
    dist1[u]=p;
    ll ans=(p==1)?2:1;
    int p1=(p==1)?2:1;
    for(li::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
        if(!visited1[*i]){
            ll a=dfs1(*i,p1);
            if(a==0) return 0;
            ans*=a;
        }
        if(dist1[*i]==p) return 0;
        ans%=mod;
    }
    return ans;
}
ll dfs2(int u,int p){
    visited2[u]=true;
    dist2[u]=p;
    ll ans=(p==1)?2:1;
    int p1=(p==1)?2:1;
    for(li::iterator i=EdgeList[u].begin();i!=EdgeList[u].end();++i){
        if(!visited2[*i]){
            ll a=dfs2(*i,p1);
            if(a==0) return 0;
            ans*=a;
        }
        if(dist2[*i]==p) return 0;
        ans%=mod;
    }
    return ans;
}
int main()
{

   int n;cin>>n;
   pii a[n];
   int x;
   for(int i=0;i<n;i++) {si(x);a[i]=make_pair(x,i);}
   vpi res;
   sort(a,a+n,greater<pii>());
   int i=0;
   int taille=0;
   while(a[i].first>0 && i<n-1){
    res.push_back(make_pair(a[i].second,a[i+1].second));
    a[i].first--;
    a[i+1].first--;
    i++;
    taille++;
   }
   i++;
   int j=0;
   if(i<n) taille++;
   if(i<n){
        while(a[j].first>0 && i<n){
            while(a[j].first>0 && i<n){
                res.push_back(make_pair(a[j].second,a[i].second));
                a[j].first--;
                a[i].first--;
                i++;
           }
            j++;
        }
   }
   if((int)res.size()==n-1){
    cout<<"YES "<<taille<<endl;
    cout<<n-1<<endl;
    for(int i=0;i<n-1;i++) cout<<res[i].first+1<<" "<<res[i].second+1<<endl;
   }
   else cout<<"NO"<<endl;


    return 0;
}
