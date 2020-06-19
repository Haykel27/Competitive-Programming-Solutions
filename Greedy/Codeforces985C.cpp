#include <iostream>
#include<vector>
#include<algorithm>
#include<inttypes.h>

using namespace std;

int main()
{
    vector<uint64_t> inp;

    uint64_t n,k,l;
    scanf("%I64d %I64d %I64d",&n,&k,&l);
    for(uint64_t i=0;i<n*k;i++){uint64_t x;scanf("%I64d",&x);inp.push_back(x);}
    std::sort(inp.begin(),inp.end());
    if(n==1){
        cout<<inp[0]<<endl;
    }
    else if(inp[n-1]-inp[0]>l){
        cout<<"0"<<endl;
    }

    else{
        uint64_t s=0;
        if(k==1){
            for(uint64_t i=0;i<n;i++){
                s+=inp[i];
            }
        }
        else{
            uint64_t j=n*k-k;
            while(inp[j]-inp[0]>l)
                j--;
            uint64_t r=(n*k-1-j)/(k-1);
            for(uint64_t i=0;i<r;i++){
                s+=inp[j-i];
            }
            for(uint64_t i=0;i<(n-r)*k;i=i+k){
                s+=inp[i];
            }
        }
        cout<<s<<endl;
    }

    return 0;
}
