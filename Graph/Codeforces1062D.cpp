#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mod 1000000007
using namespace std;
int Binary_search(vector<int> t,int d,int f,int x){
    while(d<=f){
        int mid=(d+f)/2;
        if(t[mid]==x){

            while(t[mid]==t[mid-1] && mid>0) mid--;
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
        if(y%2==0){
            ll a=pow(x,y/2);
            return (a*a)%mod;
        }
        else{
            ll a=pow(x,y/2);
            return (a*a*x)%mod;
        }
    }
}
ll pgcd(ll a,ll b){
    if(b==0) return(a);
    else if(a%b==0) return b;
    else{
        return pgcd(b,a%b);
    }
}
ll ppcm(ll a,ll b){
    return(a*b)/pgcd(max(a,b),min(a,b));
}
int prime(ll a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0) return 0;
    }
    return 1;
}
int premier(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int main()
{
   /*ll la,ra,ta,lb,rb,tb;
   scanf("%lld %lld %lld %lld %lld %lld",&la,&ra,&ta,&lb,&rb,&tb);
   int k1=0;ll res=0;
   while(ra<lb) {la+=ta;ra+=ta;}
   while(rb<la){rb+=tb;lb+=tb;}
   while(k1*ta<=ppcm(ta,tb)-ra){
    for(int k2=max(0ll,(la+k1*ta-rb)/tb);k2<=(ra+k1*ta-lb)/tb;k2++){
        res=max(res,min(ra+k1*ta,rb+k2*tb)-max(la+k1*ta,lb+k2*tb)+1);
    }
    k1++;
   }
   cout<<res<<endl;*/

  int n;scanf("%d",&n);int k;
  ll res=0;
  for(int i=2;i<=n;i++){
    k=2;
    if(i){
        while(i*k<=n){
            res+=k;
            k++;
        }
    }
  }
  cout<<4*res<<endl;

   return 0;
}
