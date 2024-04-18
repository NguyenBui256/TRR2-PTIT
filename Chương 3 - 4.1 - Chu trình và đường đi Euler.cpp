#include<iostream> 
#include<vector>
#include<set>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;

set<int> ke[1003];
int a[1003][1003];
int check[1003];


void dfs(int u)
{
    vector<int> CE;
    stack<int> st;
    st.push(u);
    check[u] = 1;
    while(!st.empty())
    {
        int v = st.top();
        if(ke[v].size()) 
        {
            int t = *ke[v].begin();
            st.push(t);
            ke[t].erase(v);
            ke[v].erase(t);
        }
        else {
            st.pop();
            CE.push_back(v);
        }
    }
    reverse(CE.begin(), CE.end());
    for(int x : CE) cout << x << ' ';
}

int main()
{
    int n, t; cin >> n >> t;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) 
        {
            cin >> a[i][j];
            if(a[i][j]) 
            {
                ke[i].insert(j);
                ke[j].insert(i);
            }
        }
    }
    dfs(t);
}