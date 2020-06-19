#include <iostream>
#include<bits/stdc++.h>

using namespace std;
bool f(pair<int,int> p1,pair<int,int> p2){
    return(p1.second-p1.first<=p2.second-p2.first);
}

int main()
{
    int t;scanf("%d",&t);
    vector<vector<int>> res;
    for(int i=0;i<t;i++){
        long int n;scanf("%ld",&n);vector<int> v1;vector<int> res1;
        vector<int> v;
        for(long int j=0;j<n;j++){
            int a;scanf("%d",&a);v.push_back(a);
        }
        sort(v.begin(),v.end());
        long int j=0;
        while(j<n){
           if(j<n-1 && v[j]==v[j+1]){
                v1.push_back(v[j]);
                j+=2;
            }
            else j++;
        }
        double m=1000000000;int M=0;
        for(int j=1;j<v1.size();j++){
                double p=2*(v1[j]+v1[j-1]),s=v1[j]*v1[j-1];

                if((p*p)/s==16){
                    res1={v1[j-1],v1[j]};
                    break;
                }
                else if((p*p)/s<=m){

                    M=v1[j];res1={v1[j-1],v1[j]};m=(p*p)/s;
                }



        }
        res.push_back(res1);

    }
    for(int i=0;i<t;i++){
        printf("%d %d %d %d\n",res[i][0],res[i][0],res[i][1],res[i][1]);
    }
    return 0;
}
