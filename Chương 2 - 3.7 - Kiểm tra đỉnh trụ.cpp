#include<iostream> 
#include<vector>
#include<cstring>
using namespace std;

int a[1005][1005];
int vs[1005];
int n;
int tplt, cnt;

void DFS(int i)
{
    vs[i] = 1;
    for(int j = 1; j <= n; j++)
    {
        if(a[i][j] && !vs[j]) DFS(j);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vs[i]) 
        {
            tplt++;
            DFS(i);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        memset(vs,0,sizeof(vs));
        vector<int> v;
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j])
            {
                v.push_back(j);
                a[i][j] = 0;
                a[j][i] = 0;
            }
        }
        cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(!vs[j] && j != i) 
            {
                cnt++;
                DFS(j);
            }
        }
        if(cnt > tplt) cout << i << ' ';
        for(int x : v)
        {
            a[i][x] = 1;
            a[x][i] = 1;
        }
    }
}