#include <iostream>
#include<bits/stdc++.h>
#define ll long long
#define pii std::pair<int,int>
#define psi std::pair<string,int>
#define pli std::pair<ll,int>
#define pll std::pair<ll,ll>


using namespace std;

int main()
{
    bool visited[2002];memset(visited,false,sizeof visited);
    int n,m;scanf("%d %d",&n,&m);
    vector<int> power(2*n);
    int x;
    for(int i=0;i<2*n;i++){
        scanf("%d",&x);power[i]=x;
    }
    int a,b;
    vector<pii> special(2*m);
    pii p;
    int liaison[2002];memset(liaison,-1,sizeof liaison);
    for(int i=0;i<2*m;i+=2){
        scanf("%d %d",&a,&b);a--;b--;
        special[i].first=power[a];special[i].second=a;
        special[i+1].first=power[b];
        special[i+1].second=b;
        liaison[a]=b;liaison[b]=a;

    }
    vector<pii> not_special;
    for(int i=0;i<2*n;i++){
        if(liaison[i]==-1){
            p.first=power[i];p.second=i;
            not_special.push_back(p);
        }
    }
    sort(special.begin(),special.end());
    sort(not_special.begin(),not_special.end());
    //for(int i=0;i<(int)not_special.size();i++) cout<<"["<<not_special[i].first<<","<<not_special[i].second<<"] ";cout<<endl;
    //for(int i=0;i<(int)special.size();i++) cout<<"["<<special[i].first<<","<<special[i].second<<"] ";cout<<endl;
    int cpt_special=0;
    int cpt=0;
    int t;scanf("%d",&t);
    while(cpt<2*n){
        if(t==1){
            if(cpt_special<2*m){
                int i=2*m-1;
                while(visited[special[i].second]) i--;
                cout<<special[i].second+1<<endl;
                scanf("%d",&x);x--;
                visited[special[i].second]=true;
                visited[x]=true;
                cpt_special+=2;
            }
            else{
                int i=(int) not_special.size()-1;
                while(visited[not_special[i].second]) i--;
                cout<<not_special[i].second+1<<endl;;
                scanf("%d",&x);x--;
                visited[not_special[i].second]=true;
                visited[x]=true;
            }


        }
        else{
            scanf("%d",&x);x--;
            visited[x]=true;
            if(liaison[x]!=-1 && !visited[liaison[x]]) {cout<<liaison[x]+1<<endl;cpt_special+=2;visited[x]=true;visited[liaison[x]]=true;}
            else{
                if(cpt_special<2*m){
                    int i=2*m-1;
                    while(visited[special[i].second]) i--;
                    cout<<special[i].second+1<<endl;
                    visited[special[i].second]=true;
                    cpt_special+=2;
                }
                else{
                    int i=(int)not_special.size()-1;
                    while(visited[not_special[i].second]) i--;
                    cout<<not_special[i].second+1<<endl;
                    visited[not_special[i].second]=true;

                }
            }
        }

        cpt+=2;
    }
    return 0;
}
