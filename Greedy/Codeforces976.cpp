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
#define ma 1000000
#define mod 1000000007
using namespace std;
int  t[1000001];
vector<int> fibonacci;
int dp[1000001][2];

int Binary_search(vector<int>t,int d,int f,int x){
    while(d<=f){
        int mid=(d+f)/2;
        if(t[mid]==x){

            while(t[mid]==t[mid-1] && mid>0) mid++;
            return mid;
        }
        else if(t[mid]>x) f=mid-1;
        else d=mid+1;
    }
    return -1;
}
ll pow(int x,int y){
    if(y==0) return 1;
    else{
        ll a=pow(x,y/2);
        if(y%2) return (a*a*x)%mod;
        else return (a*a)%mod;
    }
}
int play(int n,int player){
    if(t[n]) {return player;}
    else if(dp[n][player]==-1){
        int a;
        for(int i=0;i<(int)fibonacci.size();i++){
            if(fibonacci[i]>=n) break;
            else{
               a=play(n-fibonacci[i],1-player);
               if(a==player){
                dp[n][player]=player;
                break;
               }
            }

        }
        if(dp[n][player]==-1) dp[n][player]=1-player;
        dp[n][1-player]=1-dp[n][player];

    }
    return dp[n][player];
}
int f(vector<int> t,int a,int b,int i,int k){
    if(a==k ) return 1;
    else if(a>k) return 0;
    else if(a+b<k) return 0;
    else{
        int c=f(t,a+t[i],b-t[i],i+1,k);
        if(c) return c;
        else return f(t,a,b-t[i],i+1,k);
    }
}
bool g(vll a,vll b){
    return a[1]<b[1];

}
bool h(vll a,vll b){
    if( a[0]<b[0]) return 1;
    else if(a[0]==b[0]) return a[1]>b[1];
    else return 0;
}
int main()
{   /*string s;cin>>s;
    int n=(int)s.size();
    int nbre_a=0;
    int nb=0;
    vector<int> pos_a;
    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            nb++;
            nbre_a++;
        }
        if(s[i]=='b' && nb){pos_a.pb(nb);nb=0;}
    }
    if(nb) pos_a.pb(nb);
    ll res=1;
    for(int i=0;i<(int)pos_a.size();i++){
        res=(pos_a[i]*res+res)%mod;
    }
    cout<<res-1<<endl;*/
    int n;si(n);
    vector<vll> v(n);
    vector<vll> v2(n);
    ll x,y;
    for(int i=0;i<n;i++){
        sll(x);sll(y);
        v[i]={x,y,i};
        v2[i]={y,x,i};
    }
    //for(int i=0;i<n;i++) cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
    sort(v.begin(),v.end());
    sort(v2.begin(),v2.end());
    for(int i=0;i<n;i++){
        if(v[i][2]!=v2[i][2]){
            return cout<<v2[i][2]+1<<" "<<v[i][2]+1<<endl,0;
        }
        if(i!=n-1 && v[i][0]==v[i+1][0] && v[i][1]==v[i+1][1]) return cout<<v[i+1][2]+1<<" "<<v[i][2]+1<<endl,0;
        if(i!=n-1 && v[i][0]==v[i+1][0] && v[i+1][1]>=v[i][1]) return cout<<v[i][2]+1<<" "<<v[i+1][2]+1<<endl,0;
        if(i!=n-1 && v[i][0]==v[i+1][0] && v[i+1][1]<=v[i][1]) return cout<<v[i+1][2]+1<<" "<<v[i][2]+1<<endl,0;
        if(i!=n-1 && v[i][1]==v[i+1][1] && v[i+1][0]<=v[i][0]) return cout<<v[i][2]+1<<" "<<v[i+1][2]+1<<endl,0;
        if(i!=n-1 && v[i][1]==v[i+1][1] && v[i+1][1]>=v[i][1]) return cout<<v[i+1][2]+1<<" "<<v[i][2]+1<<endl,0;
    }
    cout<<-1<<" "<<-1<<endl;
    return 0;

}
