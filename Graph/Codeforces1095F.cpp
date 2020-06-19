#include <iostream>
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pii std::pair<int,ll>
#define pli std::pair<ll,int>
#define psi std::pair<string,int>
#define pli std::pair<ll,int>
#define pll std::pair<ll,ll>
#define pci std::pair<char,int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define pb push_back
#define vll std::vector<ll>
#define vpi std::vector<std::pair<int,ll>>
#define vi std::vector<int>
#define vvi std::vector<std::vector<int>>
#define vli std::vector<li>
#define vlpli vector<list<pli>>
#define lpli list<pli>
#define li std::list<int>
#define Endl printf("\n")
#define ma 1000000
#define mod 998244353
#define Nmax 10000000000000000
using namespace std;
// Creating shortcut for an integer pair
typedef  pair<ll, ll> iPair;

// Structure to represent a graph
struct Graph
{
    int V, E;
    vector< pair<ll, iPair> > edges;

    // Constructor
    Graph(ll V, ll E)
    {
        this->V = V;
        this->E = E;
    }

    // Utility function to add an edge
    void addEdge(ll u,ll v, ll w)
    {
        edges.push_back({w, {u, v}});
    }

    // Function to find MST using Kruskal's
    // MST algorithm
    ll kruskalMST();
};

// To represent Disjoint Sets
struct DisjointSets
{
    ll *parent, *rnk;
    ll n;

    // Constructor.
    DisjointSets(ll n)
    {
        // Allocate memory
        this->n = n;
        parent = new ll[n+1];
        rnk = new ll[n+1];

        // Initially, all vertices are in
        // different sets and have rank 0.
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;

            //every element is parent of itself
            parent[i] = i;
        }
    }

    // Find the parent of a node 'u'
    // Path Compression
    ll find(ll u)
    {
        /* Make the parent of the nodes in the path
           from u--> parent[u] point to parent[u] */
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(ll x, ll y)
    {
        x = find(x), y = find(y);

        /* Make tree with smaller height
           a subtree of the other tree  */
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else // If rnk[x] <= rnk[y]
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

 /* Functions returns weight of the MST*/

ll Graph::kruskalMST()
{
    ll mst_wt = 0; // Initialize result

    // Sort edges in increasing order on basis of cost
    sort(edges.begin(), edges.end());

    // Create disjoint sets
    DisjointSets ds(V);

    // Iterate through all sorted edges
    vector< pair<ll, iPair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        ll u = it->second.first;
        ll v = it->second.second;

        ll set_u = ds.find(u);
        ll set_v = ds.find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            //cout << u << " - " << v << endl;

            // Update MST weight
            mst_wt += it->first;

            // Merge two sets
            ds.merge(set_u, set_v);
        }
    }

    return mst_wt;
}

int main()
{
    int n,m;cin>>n>>m;
    pll a[n];
    ll x;
    for(int i=0;i<n;i++) {sll(x);a[i]=make_pair(x,i);}
    sort(a,a+n);
    map<pair<ll,ll>,ll> Map;
    for(int i=1;i<n;i++){
        Map[make_pair(a[0].second,a[i].second)]=a[0].first+a[i].first;
    }
    int u,v;ll w;
    for(int i=n-1;i<n+m-1;i++){
        si(u);si(v);sll(w);
        u--;v--;
        if(Map[make_pair(u,v)]){
            Map[make_pair(u,v)]=min(w,Map[make_pair(u,v)]);
        }
        else if(Map[make_pair(v,u)]){
            Map[make_pair(v,u)]=min(Map[make_pair(v,u)],w);
        }
        else{
            Map[make_pair(u,v)]=w;
        }

    }
    int k=0;

    map<pair<ll,ll>,ll> mymap;
    for(map<pair<ll,ll>,ll>::iterator i=Map.begin();i!=Map.end();++i){
        if(i->second>0){
            mymap[i->first]=i->second;
        }
    }
    Graph graph((ll) n,(ll) mymap.size());
    for(map<pair<ll,ll>,ll>::iterator i=mymap.begin();i!=mymap.end();++i){
        graph.addEdge((i->first).first,(i->first).second,i->second);
    }
    cout<<graph.kruskalMST()<<endl;


    return 0;
}
