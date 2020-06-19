#include <iostream>
//#include <algorithm>
#include<vector>
//#include<string>
//#include<inttypes.h>
#define for(i,a,b) for(int i=int(a);i<int(b);i++)
//#define n

using namespace std;
/*int sum(vector<int> a){
    int s=0;
    for(i,0,a.size()){s+=a[i];return s;}
}*/

int main()
{
   /*string ch;
   cin >> ch;*/
   int n,k;
   scanf("%d %d",&n,&k);
   vector<vector<int>> v;
   vector<int> res;
   for(i,0,n){
    int x,b=1,exist=0,pos=-1;
    scanf("%d",&x);
    for(j,0,v.size()){
            if (x>=v[j][0] && x<=v[j][1]){
                res.push_back(v[j][0]);
                exist=1;
                b=0;
                break;
            }
            else if((x-k+1>=v[j][0] && x-k+1<=v[j][1]) && x-v[j][0]+1>k){
                pos=j;
                b=0;

            }

    }
    if(!exist && pos>=0){
       vector<int> v1;
        v1.push_back(v[pos][1]+1);
        v1.push_back(x);
        v.push_back(v1);
        res.push_back(v1[0]);
    }
    if(b){
        vector<int> v1;
        v1.push_back(max(0,x-k+1));
        v1.push_back(x);
        v.push_back(v1);
        res.push_back(v1[0]);
    }
   }
   for(i,0,n){
    cout << res[i] << " ";
   }
   cout <<endl;
   /*uint64_t k;
   scanf("%I64d",&k);
   vector<int> t;
   for(i,0,n){int b;b=scanf("%d",&b);t.push_back(b);}
   vector<string> t1;
   for(i,0,n){string ch1;cin >> ch1; t1.push_back(ch1);}*/




    return 0;
}
