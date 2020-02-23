#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;
int n, m;

/**
  * Heap[] 存储的是堆
  * mapper 存储值为i的节点在Heap[]中的下标
  */
int Heap[maxn];
map<int, int> mapper;

/**
  * 建堆操作，将temp调整到堆中正确的位置
  * temp是要插入到堆中的值，idx是它所在的下标
  */
void addNode(int temp, int idx) {
    while (idx > 1 && temp  < Heap[idx / 2]) {
        Heap[idx] = Heap[idx / 2];
        idx /= 2;
    }
    Heap[idx] = temp;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t; cin >> t;
        //插入到堆中
        addNode(t, i);
    }
    //存储映射关系
    for (int i = 1; i <= n; i++) mapper[Heap[i]] = i;
    while (m--) {
        int x, y;
        string s, s1, s2, s3, s4;
        cin >> x >> s;
        if (s == "is") {
            cin >> s1 >> s2;
            s3 = s1 + s2;
            if (s3 == "theroot") {
                //根节点的判断
                printf("%c\n", (mapper[x] == 1) ? 'T' : 'F');
            } else if (s3 == "theparent") {
                //父亲节点的判断
                cin >> s4 >> y;
                printf("%c\n", (mapper[x] == mapper[y]/2) ? 'T' : 'F');
            } else {
                //子节点的判断
                cin >> s4 >> y;
                printf("%c\n", (mapper[x]/2 == mapper[y]) ? 'T' : 'F');
            }
        } else {
            //兄弟的节点的判读
            cin >> y >> s1 >> s2;
            printf("%c\n", (mapper[x]/2 == mapper[y]/2) ? 'T' : 'F');
        }
    }
    return 0;
}
