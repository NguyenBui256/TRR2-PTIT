#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = a; i > b; i--) 
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define TEST cin >> t; while(t--)
#define ii pair<int,int> 
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vs vector<string>
#define all(a) a.begin(), a.end()
#define reset(a) memset(a,0,sizeof(a))

ll MOD = 1e9 + 7;
int n, m;
int D[505][505];
int par[505][505];

vector<int> trace_path(int u, int v) {
    if(u == v) return {u}; 
    vector<int> path;
    while (v != u) { // truy vết ngược từ v về u
        path.push_back(v);
        v = par[u][v];
    }
    path.push_back(u);
    
    reverse(path.begin(), path.end()); // cần reverse vì đường đi từ v ngược về u
    
    return path;
}

void solve() {
    cin >> n;
    FOR(i,0,n){
        FOR(j,0,n) {
            cin >> D[i][j];
            if(i != j && !D[i][j]) D[i][j] = 1e9;
        }
    }
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            par[u][v] = u;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (u != v && u != k && k != v && D[u][v] > D[u][k] + D[k][v]) {
                    D[u][v] = D[u][k] + D[k][v];
                    par[u][v] = par[k][v];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(D[i][j] != 1e9){
                cout << "K/c " << i + 1 << " -> " << j + 1 << " = " << D[i][j] << "; "; 
                vector<int> ans = trace_path(i,j);
                for(int z = 0; z < ans.size(); z++){
                    cout << ans[z] + 1; 
                    if(z != ans.size() - 1) cout << " --> ";
                }
                cout << "\n";
            }else{
                cout << "K/c " << i + 1 << " -> " << j + 1 << " = " << 0 << "; " << i + 1;
                cout << "\n";
            }
        }
        cout << "\n";
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