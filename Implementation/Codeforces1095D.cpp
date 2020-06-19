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
#define vli std::vector<std::vector<std::pair<int,ll>>>
#define li std::list<pii>
#define Endl printf("\n")
#define ma 1000000
#define mod 1000000007
#define Nmax 10000000000000000

using namespace std;
ll Pow(ll a,ll b){
    if(b==0) return 1;
    else{
        ll c=Pow(a,b/2);
        if(b%2) return c*c*a;
        else return c*c;
    }
}
int main()
{

    int n;cin>>n;
    vector<pii> v(n);
    list<int> l;
    int c,b;
    pii p;
    for(int i=0;i<n;i++){
        si(c);si(b);c--;b--;
        p.first=c;p.second=b;
        v[i]=p;

    }
    /*map<int,bool> Map;
    for(int i=0;i<n;i++){
        if(!Map[i]){
           if(!l.size()){
                l.push_front(i);
                if(v[i].first==v[v[i].second].first || v[i].first==v[v[i].second].second){
                    l.push_back(v[i].second);
                    l.push_back(v[i].first);
                     Map[i]=true;
                     Map[v[i].first]=true;
                    Map[v[i].second]=true;
                }
                else{
                    l.push_back(v[i].first);
                    l.push_back(v[i].second);

                }
            }
            else{
                auto it=next(l.begin(),0);
                auto it1=next(l.begin(),1);
                auto it2=next(l.begin(),l.size()-1);
                if(*it==v[i].first) {
                        if(*it1==v[i].second) l.push_front(i);
                        else {l.push_front(v[i].second);l.push_front(i);}
                }
                else if(*it==v[i].second){
                    if(*it1==v[i].first) l.push_front(i);
                    else{l.push_front(v[i].first);l.push_front(i);}
                }
                else{
                    int avant,apres;
                    if(v[i].first==v[v[i].second].first || v[i].first==v[v[i].second].second){avant=v[i].second;apres=v[i].first;}
                    else {avant=v[i].first;apres=v[i].second;}
                    if(*it==v[avant].first || *it==v[avant].second){ l.push_front(i);l.push_front(avant);l.push_front(apres);}
                    else if(v[*it2].first==i || v[*it2].second==i){l.push_back(i);l.push_back(avant);l.push_back(apres);}
                }
            }
        }
    }
    for(list<int>::iterator i=l.begin();i!=l.end();++i){
        cout<<*i+1<<" ";
    }*/
    queue<int> Stack;
    Stack.push(0);
    map<int,bool> Map;
    while(Stack.size()&& (int) l.size()<n){
        int avant,apres;

        int u=Stack.front();Stack.pop(); bool e=Map[u];if(!Map[u]) {l.push_back(u);Map[u]=true;}
        if(!e){
        if(v[u].first==v[v[u].second].second || v[u].first==v[v[u].second].first){avant=v[u].second;apres=v[u].first;}
        else {avant=v[u].first;apres=v[u].second;}
        if(!Map[avant])Stack.push(avant);
        if(!Map[apres]) Stack.push(apres);
        }


    }
    for(list<int>::iterator i=l.begin();i!=l.end();++i){
        cout<<*i+1<<" ";
    }
    return 0;
}
