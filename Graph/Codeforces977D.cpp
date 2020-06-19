#include <iostream>
#include<vector>
#include<inttypes.h>
#define for(i,a,b) for(uint64_t i=a;i<b;i++)
using namespace std;
int exist(vector<uint64_t> tab,uint64_t l ){
    for(i,0,tab.size()){if (tab[i]==l) return 1 ;} return 0;
}
uint64_t index(vector<uint64_t> tab,uint64_t l){ for(i,0,tab.size()){if (tab[i]==l) return i ;} return 10000000000000000;}
/*void chemin(vector<uint64_t> t1,uint64_t a, vector<uint64_t> t2){
    if (exist(t1,t1[a]/3)){
        t2.push_back(t1[a]);
        chemin(t1,index(t1[a]/3),)
    }

}*/
int main()
{
    uint64_t n;
    cin >> n;
    vector<uint64_t> ta;
    vector<uint64_t> v;
    for(i,0,n)
    {   uint64_t b;
        cin >> b;
        ta.push_back(b);
    }
    for(i,0,n)
    {   uint64_t k=0;
        vector<uint64_t> ta2=ta;
        v.push_back(ta2[i]);
        ta2.erase(ta2.begin()+i);
       while (k<n-1){
        if ((v[k]%3==0) && (exist(ta2,v[k]/3))){
            v.push_back(v[k]/3);

            ta2.erase(ta2.begin()+index(ta2,v[k]/3));
            k++;
        }
        else if(exist(ta2,v[k]*2)){
            v.push_back(v[k]*2);

            ta2.erase(ta2.begin()+index(ta2,v[k]*2));
            k++;
        }
        else{
            v.clear();
            break;
        }
       }
       if (k==n-1){
        break;
       }


    }
    for(i,0,n){
        cout << v[i] << " " ;
    }
    return 0;
}
