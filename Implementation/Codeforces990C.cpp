#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;


int bien_parenthese(string s){
    vector<string> v,v1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
            v.push_back("(");
        else if(v.size()){
            v.pop_back();
        }
        else
            v1.push_back(")");
    }
    if(v.size()&& v1.size())
        return 3*100001;
    else if(v.size()){
        return v.size();
    }
    else if(v1.size()){
        return -v1.size();
    }
    else{
        return 0;
    }

}
int main()
{
    vector<long long int> avant;
    vector<long long int> arriere;
    for(int i=0;i<=(3*100000);i++){
        avant.push_back(0);
        arriere.push_back(0);
    }
    long long int bien=0;
    int n;scanf("%d",&n);
    vector<string> inp;
    for(int i=0;i<n;i++){
        string ch;cin>>ch;
        int r=bien_parenthese(ch);
        if(r<0){
            avant[-r]++;
        }
        else if(r<=3*100000 && r>0){
            arriere[r]++;
        }
        else if(r==0)
            bien++;


    }
    bien=bien*bien;
    long long int res=0;
    for(int i=0;i<=3*100000;i++){
        res+=avant[i]*arriere[i];
    }

    printf("%lld\n",bien+res);


    return 0;
}
