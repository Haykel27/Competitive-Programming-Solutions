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
    int rep;
    ll testa=0,testb=0;
    ll a=0,b=0;
    vector<int> kifkif;
    cout<<"?"<<" "<<0<<" "<<0<<endl;
    cin>>rep;
    int sup;
    int c=1;
    if(rep==1) sup=1;
    else if(rep==-1) sup=-1;
    else{
        for(int j=29;j>=0;j--) kifkif.pb(j);
        c=0;
    }

    if(c){
        for(int j=29;j>=0;j--){
            cout<<"? "<<testa+(1<<j)<<" "<<testb+(1<<j)<<endl;
            cin>>rep;
            if(sup==rep){
                kifkif.pb(j);
            }
            else if(rep!=0){
                if(sup==1){
                    a+=(1<<j);
                    testa+=(1<<j);
                    cout<<"? "<<testa<<" "<<testb<<endl;
                    cin>>rep;
                    if(rep==1) sup=1;
                    else if(rep==-1) sup=-1;
                    else{
                        for(int i=j-1;i>=0;i--) kifkif.pb(i);
                        break;

                    }
                }
                else{
                    sup=1;
                    b+=(1<<j);
                    testb+=(1<<j);
                    cout<<"? "<<testa<<" "<<testb<<endl;
                    cin>>rep;
                    if(rep==1) sup=1;
                    else if(rep==-1) sup=-1;
                    else{
                        for(int i=j-1;i>=0;i--) kifkif.pb(i);
                        break;
                    }
                }
            }
            else{
                for(int i=j;j>=0;j--) kifkif.pb(i);
                break;
            }
        }
    }
    for(int i=0;i<(int)kifkif.size();i++){
        cout<<"? "<<testa+(1<<kifkif[i])<<" "<<testb<<endl;
        cin>>rep;
        if(rep==-1){
            testa+=(1<<kifkif[i]);
            testb+=(1<<kifkif[i]);
            a+=(1<<kifkif[i]);
            b+=(1<<kifkif[i]);
        }
    }
    cout<<"! "<<a<<" "<<b<<endl;

    /*ll l=201848071;
    for(int i=29;i>=0;i--){
        if((1<<i) & l) cout<<1;
        else cout<<0;
    }*/

    return 0;
}
