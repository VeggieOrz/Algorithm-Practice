#include <bits/stdc++.h>

using namespace std;
const int maxn = 50;
int n;
/**
  * pre_order[]表示前序遍历序列
  * in_order[]表示中序遍历序列
  * tree[]用于存储树结构，
  */
int pre_order[maxn], in_order[maxn];
pair<int, int> tree[maxn];

/**
  * 建树函数
  * la, ra表示前序遍历序列的左右边界
  * lb, rb表示中序遍历序列的左右边界
  */
int build(int la, int ra, int lb, int rb) {
    if (la > ra || lb > rb) return 0;
    //根节点
    int rt = pre_order[la];
    //p表示根节点在中序遍历序列中的下标
    int p = 1;
    while (in_order[p] != rt) p++;
    //cnt表示左子树的节点数
    int cnt = p - lb;
    //递归求左子树
    tree[rt].first = build(la + 1, la + cnt, lb, p - 1);
    //递归求右子树
    tree[rt].second = build(la + cnt + 1,ra, p + 1, rb);
    return rt;
}

/**
  * 广度优先搜索
  * 只要先访问右子树再访问左子树就可以实现镜像二叉树的层序遍历
  */
void bfs(int rt) {
    vector<int> ans;
    queue<int> q;
    q.push(rt);
    while (!q.empty()) {
        int x = q.front();
        ans.push_back(x);
        q.pop();
        if (tree[x].second) q.push(tree[x].second);
        if (tree[x].first)  q.push(tree[x].first);
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> in_order[i];
    for (int i = 1; i <= n; i++) cin >> pre_order[i];
    int rt = build(1, n, 1, n);
    bfs(rt);
    return 0;
}
