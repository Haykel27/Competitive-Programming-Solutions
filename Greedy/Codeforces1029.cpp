#include <iostream>
#include<bits/stdc++.h>

using namespace std;
bool f(pair<int,int> p1,pair<int,int> p2){
    return(p1.second-p1.first<=p2.second-p2.first);
}

int main()
{

    int n;scanf("%d",&n);
    vector<pair<long int,long int>> v;
    pair<long int,long int> maxX;maxX.first=0;maxX.second=1000000000;
    pair<long int,long int> minY;minY.first=0;minY.second=1000000000;
    for(int i=0;i<n;i++){
        long int x,y;scanf("%ld %ld",&x,&y);pair<long int,long int> p;p.first=x;p.second=y;v.push_back(p);
        if(x>maxX.first|| x==maxX.first && y<maxX.second){
            maxX.first=x;maxX.second=y;
        }
        if(y<minY.second|| y==minY.second && x>minY.first){
            minY.first=x;minY.second=y;
        }

    }
    long int d1,d2;
    int b=1;long int x=0,y=1000000000;
    for(int i=0;i<n;i++){
        if(b && v[i]==maxX)
            b=0;
        else{
            if(v[i].first>x)
                x=v[i].first;
            if(v[i].second<y)
                y=v[i].second;
        }
    }
    d1=y-x;
    b=1;x=0;y=1000000000;
    for(int i=0;i<n;i++){
        if(b && v[i]==minY)
            b=0;
        else{
            if(v[i].first>x)
                x=v[i].first;
            if(v[i].second<y)
                y=v[i].second;
        }
    }
    d2=y-x;
    long int d=max(d1,d2);long int o=0;
    cout<<max(d,o)<<endl;


    return 0;
}
