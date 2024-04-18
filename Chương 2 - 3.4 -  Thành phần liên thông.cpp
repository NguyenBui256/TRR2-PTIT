#include<iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> ke(1003);
int check[1003];

void dfs(int u)
{
    check[u] = 1;
    for(int v : ke[u])
    {
        if(!check[v]) dfs(v);
    }
}

int main()
{
    cin >> n;
    int a[n+1][n+1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if(a[i][j])
            {
                ke[i].push_back(j);
                ke[j].push_back(i);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!check[i]) ans++, dfs(i);
    }
    cout << ans;
} 