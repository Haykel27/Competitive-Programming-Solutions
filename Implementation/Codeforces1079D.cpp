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
#define Endl printf("\n");
#define vli std::vector<std::list<int>>
#define vvi std::vector<std::vector<int>>
#define vvll std::vector<std::vector<long long>>
#define vi std::vector<int>
#define li std::list<int>
#define ma 1000000
#define mod 1000000007
#define mod1 998244353

using namespace std;

int main()
{
    cout.precision(17);
    ll a,b,c;cin>>a>>b>>c;
    ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    double distance1=abs(x2-x1)+abs(y2-y1);
    double y1Fixe,y2Fixe,x1Fixe,x2Fixe;
     if(b) y1Fixe=(double)(-c-a*x1)/b;
     if(a) x1Fixe=(double)(-c-b*y1)/a;
     if(b) y2Fixe=(double)(-c-a*x2)/b;
    if(a) x2Fixe=(double)(-c-b*y2)/a;
    double distance2,distance3,distance4,distance5;
    if(b) distance2=abs(y1-y1Fixe)+abs(y2-y2Fixe)+sqrt(pow(x1-x2,2)+pow(y1Fixe-y2Fixe,2));else distance2=distance1;
    if(a && b) distance3=abs(y1-y1Fixe)+abs(x2-x2Fixe)+sqrt(pow(x1-x2Fixe,2)+pow(y1Fixe-y2,2));else distance3=distance1;
    if(a && b) distance4=abs(x1-x1Fixe)+abs(y2-y2Fixe)+sqrt(pow(x1Fixe-x2,2)+pow(y1-y2Fixe,2)); else distance4=distance1;
    if(a) distance5=abs(x1-x1Fixe)+abs(x2-x2Fixe)+sqrt(pow(x1Fixe-x2Fixe,2)+pow(y1-y2,2));else distance5=distance1;
    double distance=min(distance2,distance1);
    distance=min(distance,distance3);
    distance=min(distance,distance4);
    distance=min(distance,distance5);
    cout<<distance<<endl;
    return 0;
}
