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
#define Endl printf("\n");
#define vli std::vector<std::list<int>>
#define vvi std::vector<std::vector<int>>
#define vvll std::vector<std::vector<long long>>
#define li std::list<int>
#define vlpi std::vector<std::list<std::pair<int,int>>>
#define vpi std::vector<std::pair<int,int>>
#define vli std::vector<std::list<int>>
#define ma 1000000
#define mod 1000000007
#define mod1 998244353

using namespace std;

int main()
{
    int n;cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) sll(a[i]);
    stack<int> Stack;
    ll M=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]) Stack.push(i);
        else if(a[i+1]>a[i] && Stack.size()){
            if(!((i+1-Stack.top())%2)) return cout<<"NO"<<endl,0;
            else{
                if(a[i+1]>a[Stack.top()]){
                    while(Stack.size() && a[Stack.top()]<=a[i+1]){
                        if(!((i+1-Stack.top())%2)) return cout<<"NO"<<endl,0;
                        M=Stack.top();
                        Stack.pop();
                    }
                    if(!Stack.size() && ((i+1)%2)) return cout<<"NO"<<endl,0;
                }
                else if(a[i+1]==a[Stack.top()]) {M=Stack.top();Stack.pop();}
            }
        }
        else if(a[i+1]>a[i]){  if((i+1)%2)return cout<<"NO"<<endl,0;}
    }
    if(Stack.size()){
            while(Stack.size()){
                if((n-1-Stack.top())%2) return cout<<"NO"<<endl,0;
                Stack.pop();
            }
            cout<<"YES"<<endl;
    }
    else if(a[n-1]<a[M]) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
