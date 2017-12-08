#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

class graph {
    ll v;
    list< pair<ll, ll> > *adj;
    public:
        graph(ll v);
       void addEdge(ll a, ll b, ll c);
       void dijkstra(ll s);
};

graph::graph(ll v){
    this->v = v;
    adj = new list< pair<ll, ll> >[v];
}

void graph::addEdge(ll v,ll a,ll b){
    adj[v].push_back(make_pair(a,b));
    adj[a].push_back(make_pair(v,b));
}

void graph::dijkstra(ll s){
    set<pair<ll,ll>>setvertices;
    vector<ll>distance(v,INT_MAX);
    setvertices.insert(make_pair(s,0));
    distance[s]=0;
    
    while(!setvertices.empty()){
        pair<ll,ll> tmp = *(setvertices.begin());
        setvertices.erase(setvertices.begin());
        
        ll u = tmp.first;
        list< pair<ll, ll> >::iterator i;
        for(i=adj[u].begin();i!=adj[u].end();i++){
            cout<<(*i).first;
           /* ll ver = *(i)->first;
            ll w = *(i)->second;
            
            if(distance[ver]>distance[u]+w){
                if(distance[ver]!=INT_MAX)
                    setvertices.erase(make_pair(ver,distance[ver]));
                distance[ver] = distance[u]+w;
                setvertices.insert(make_pair(ver,distance[ver]));
            }*/
        }
        
    }
    for(ll i=0;i<v&&i!=s;i++)
        cout<<distance[i];
}


int main()
{
    ll t;    
    cin>>t;
    while(t--) {
        ll n;
        ll m;
        cin>>n>>m;
        graph g(n);
        for(ll a1 = 0; a1 < m; a1++){
            ll x;
            ll y;
            ll r;
            cin>>x>>y>>r;
            g.addEdge(x,y,r);
            
        }
        ll s;
        cin>>s;
       // cout<<s;
        g.dijkstra(s);
    }
    return 0;
}

