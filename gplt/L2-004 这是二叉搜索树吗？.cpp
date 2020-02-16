#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 10;
int n, flag;
/**
  * a[]用于存储输入的前序遍历序列
  * ans用于存储后序遍历的结果
  */
int a[maxn];
vector<int> ans;

/**
  * 后序遍历这颗二叉树
  *
  */
void dfs(int l, int r) {
    if (l > r) return ;
    //tl表示右子树的左边界，tr表示左子树的右边界
    int tl = l + 1, tr = r;
    if (flag) {
        //判断二叉搜索树的“镜像”
        while (tl <= r && a[tl] >= a[l]) tl++;
        while (tr > l && a[tr] < a[l]) tr--;
    } else {
        //判断二叉搜索树
        while (tl <= r && a[tl] < a[l]) tl++;
        while (tr > l && a[tr] >= a[l]) tr--;
    }
    //不满足二叉搜索树的条件
    if (tl - tr != 1) return ;
    dfs(l + 1, tr);
    dfs(tl, r);
    ans.push_back(a[l]);
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    //先检查是不是二叉搜索树的“镜像”
    dfs(1, n);
    //如果不满足，则再检查是不是二叉搜索树
    if (ans.size() != n) {
        flag = 1;
        ans.clear();
        dfs(1, n);
    }
    if (ans.size() != n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n -1 ? '\n' : ' ');
        }
    }
    return 0;
}
