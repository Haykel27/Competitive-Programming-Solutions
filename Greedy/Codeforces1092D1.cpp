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
    Stack.push(0);
    for(int i=1;i<n;i++){
            if(!Stack.size()) Stack.push(i);
            else if(a[i]%2!=a[Stack.top()]%2){
                if(!(i-Stack.top()%2)) Stack.pop();
                else Stack.push(i);
            }
            else if(Stack.size())Stack.pop();
    }
    if(Stack.size()>1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;



    return 0;
}
