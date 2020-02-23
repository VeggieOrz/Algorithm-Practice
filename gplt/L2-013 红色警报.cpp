#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;
const int maxn = 510;
int n, m, k, x, cnt;
/**
  * p[] 是并查集数组，存储元素i的父亲节点
  * mark[] 用于标记i城市是否被攻占
  */
int p[maxn], mark[maxn];
pair<int, int> edge[maxn * 10];

void init(int n) {
    for (int i = 0; i < n; i++) p[i] = i;
}

int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}

void Merge(int x, int y) {
    int tx = Find(x);
    int ty = Find(y);
    if (tx != ty) p[tx] = ty;
}

int main()
{
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> edge[i].first >> edge[i].second;
        Merge(edge[i].first, edge[i].second);
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == i) cnt++;
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x;
        mark[x] = 1; //攻占标记
        init(n);
        for (int j = 0; j < m; j++) {
            //如果两座城市都没有被攻占才将它们合并到同一个连通块中
            if (!mark[edge[j].first] && !mark[edge[j].second]) {
                Merge(edge[j].first, edge[j].second);
            }
        }
        int ans = 0;
        for (int j = 0; j < n; j++) {
            //计算连通块个数，注意被攻占的城市不能计算在内
            if (!mark[j] && p[j] == j) ans++;
        }
        /**
          * 如果被攻占的城市不影响城市之间的连通性，
          * 那么该城市被攻占后，连通块个数不变或者减少一个（攻占了孤岛）
          */
        if (ans == cnt || ans + 1 == cnt) {
            cout << "City "<< x << " is lost." << endl;
        } else {
            cout << "Red Alert: City " << x << " is lost!" << endl;
        }
        cnt = ans;
    }
    if (k == n) {
        cout << "Game Over." << endl;
    }
    return 0;
}
