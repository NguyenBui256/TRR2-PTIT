#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

vector<vector<int>> ke(1003);
int a[1005][1005];
int vs[1005];
int par[1005];
int s, t;
vector<int> path;

void DFS(int u)
{
    vs[u] = 1;
    for(int x : ke[u])
    {
        if(!vs[x]) 
        {
            par[x] = u;
            DFS(x);
        }
    }
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int x : ke[v])
        {
            if(!vs[x])
            {
                vs[x] = 1;
                par[x] = v;
                q.push(x);
            }
        }
    }
}


int main()
{
    int n; cin >> n;
    cin >> s >> t;
    int endpoint = t;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) 
        {
            cin >> a[i][j];
            if(a[i][j])
            {
                ke[i].push_back(j);
            }
        }
    }
    vs[s] = 1;
    DFS(s);
    if(!par[t]) 
    {
        cout << "no path";
        return 0;
    }
    vector<int> path;
    while(t != s)
    {
        path.push_back(t);
        t = par[t];
    }
    path.push_back(s);
    cout << "DFS path: ";
    for(int zz : path) cout << zz << ' ';

    path.clear();
    memset(par,0,sizeof(par));
    memset(vs,0,sizeof(vs));
    vs[s] = 1;
    BFS(s);
    t = endpoint;
    while(t != s)
    {
        path.push_back(t);
        t = par[t];
    }
    path.push_back(s);
    cout << "\n";
    cout << "BFS path: ";
    for(int zz : path) cout << zz << ' ';
}