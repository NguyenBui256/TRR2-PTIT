#include<iostream>
#include<cstring>
using namespace std;

int a[100][100];
int tplt, cnt;
int n;
int vs[100];

void DFS(int u)
{
    vs[u] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(a[u][i] && !vs[i]) DFS(i);
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vs[i]) 
        {
            tplt++;
            DFS(i);
        }
    }
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(a[i][j]) 
            {
                a[i][j] = 0;
                a[j][i] = 0;
                memset(vs,0,sizeof(vs));
                cnt = 0;
                for(int k = 1; k <= n; k++)
                {
                    if(!vs[k]) 
                    {
                        cnt++;
                        DFS(k);
                    }
                }
                if(cnt > tplt) cout << i << ' ' << j << "\n";
                a[i][j] = 1;
                a[j][i] = 1;
            }
        }
    }
}