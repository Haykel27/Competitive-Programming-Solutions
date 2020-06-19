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
#define ma 1000000
#define mod 1000000007

using namespace std;

int premier(ll x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return 0;
    }
    return 1;
}
ll pow(int x,int y){
    if(y==0) return 1;
else{
    ll a=pow(x,y/2);
    if(y%2) return a*a*x;
    else return a*a;
}
   }
vector<ll> diviseurs(ll x){
    vector<ll> v;
    v.push_back(1);v.push_back(x);
    for(int j=2;j<v[v.size()-1] && !premier(v[v.size()-1]);j++){
        if(x%j==0){
            v.push_back(j);v.push_back(x/j);
        }
    }
    return v;
}

int main()
{
    /*ll n;sll(n);
    vector<ll> v=diviseurs(n);
    int taille=(int) v.size();
    for(int i=0;i<(1<<taille);i++){
        vector<ll> a;
        for(int j=2;j<taille;j++){
            if(i & (1<<j)) a.pb(v[j]);
        }
        double x,y;double z;double o=1-1/n;
        int b=0;
        for(int j=0;j<(int)a.size();j++){
            z=a[j];
            x+=1/z;
            y+=a[j-1]/z;
            b=1;
        }
        if(o>=x && o<=y && b){
            cout<<"yes"<<endl;
        }
    }*/


    int n,m,k;si(n);si(m);si(k);
  int t[n][m];memset(t,0,sizeof t);
  int nb=1;
  for(int j=0;j<m;j++){
    for(int i=0;i<(n-n%2);i+=2){
        t[i][j]=nb;t[i+1][j]=nb;
        nb++;
    }
  }
  if(!t[n-1][0]){
    for(int i=0;i<m-(m%2);i+=2){
        t[n-1][i]=nb;t[n-1][i+1]=nb;nb++;
    }
  }
  if(!t[n-1][m-1]) t[n-1][m-1]=nb-1;
  nb--;
  if(n==2){
    int j=1;
    while(nb>k){
        t[0][j]=1;
        t[1][j]=1;
        j++;
        nb--;
    }
  }
  if(n>2){
  if(n%2){
    int i=2,j=0;
    while(nb>k && j<m){
        if(j%2==0){
            if(i==n-1 && nb>=k){
                t[i][j]=1;t[i][j+1]=1;nb--;j++;
                i=n-2;
            }
            else{t[i][j]=1;
                t[i+1][j]=1;
                i+=2;nb--;
            }

        }
        else{
            if(i<=0 && nb>=k){
                t[i+1][j+1]=1;
                t[i+2][j+1]=1;
                i=2;
                j++;
                nb--;
            }
            else{t[i][j]=1;
                t[i-1][j]=1;
                nb--;
                i-=2;
            }

        }
    }
  }
  else{
      int i=2,j=0;

    while(nb>k && j<m){

        if(j%2==0){
            t[i][j]=1;
            t[i+1][j]=1;
            i+=2;nb--;
            if(i==n && nb>k){
                t[n-1][j+1]=1;t[n-2][j+1]=1;nb--;j++;i=n-3;

            }
        }
        else{
            t[i][j]=1;
            t[i-1][j]=1;
            nb--;
            i-=2;
            if(i<=0 && nb>k){
                t[0][j+1]=1;
                t[1][j+1]=1;
                i=2;
                j++;
                nb--;
            }
        }

    }
  }}
  if(t[n-1][m-1]!=t[n-1][m-2] && t[n-1][m-1]!=t[n-2][m-1]) t[n-1][m-1]=t[n-2][m-1];

  map<int,vector<pii>> res;
  pii p;
  if(n>2){
    for(int j=0;j<m;j++){
        if(j%2==0){
            for(int i=0;i<n;i++){
                p.first=i+1;p.second=j+1;
                res[t[i][j]].push_back(p);
            }
        }
        else{
            for(int i=n-1;i>=0;i--){
                p.first=i+1;p.second=j+1;
                res[t[i][j]].push_back(p);
            }
        }
    }
  }
  else {
    int i;
    for( i=0;i<m;i++){
        if(t[0][i]==1){
            p.first=1;p.second=i+1;
            res[1].push_back(p);
        }
        else{
            break;
        }
    }
    for(int j=i-1;j>=0;j--){
        p.first=2;p.second=j+1;
        res[1].push_back(p);
    }
    for(int j=i;j<m;j++){
        p.first=1;p.second=j+1;
        res[t[0][j]].push_back(p);
        p.first=2;p.second=j+1;
        res[t[1][j]].push_back(p);
    }
  }
  for(map<int,vector<pii>>::iterator i=res.begin();i!=res.end();++i){
    cout<<(i->second).size()<<" ";
    for(int j=0;j<(int)(i->second).size();j++){
        cout<<(i->second)[j].first<<" "<<(i->second)[j].second<<" ";
    }
    cout<<endl;
  }
    return 0;
}
