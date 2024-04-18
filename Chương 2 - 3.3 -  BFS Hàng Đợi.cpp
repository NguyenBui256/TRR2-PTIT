#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<vector<int>> ke(1003);
int check[1003];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    check[u] = 1;
    while(!q.empty())
    {
        int v = q.front();
        cout << v << ' ';
        q.pop();
        for(int k : ke[v])
        {
            if(!check[k]) 
            {
                q.push(k);
                check[k] = 1;
            }
        }
    }
}

int main()
{
    cin >> n;
    int a[n+1][n+1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j]) 
            {
                ke[i].push_back(j);
                // ke[j].push_back(i);
            }
        }
    }
    bfs(1);
}