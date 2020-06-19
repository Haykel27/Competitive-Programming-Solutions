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
#define ma 1000000
#define mod 1000000007
#define mod1 998244353

using namespace std;

int main()
{
   int n;cin>>n;
   vector<string> v(2*n-2);
   string s;
    vector<string> v1;
    int S,P;
   for(int i=0;i<2*n-2;i++){
    cin>>s;v[i]=s;
   }
   for(int i=0;i<2*n-2;i++){
    if((int)v[i].size()==n-1){
        for(int j=i+1;j<2*n-2;j++){
            if((int)v[j].size()==n-1){
                S=i;P=j;
                v1.pb(v[i]);v1.pb(v[j]);
                break;
            }
        }
        break;
    }
   }
   string s1="";
   s1+=v1[1];
   s1+=v1[0][n-2];
   string s2="";
   s2+=v1[0];s2+=v1[1][n-2];
   string res1="";
   string ch4="";
   bool t[2*n-2];
   memset(t,true,sizeof t);
   for(int i=0;i<2*n-2;i++) res1+='E';
   res1[S]='S';
   res1[P]='P';
   for(int i=0;i<n-2;i++){
    ch4+=s1[i];

    for(int j=0;j<(2*n)-2;j++){
        if(t[j] && ch4==v[j]) {res1[j]='P';t[j]=false;break;}
    }
   }
   ch4="";
   for(int j=n-1;j>1;j--){
    ch4=s1[j]+ch4;
    for(int i=0;i<2*n-2;i++){
        if(t[i] && ch4==v[i]){
            res1[i]='S';t[i]=false;
            break;
        }
    }
   }
   memset(t,true,sizeof t);
   string res2="";
   ch4="";
   for(int i=0;i<2*n-2;i++) res2+='E';
   res2[P]='S';
   res2[S]='P';
   for(int i=0;i<n-2;i++){
    ch4+=s2[i];
    for(int j=0;j<(2*n)-2;j++){
        if(t[j] && ch4==v[j]) {res2[j]='P';t[j]=false;break;}
    }
   }
   ch4="";
   for(int j=n-1;j>1;j--){
    ch4=s2[j]+ch4;
    for(int i=0;i<2*n-2;i++){
        if(t[i] && ch4==v[i]){
            res2[i]='S';t[i]=false;
            break;
        }
    }
   }
   for(int i=0;i<2*n-2;i++) if(res1[i]=='E') return cout<<res2<<endl,0;
    cout<<res1<<endl;
    return 0;
}
