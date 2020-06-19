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
#define vvi std::vector<std::vector<int>>
#define vli std::vector<std::list<int>>
#define li std::list<int>
#define Endl printf("\n")
#define ma 1000000
#define mod 1000000007

using namespace std;

int main()
{   int n;cin>>n;
   string s;cin>>s;
   int nb1=0,nb2=0,nb3=0;
   for(int i=0;i<n;i++){
    if(s[i]=='0') nb1++;
    if(s[i]=='1') nb2++;
    if(s[i]=='2') nb3++;
   }
   if(nb1>n/3){
        if(nb2>n/3){
            int i=n-1;
            while(nb1>n/3 || nb2>n/3){
                if(s[i]=='0' && nb1>n/3){s[i]='2';nb1--;}
                if(s[i]=='1' && nb2>n/3){s[i]='2';nb2--;}

                i--;
            }

        }
        else if(nb2<=n/3 && nb3<=n/3){
            int i=n-1;
            while(nb3<n/3){
                if(s[i]=='0' && nb1>n/3){s[i]='2';nb1--;nb3++;}
                i--;
            }
             while(nb2<n/3){
                if(s[i]=='0' && nb1>n/3){s[i]='1';nb1--;nb2++;}
                i--;
            }
        }
        else if(nb3>n/3){
            int i=0;
           while(nb3>n/3){
            if(s[i]=='2') {s[i]='1';nb3--;}
            i++;
           }
           i=n-1;
           while(nb1>n/3){
            if(s[i]=='0'){s[i]='1';nb1--;}
            i--;
           }
        }

   }
   if(nb2>n/3){
    if(nb3>n/3){
        int i=0;
        while(nb2>n/3 || nb3>n/3){
            if(s[i]=='1' && nb2>n/3){s[i]='0';nb2--;}
            if(s[i]=='2' && nb3>n/3){s[i]='0';nb3--;}
            i++;

        }
    }
    else if(nb3<=n/3){
        int i=0;
        while(nb1<n/3){
            if(s[i]=='1'){s[i]='0';nb1++;}
            i++;
        }
        i=n-1;
        while(nb3<n/3){
            if(s[i]=='1'){s[i]='2';nb3++;}
            i--;
        }
    }
   }
   if(nb3>n/3){
        int i=0;
        while(nb1<n/3){
            if(s[i]=='2'){s[i]='0';nb1++;}
            i++;
        }
        while(nb2<n/3){
            if(s[i]=='2'){s[i]='1';nb2++;}
            i++;
        }

   }
   cout<<s<<endl;
    return 0;
}
