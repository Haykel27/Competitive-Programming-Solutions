#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define pii std::pair<int,int>
#define psi std::pair<string,int>
#define pli std::pair<ll,int>
#define pll std::pair<ll,ll>
#define mod 1000000007

using namespace std;
bool f(vector<int> a,vector<int>b){
    return a.size()<b.size();
}
int main()
{
    int n;scanf("%d",&n);
    map<ll,int> problems;
    ll x;
    for(int i=0;i<n;i++){
        scanf("%lld",&x);
        if(problems[x]) problems[x]++;
        else problems[x]=1;
    }
    vector<int> v;
    for(map<ll,int>::iterator i=problems.begin();i!=problems.end();++i){
        v.push_back(i->second);
    }
    sort(v.begin(),v.end());
    //for(int i=0;i<(int)v.size();i++) cout<<v[i]<<" ";cout<<endl;
    ll M=0;
    int nb=1;
    int depart=0;
    n=v.size();
    while(nb<=v[n-1]){
        ll a=0;
        int calc;
        for(int i=depart;i<n;i++){
            if(v[i]<nb) depart=i+1;
            else{if(i==depart) {a+=nb;calc=nb;}
                else if(v[i]>=calc*2){ a+=calc*2;calc*=2;}
            }
        }
        nb++;
        M=max(a,M);
    }
    


    cout<<M<<endl;
    return 0;
}
