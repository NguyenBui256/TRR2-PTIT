#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int n;
vector<vector<int>> ke(1003);
int check[1003];

void dfs(int u)
{
    stack<int> st;
    st.push(u);
    // cout << u << ' ';
    check[u] = 1;
    while(!st.empty())
    {
        int v = st.top(); st.pop();
        cout << v << ' ';
        for(int kk : ke[v]) 
        {
            if(!check[kk])
            {
                check[kk] = 1;
                st.push(kk);
                break;
            }
        }
    }
}

int main() 
{
    cin >> n;
    int a[n+1][n+1] = {};
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
    dfs(1);
}