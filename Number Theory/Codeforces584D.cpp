#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int premier(long int k){
    for(int i=2;i<=sqrt(k);i++){
        if(k%i==0) return 0;
    }
    return 1;
}
int main()
{
    long int n;scanf("%ld",&n);if(premier(n)) {cout<<1<<endl; cout<<n<<endl;}
    else{long int s1=n-3,s2=2;
    while(!premier(s1) || !premier(s2)){
        s1--;s2++;
    }
    s2=s2-1;int s3=2;
    while(!premier(s3) || !premier(s2)){
        s2--;s3++;
    }
    if(s1==0||s2==0|| s3==0){
        cout<<2<<endl;
        if(s1==0) cout<<s2<<" "<<s3<<endl;
        else if(s2==0) cout<<s1<<" "<<s3<<endl;
        else cout<<s1<<" "<<s2<<endl;
    }
    else{
        cout<<3<<endl;
        cout<<s1<<" "<<s2<<" "<<s3<<endl;
    }
    }

    return 0;
}
