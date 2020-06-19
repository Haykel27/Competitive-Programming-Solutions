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
    int n,m;scanf("%d %d",&n,&m);
    vector<vector<int>> skills(m);
    for(int i=0;i<m;i++) skills[i]={};
    int subject,skill;
    for(int i=0;i<n;i++){
        scanf("%d %d",&subject,&skill);
        subject--;
        skills[subject].push_back(skill);
    }
    for(int i=0;i<m;i++){
        sort(skills[i].begin(),skills[i].end());
    }
    sort(skills.begin(),skills.end(),f);
    vector<vector<int>> skills2(m);
    for(int i=0;i<m;i++){
        vector<int> v;
        for(int j=0;j<(int)skills[i].size();j++){
            if(j==0) v.push_back(skills[i][j]);
            else v.push_back(v[j-1]+skills[i][j]);
        }
        skills2[i]=v;
    }
    /*for(int i=0;i<m;i++){
        for(int j=0;j<(int)skills2[i].size();j++) cout<<skills2[i][j]<<" ";
        cout<<endl;
    }*/
    int taille=1;
    ll M=0;
    int pos=0;
    while(taille<=(int)skills2[m-1].size()){
        ll a=0;
        for(int i=pos;i<m;i++){
            int r=skills2[i].size();
            if(r>taille) a=max(a,a+skills2[i][r-1]-skills2[i][r-1-taille]);
            else if(r==taille) a=max(a,a+skills2[i][r-1]);
            else pos=i;
        }

        M=max(a,M);
        taille++;
    }
    cout<<M<<endl;
    return 0;
}
