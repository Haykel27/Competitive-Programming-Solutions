#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define pii std::pair<int,int>
#define psi std::pair<string,int>

using namespace std;

int main()
{

   int n;scanf("%d",&n);
   map<string,psi> substrings;
   string s;
   string ch;
   psi p;
   for(int i=0;i<n;i++){
    cin>>s;
    for(int j=0;j<(int)s.size();j++){
        ch="";
        for(int k=j;k<(int)s.size();k++){
            ch+=s[k];
            if(substrings[ch].second && substrings[ch].first!=s) {substrings[ch].second++;substrings[ch].first=s;}
            else if(!substrings[ch].second) {p.first=s;p.second=1;substrings[ch]=p;}
        }
    }
   }
   /*for(map<string,psi>::iterator i=substrings.begin();i!=substrings.end();++i){
    cout<<i->first<<" "<<i->second.second<<" "<<i->second.first<<endl;
   }*/

   int q;scanf("%d",&q);
   for(int i=0;i<q;i++){
    cin>>s;
    if(substrings[s].second)
        cout<<substrings[s].second<<" "<<substrings[s].first<<endl;
    else cout<<0<<" -"<<endl;
   }



    return 0;
}
