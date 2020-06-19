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
{   ll n;cin>>n;
    string s=to_string(n);
    int m1=50,m2=50,m3=50,m4=50;
    string s1=s,s2=s,s3=s,s4=s;
    for(int i=(int)s.size()-1;i>=0;i--){
        if(s1[i]=='0'){
            char y=s[i];
            for(int j=i;j<(int)s.size()-1;j++) s1[j]=s1[j+1];
            s1[s.size()-1]=y;

            for(int j=(int)s.size()-2;j>=0;j--){
                if(s1[j]=='0') {m1=min(m1,(int)s.size()-1-i+(int)s.size()-2-j);break;}

            }
            int j=0;
            while(s1[j]=='0') {m1++;j++;}
            break;
        }
    }
    for(int i=(int)s.size()-1;i>=0;i--){
        if(s2[i]=='0'){
            char y=s2[i];
            for(int j=i;j<(int)s.size()-1;j++) s2[j]=s2[j+1];
            s2[s2.size()-1]=y;

            for(int j=(int)s.size()-2;j>=0;j--){
                if(s2[j]=='5') {m2=min(m1,(int)s.size()-1-i+(int)s.size()-2-j);break;}

            }
            int j=0;
            while(s2[j]=='0') {m2++;j++;}
            break;
        }
    }
    for(int i=(int)s.size()-1;i>=0;i--){
        if(s3[i]=='5'){
           char y=s3[i];
            for(int j=i;j<(int)s.size()-1;j++) s3[j]=s3[j+1];
            s3[s.size()-1]=y;
            for(int j=(int)s.size()-2;j>=0;j--){
                if(s3[j]=='2') {m3=min(m1,(int)s.size()-1-i+(int)s.size()-2-j);break;}

            }
            int j=0;
            while(s3[j]=='0') {m3++;j++;}
            break;
        }
    }
    for(int i=(int)s.size()-1;i>=0;i--){
        if(s4[i]=='5'){
            char y=s[i];
            for(int j=i;j<(int)s.size()-1;j++) s4[j]=s4[j+1];
            s4[s.size()-1]=y;

            for(int j=(int)s.size()-2;j>=0;j--){
                if(s4[j]=='7') {m4=min(m1,(int)s.size()-1-i+(int)s.size()-2-j);break;}

            }
            int j=0;
            while(s4[j]=='0') {m4++;j++;}
            break;
        }
    }

    int k=min(min(m1,m2),min(m3,m4));
    if(k==50) cout<<-1<<endl;
    else cout<<k<<endl;
    return 0;
}
