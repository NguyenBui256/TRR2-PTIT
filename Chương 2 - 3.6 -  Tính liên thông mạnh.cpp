#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


int n;
int check[1005];
int kq = 0;
int a[1005][1005];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    check[u] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = n; i >= 1; i--) {
            if (a[v][i] == 1 && check[i] == 0) {
                check[i] = 1;
                q.push(i);
                break;

            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    bfs(1);
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            cout << "not strongly connected";
            return 0;
        }
    }
    cout << "strongly connected";
}