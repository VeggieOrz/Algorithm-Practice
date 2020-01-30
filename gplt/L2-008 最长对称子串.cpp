#include <bits/stdc++.h>

using namespace std;
int len, ans;
string str;

int main()
{
    //输入带空格的字符串
    getline(cin, str);
    len = str.length();
    /**
      * i表示中心点的位置
      * j表示从中心点开始的延伸长度
      * 当两边字符不相等、延伸超过字符串范围时停止循环
      */
    for (int i = 0; i < len; i++) {
        //回文串长度为奇数
        for (int j = 0; (i - j) >= 0 && (i + j < len) && str[i - j] == str[i + j]; j++)
            ans = max(j * 2 + 1, ans);
        //回文串长度为偶数
        for (int j = 0; (i - j) >= 0 && (i + j + 1) < len && str[i - j] ==  str[i + j + 1]; j++)
            ans = max((j + 1) * 2, ans);
    }
    cout << ans << endl;
    return 0;
}
