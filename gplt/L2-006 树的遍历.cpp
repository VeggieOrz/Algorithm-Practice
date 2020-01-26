#include <bits/stdc++.h>

using namespace std;
const int maxn = 50;
int n;
/**
  * in_order[]表示中序遍历序列
  * post_order[]表示后序遍历序列
  * tree[]用于存储树形结构
  * 其中，tree[i].first表示i节点左孩子编号，tree[i].second表示i号节点右孩子编号
  */
int in_order[maxn], post_order[maxn];
pair<int, int> tree[maxn];
/**
  * [la, ra]表示中序遍历序列的范围
  * [lb, rb]表示后序遍历序列的范围
  */
int build(int la, int ra, int lb, int rb) {
    if (la > ra) return 0;
    int rt = post_order[rb];
    //p表示根节点在中序遍历序列中的位置
    int p = la;
    while (in_order[p] != rt) p++;
    //cnt表示左子树的节点数
    int cnt = p - la;
    //根据已知量，求左右子树所在的遍历序列区间
    tree[rt].first = build(la, p - 1 , lb, lb + cnt - 1);
    tree[rt].second = build(p + 1, ra, lb + cnt, rb - 1);
    return rt;
}

/**
  * 利用bfs层序遍历二叉树
  * @param root表示二叉树的根节点
  */
void bfs(int root) {
    vector<int> ans;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        if (tree[node].first) q.push(tree[node].first);
        if (tree[node].second) q.push(tree[node].second);
    }
    int len = ans.size();
    for (int i = 0; i < len; i++)
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> post_order[i];
    for (int i = 1; i <= n; i++)
        cin >> in_order[i];
    int root = build(1, n, 1, n);
    bfs(root);
    return 0;
}
