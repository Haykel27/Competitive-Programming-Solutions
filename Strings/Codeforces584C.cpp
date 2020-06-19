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
    int n,t;cin>>n;cin>>t;
    string s1,s2;cin>>s1>>s2;
    int tab[26][n];
    memset(tab,0,sizeof tab);
    for(int i=0;i<n;i++){
        if(s1[i]==s2[i]) tab[(int)s1[i]-'a'][i]=3;
        else{
            tab[(int)s1[i]-'a'][i]=1;
            tab[(int)s2[i]-'a'][i]=2;
        }
    }
    string res="";
    for(int i=0;i<n;i++) res+='A';
    int k=0;
    /*for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            if(nb==(n-t)/2+(n-t)%2) break;
            if (tab[i][j]==1) {res[j]=s1[j];nb++;}
        }
        if(nb==(n-t)/2+(n-t)%2) break;
    }
    k+=nb;
    nb=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            if(nb==(n-t)/2+(n-t)%2){ break;}
            if (tab[i][j]==2 && res[j]=='A') {res[j]=s2[j];nb++;}

        }
        if(nb==(n-t)/2+(n-2)%2) break;
    }*/
    k=0;
    for(int i=0;i<26;i++){
        for(int j=0;j<n;j++){
            if(k==n-t) break;
            if (tab[i][j]==3) {res[j]=s2[j];k++;}
        }
        if(k==n-t) break;
    }
    if(k<n-t){
        int nb3=k;
        for(int i=0;i<26;i++){
            for(int j=0;j<n;j++){
                if(nb3==n-t) break;
                if(tab[i][j]==1 && res[j]=='A'){ res[j]=s1[j];nb3++;}
            }
            if(nb3==n-t) break;
        }
        nb3=k;
        for(int i=0;i<26;i++){
            for(int j=0;j<n;j++){
                if(nb3==n-t) break;
                if(tab[i][j]==2 && res[j]=='A'){ res[j]=s2[j];nb3++;}
            }
            if(nb3==n-t) break;
        }
    }
    for(int i=0;i<26;i++){
            for(int j=0;j<n;j++){
                if(tab[i][j]==0 && res[j]=='A') res[j]=(char)((int)'a'+i);
            }
    }
    int nb1=0,nb2=0;
    for(int i=0;i<n;i++){
        if(res[i]==s1[i]) nb1++;
        if(res[i]==s2[i]) nb2++;
        if(res[i]=='A') return cout<<-1<<endl,0;
    }
    if(nb1!=n-t || nb2!=n-t) cout<<-1<<endl;
    else cout<<res<<endl;

    return 0;
}
