#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 5;
int n, k, m, p;
struct People {
    int id, money, num;
} s[maxn];
/**
  * 排序方式，看清楚题目的描述即可
  */
bool cmp(const People &A, People &B) {
    if (A.money == B.money) {
        if (A.num == B.num) return A.id < B.id;
        else return A.num > B.num;
    } else {
        return A.money > B.money;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        int sum = 0;
        for (int j = 1; j <= k; j++) {
            cin >> m >> p;
            s[m].money += p;
            s[m].num++;
            sum += p;
        }
        s[i].id = i;
        s[i].money -= sum;
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        printf("%d %.2f\n", s[i].id, s[i].money / 100.0);
    return 0;
}
