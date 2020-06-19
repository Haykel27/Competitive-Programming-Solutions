#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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
  map<string,int> indices;
  indices["00"]=0;
  indices["01"]=1;
  indices["10"]=2;
  indices["11"]=3;
  vector<vector<int>> v(4);
  for(int i=0;i<4;i++) v[i]={};
  int n;cin>>n;
  string s;int a;
  for(int i=0;i<n;i++){
    cin>>s>>a;v[indices[s]].push_back(a);
  }
  for(int i=0;i<4;i++){
    sort(v[i].begin(),v[i].end());
  }
  int m=min(v[1].size(),v[2].size());
  ll res=0;
  int nb=0;
  for(int j=0;j<(int)v[3].size();j++) {res+=v[3][j];nb++;}
  for(int i=2;i>0;i--){
    for(int j=(int)v[i].size()-1;j>=max(0,(int)v[i].size()-m);j--){
        res+=v[i][j];
        nb++;
    }
  }
    int bonus=0;
    while(2*(m+(int)v[3].size())>(bonus+nb)) bonus++;
    int pos1=v[0].size()-1;
    int pos2=(v[1].size()>v[2].size())?v[1].size()-m-1:v[2].size()-m-1;
    int tab=(v[1].size()>v[2].size())?1:2;
    while(bonus>0 && (pos2>=0 || pos1>=0)){
        if(pos2<0) {res+=v[0][pos1];pos1--;}
        else if(pos1<0){res+=v[tab][pos2];pos2--;}
        else{
            if(v[tab][pos2]>v[0][pos1]){
                res+=v[tab][pos2];pos2--;
            }
            else{
                res+=v[0][pos1];pos1--;
            }
        }
        bonus--;
    }
    cout<<res<<endl;


    return 0;
}
