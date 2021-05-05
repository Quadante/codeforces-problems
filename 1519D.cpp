#include <iostream>
using namespace std;
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>    
#include <string.h>
#include <string>
#include <math.h>
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <set>
#include <unordered_set>
#include <bitset>
#include <list>
#define IOS std::ios::sync_with_stdio(false);
#define INF 0x3f3f3f3f
typedef long long ll;
typedef unsigned long long ull;
const int N = 5e3 + 5;
const int mod = 1000000007;
inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch != '\n' && ch != ' ') { s = s * 10 + ch - '0', ch = getchar(); }
    return s * w;
}
ll a[N];
ll b[N];
ll pre[N];
int main() {
    int n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        b[i] = read();
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i] * b[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll cur = a[i] * b[i];
        for (int l = i - 1, r = i + 1; l >= 1 && r <= n; l--, r++) {
            cur += a[l] * b[r] + a[r] * b[l];
            ans = max(ans, cur + pre[l - 1] + (pre[n] - pre[r]));
        }
        cur = 0;
        for (int l = i, r = i + 1; l >= 1 && r <= n; l--, r++) {
            cur += a[l] * b[r] + a[r] * b[l];
            ans = max(ans, cur + pre[l - 1] + (pre[n] - pre[r]));
        }
    }
    cout << max(ans, pre[n]);
}