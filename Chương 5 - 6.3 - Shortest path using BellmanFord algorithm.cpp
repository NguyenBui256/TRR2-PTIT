#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i > b; i--) 
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define TEST cin >> t; while(t--)

struct edge{
    int x,y,w;
    edge(int x, int y, int w){
        this->x = x;
        this->y = y;
        this->w = w;
    }
};

int n, m;
vector<edge> E;
int par[1005], d[1005];

void bellmanFord()
{
    FOR(i,1,1005) d[i] = 1e9;
    d[m] = 0;
    par[m] = -1;
    FOR(i,1,n){
        for(edge e : E){
            int u = e.x, v = e.y, w = e.w;
            if(d[u] < 1e9){
                if(d[u] + w < d[v]){
                    d[v] = d[u] + w;
                    par[v] = u;
                }  
                // d[v] = min(d[v], d[u] + w);
                // par[v] = u;
            }
        }
    }
}

void solve()
{
    cin >> n >> m; 
    int x;
    FOR(i,1,n+1)
    {
        FOR(j,1,n+1){
            cin >> x;
            if(x != 0) E.push_back({i,j,x});
        }
    }
    // for(edge e : E) cout << e.x << ' ' << e.y << ' ' << e.w << "\n"; 
    bellmanFord();
    for(int i = 1; i <= n; i++)
    {
        if(d[i] != 1e9)
        {
            cout << "K/c " << m << " -> " << i << " = " << d[i] << ";        ";
            int cur = i;
            while(cur != -1){
                cout << cur;
                if(par[cur] != -1) cout << " <- "; 
                cur = par[cur];
            }
            if(i == m) cout << " <- " << m << "\n";
            else cout << "\n";
        }
        else
        {
            cout << "K/c " << m << " -> " << i << " = INF\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    // TEST
    {
        solve();
    }
}