
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>
#include <cstdlib>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f3f3f3f3f;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second

const int MAXN = 20005;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    getline(cin, s);
    int n = s.size();
    ll sum = 0;
    vector<int> numTableStarts(n);
    for (int p = 2; p <= n / 2; ++p) {
        //cout << p << endl;
        int farthestUBorder = -1;
        int farthestDBorder = -1;
        int farthestCentral = -1;
        for (int i = 0; i < n; ++i) {
            char l = (i - 1 >= 0 && s[i - 1] == 'R');
            char r = (i + 1 < n && s[i + 1] == 'L');
            char d = (i + p < n && s[i + p] == 'U');
            char u = (i - p >= 0 && s[i - p] == 'D');
            bool isCentral = l + r + d + u == 1;

            bool isRBorder = l + d + u == 1;
            bool isUBorder = l + d + r == 1;
            bool isDBorder = l + u + r == 1;
            bool isRUCorner = l + d == 1;
            bool isRDCorner = l + u == 1;

            int j = i - p + 1;
            char jr = (j + 1 < n && s[j + 1] == 'L');
            char jd = (j + p < n && s[j + p] == 'U');
            char ju = (j - p >= 0 && s[j - p] == 'D');
            bool isjLBorder = jr + jd + ju == 1;
            bool isjLUCorner = jr + jd == 1;
            bool isjLDCorner = jr + ju == 1;

            bool isMiddle = isRBorder & isjLBorder & (farthestCentral <= j);
            bool isHeader = isRUCorner & isjLUCorner & (farthestUBorder <= j);
            bool isFooter = isRDCorner & isjLDCorner & (farthestDBorder <= j);

            numTableStarts[i] = 0;
            if (isMiddle && i - p >= 0) {
                numTableStarts[i] += numTableStarts[i - p];
            }
            if (isHeader) {
                numTableStarts[i] += 1;
            }
            if (isFooter && i - p >= 0) {
                sum += numTableStarts[i - p];
            }

            farthestCentral = isCentral ? farthestCentral : i;
            farthestUBorder = isUBorder ? farthestUBorder : i;
            farthestDBorder = isDBorder ? farthestDBorder : i;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i; j < n - 1; j += 2) {
            if (s[j] == 'D' && s[j + 1] == 'U') {
                ++sum;
            } else {
                break;
            }
        }
    }
    vector<int> cnt(MAXN + 1, 0);
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                ++cnt[i];
                if (j * j != i) {
                    ++cnt[i];
                }
            }
        }
        if (i > 1) {
            ++cnt[i];
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i; j < n - 1; j += 2) {
            if (s[j] == 'R' && s[j + 1] == 'L') {
                sum += 1 - cnt[(j - i + 2) / 2];
            } else {
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
