#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;

/**
  * 因为题目描述写这个属性是正数
  * 故num, price都要用double类型
  */
struct Food {
    double num, price;
    double pri;
} f[maxn];


bool cmp (const Food &A, const Food &B) {
    return A.pri > B.pri;
}

int main()
{
    int n, need;
    scanf("%d %d", &n, &need);
    for (int i = 0; i < n; i++) scanf("%lf", &f[i].num);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &f[i].price);
        f[i].pri = f[i].price / f[i].num;
    }
    sort(f, f + n, cmp);
    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (f[i].num < need) {
            ans += f[i].price;
            need -= f[i].num;
        } else {
            ans += need * f[i].pri;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
