#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,int>
#define psi std::pair<string,int>
#define pli std::pair<ll,int>
#define pll std::pair<ll,ll>
#define pci std::pair<char,int>
#define sll(x) scanf("%I64d",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define pb push_back
#define vll std::vector<ll>
#define ma 1000000
#define mod 1000000007

using namespace std;
vector<int> v1;
int ceilIndex(ll input[], int t[],int End,int s){
    int start=0;
    int len=End;
    int mid;
    while(start<=End){
        mid=(start+End)/2;
        if(mid<len &&  s+1==input[t[mid+1]]) return mid+1;
        else if(s+1==input[t[mid]]) return mid;
        else if(input[t[mid]]<s) start=mid+1;
        else End=mid-1;
    }
    return -1;

}
int longest_increasing_subsequence(ll input[],int n){
    int t[n];
    int R[n];
    memset(R,-1,sizeof R);
    t[0]=0;
    int len=0;
    for(int i=1;i<n;i++){
        if(input[t[len]]+1==input[i]){
            len++;t[len]=i;R[t[len]]=t[len-1];
        }
        else{
            int index=ceilIndex(input,t,len,input[i]);
            if(index!=-1 && index<n){
                t[index]=i;
                R[t[index]]=t[index-1];
            }
        }
    }
    cout<<len+1<<endl;
    int index=t[len];

    while(index!=-1 && index<n){
        v1.push_back(index);
        index=R[index];

    }
    return len;

}

int main()
{   int n;cin>>n;
    ll v[n];
    for(int i=0;i<n;i++) sll(v[i]);
    sort(v,v+n);
    vector<vector<long long>> h;
    for(ll j=1;j<=2000000000;j*=2){
        pii res[n];
        res[0]=make_pair(-1,1);
        map<ll,pair<bool,int>> Map;
        Map[v[0]]=make_pair(true,0);
        for(int i=1;i<n;i++){
            if(Map[v[i]-j].first==true){
                res[i]=make_pair(Map[v[i]-j].second,res[Map[v[i]-j].second].second+1);
            }
            else{
                res[i]=make_pair(-1,1);
            }
            Map[v[i]]=make_pair(true,i);

        }
        int M=0;
        int pos;
        for(int i=0;i<n;i++){
            if(M<res[i].second){
                M=res[i].second;
                pos=i;
            }
        }
        vector<ll> t;
        while(pos!=-1){
            t.push_back(v[pos]);
            pos=res[pos].first;
        }
        h.push_back(t);
    }
    vector<ll> o;
    for(int i=0;i<(int)h.size();i++) if(h[i].size()>o.size()) o=h[i];
    cout<<min(3,(int)o.size())<<endl;
    for(int i=0;i<min(3,(int)o.size());i++) cout<<o[i]<<" ";
    return 0;
}
