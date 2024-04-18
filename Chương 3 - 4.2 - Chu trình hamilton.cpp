#include<iostream>
#include<vector>
using namespace std;

int n;
int a[1003][1003];
int X[1003];
vector<int> check(1003);

void in()
{
    for(int i = 1; i <= n; i++) cout << X[i] << ' ';
    cout << X[1];
    cout << "\n";
}

void dq(int k)
{
    for(int j = 1; j <= n; j++)
    {
        if(a[X[k-1]][j] && !check[j])
        {
            X[k] = j;
            check[j] = 1;
            if(k <= n) 
            {
                dq(k+1);
            }
            else 
                if(X[1] == X[k]) in();
            check[j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> n >> t;
    int x;
    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    X[1] = t;
    dq(2);
}