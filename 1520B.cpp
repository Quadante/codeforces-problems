#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define _for(i, a, b) for(int i = a; i < b; i++)
#define _rep(i, a, b) for(int i = a; i <= b; i++)
#define x first
#define y second
using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

const int MAXN = 1e5 + 10;

long long t, n, ans;

long long lencnt(long long u) {
    long long ret = 1;
    u /= 10;
    while (u) {
        ret++;
        u /= 10;
    }
    return ret;
}

int main() {
    cin >> t;
    while (t--) {
        // _rep(n, 1, 100) {
        cin >> n;
        long long len = lencnt(n);
        ans = (len - 1) * 9;
        long long temp = 1;
        _for(i, 0, len - 1)
            temp = temp * 10 + 1;
        _rep(i, 1, 9)
            if (temp * i <= n) ans++;
        cout << ans << endl;
    }

    // system("pause");
    return 0;
}