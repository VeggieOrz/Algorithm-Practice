#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
const int maxn = 1e4 + 10;
int n, id, fid, mid, k, cid, cnt;

/**
  * People结构体每个人的必要信息
  * num表示套房总数，area表示总面积，flag表示是否拥有房产
  */
struct People {
    double num, area;
    bool flag = false;
} s[maxn];

/**
  * Answer结构体用于存储最终的答案
  * num家庭表示家庭人口数，house表示套房总数，area表示总面积
  */
struct Answer {
    int id, num;
    double house, area;
} ans[1005];

//mark[i]记录家庭i在未排序的Answer数组的存储下标
int p[maxn], mark[maxn];
//vis集合用于记录所有的出现过的人口，自带去重功能
unordered_set<int> vis;

bool cmp(const Answer &A, const Answer &B) {
    if (A.area == B.area) return A.id < B.id;
    else return A.area > B.area;
}

/**
  * 并查集数组的初始化，每个集合表示一个家庭
  */
void init() {
    for (int i = 1; i < maxn; i++) p[i] = i;
}

/**
  * 集合的查询
  */
int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
}
 /**
   * 集合的合并，保证编号最小的元素最作为父节点
   */
void Merge(int x, int y) {
    int tx = Find(x);
    int ty = Find(y);
    if (tx != ty) {
        if (tx < ty) p[ty] = tx;
        else p[tx] = ty;
    }
}

int main()
{
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &id, &fid, &mid);
        vis.insert(id);
        //将父亲添加到家庭中
        if (fid != -1) {
            Merge(id, fid);
            vis.insert(fid);
        }
        //将母亲添加到家庭中
        if (mid != -1) {
            Merge(id, mid);
            vis.insert(mid);
        }
        scanf("%d", &k);
        //将孩子们添加到家庭中
        for (int j = 1; j <= k; j++) {
            scanf("%d", &cid);
            if (cid != -1) {
                Merge(id, cid);
                vis.insert(cid);
            }
        }
        scanf("%lf %lf", &s[id].num, &s[id].area);
        s[id].flag = true;
    }
    //遍历有所人口，进行数据统计
    for (auto i : vis) {
        int t = Find(i);
        //如果这个家庭没有出现过
        if (!mark[t]) {
            //增加家庭数，并存储该家庭在ans数组的下标
            mark[t] = ++cnt;
            ans[cnt].id = t;
        }
        if (s[i].flag) {
            ans[mark[t]].house += s[i].num;
            ans[mark[t]].area += s[i].area;
        }
        ans[mark[t]].num++;
    }
    //求出各家庭的人均套房数和人均房产面积
    for (int i = 1; i <= cnt; i++) {
        ans[i].house /= ans[i].num;
        ans[i].area /= ans[i].num;
    }
    printf("%d\n", cnt);
    sort(ans + 1, ans + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].num, ans[i].house, ans[i].area);
    return 0;
}
