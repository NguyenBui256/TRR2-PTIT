#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ke(1002);
int check[1002];

void dfs(int u)
{
    cout << u << ' ';
    check[u] = 1;
    for(int v : ke[u])
    {
        if(!check[v]) dfs(v);
    }
}

int main()
{
    int n; cin >> n;
    int a[n+1][n+1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) 
        {
            cin >> a[i][j];
            if(a[i][j]) ke[i].push_back(j);
        }
    }
    dfs(1);
}