#include<iostream>
#include<vector>
#include<queue>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i > b; i--) 
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define TEST cin >> t; while(t--)
#define MOD 1000000007
#define ii pair<int,int> 
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vs vector<string>
#define all(a) a.begin(), a.end()

int n, m;
vector<ii> ke[1003];
int par[1005], d[1005];

void dijkstra()
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    FOR(i,1,n+1) d[i] = 1e9;
    q.push({0,m});
    d[m] = 0;
    par[m] = -1;
    while(!q.empty())
    {   
        int u = q.top().se;
        int du = q.top().fi;
        q.pop();
        if(du != d[u]) continue;
        for(auto x : ke[u])
        {
            int v = x.se;
            int uv = x.fi;
            if(d[v] > du + uv)
            {
                d[v] = du + uv;
                par[v] = u;
                q.push({d[v],v});
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
            if(x) ke[i].pb({x,j});
        }
    }
    dijkstra();
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
