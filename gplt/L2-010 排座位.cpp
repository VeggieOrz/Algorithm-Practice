#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int maxn = 105;
int n, m, k;

/**
  * 并查集p[]用于存储共同好友集
  * map用于存储两个人的关系
  */
int p[maxn];
map<pii, int> vis;

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

int Merge(int x, int y) {
    int tx = Find(x);
    int ty = Find(y);
    if (tx != ty) p[tx] = ty;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //注意：这里需要添加(a, b)和(b, a)的关系
        vis[make_pair(a, b)] = c;
        vis[make_pair(b, a)] = c;
        if (c == 1) Merge(a, b);
    }
    while (k--) {
        int a, b;
        cin >> a >> b;
        int res = vis[make_pair(a, b)];
        if (res == 1) {
            //两个人是好友
            cout << "No problem" << endl;
        } else if (res == -1) {
            //两个人是敌人
            int tx = Find(a);
            int ty = Find(b);
            //他们有共同好友
            if (tx == ty) cout << "OK but..." << endl;
            //他们没有共同好友
            else cout << "No way" << endl;
        } else {
            //两个人没有关系
            cout << "OK" << endl;
        }
    }
    return 0;
}
