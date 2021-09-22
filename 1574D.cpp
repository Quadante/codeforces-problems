    #include <random>
    #include <stdio.h>
    #include <bits/stdc++.h>
    #include <unordered_set>
    #include <unordered_map>
     
     
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<ll, ll> pll;
    typedef pair<ll, int> pli;
    typedef pair<int, ll> pil;
    typedef pair<int, int> pii;
     
    #define ls rt<<1
    #define rs ls|1
    #define fst first
    #define sed second
    #define psb push_back
    #define lowbit(x) ((x) & -(x))
    #define SZ(x) ((int)(x).size())
    #define sqr(x) (1LL * (x) * (x))
    #define sqrd(x) ((x) * (x))
    #define ALL(x) (x).begin(), (x).end()
    #define MEM(x, y) memset((x), (y), sizeof(x))
    #define Diz(x) (lower_bound(dz.begin(), dz.end(), (x)) - dz.begin())
    #define DISCRETE(x) (x).push_back(INT_MIN), (sizeof((x).back()) == 8 ? (x).back() = LLONG_MIN : 0), sort((x).begin(), (x).end()), (x).erase(unique((x).begin(), (x).end()), (x).end())
     
    #ifdef MPDFDFL
    #define debug(x) cout << "[" __FUNCTION__ ": " #x " = " << (x) << "]\n"
    #define TIME cout << "RuningTime: " << clock() << "ms\n", 0
    #define __int128_t long long
    #define __gcd(x, y) gcd((x), (y))
    #define __builtin_popcount(x) _BitCnt((uint)(x))
    #define __builtin_popcountll(x) _BitCnt((ull)(x))
    #define __lg (int)log2
    #else
    #define TIME 0
    #endif
    #define hash_ 1000000009
    #define gc p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
    #define IOS ios::sync_with_stdio(0), cin.tie(0)
     
    template<typename S, typename T> inline bool Min(S& a, const T& b) { return a > b ? a = b, true : false; }
    template<typename S, typename T> inline bool Max(S& a, const T& b) { return a < b ? a = b, true : false; }
    template<class T> inline bool IsPri(T x) { if (x < 2) return false; for (T i = 2; i * i <= x; ++i) if (x % i == 0) return false; return true; }
    template<class T> T gcd(T a, T b) { a = abs(a), b = abs(b); return b == 0 ? a : gcd(b, a % b); };
    template<typename T> inline int _BitCnt(T x) { int cnt = 0; while (x)++cnt, x &= x - 1; return cnt; }
    template<class T>double dpow(double a, T b) { double res = 1.0; for (; b > 0; b >>= 1) { if (b & 1)res = res * a; a = a * a; }return res; }
    inline int read() { static char buf[1000000], * p1 = buf, * p2 = buf; int x = false; char ch = gc; bool sgn = false; while (ch != '-' && (ch < '0' || ch > '9')) ch = gc; if (ch == '-') sgn = true, ch = gc; while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc; return sgn ? -x : x; }
    ll qpow(ll a, ll b, ll mod) { ll res = 1; for (; b > 0; b >>= 1) { if (b & 1) res = res * a % mod; a = a * a % mod; } return res; }
    inline ll inv(ll a, ll p) { return qpow(a, p - 2, p); }
     
    int dx[4] = { 1,0,0,-1 };
    int dy[4] = { 0,-1,1,0 };
    char sn[4] = { 'D', 'L', 'R', 'U' };
    const int mod = 1e9 + 7;
    const int INF = 0x3f3f3f3f;
    const ll LINF = 0x3f3f3f3f3f3f3f3f;
    const int N = 1e5 + 10;
    const int M = 1e6 + 10;
    const double PI = acos(-1.0);
    const double eps = 1e-8;
     
    const ull base = 2333333;
     
    map<ull, bool>ji;
    int c[N];
    vector<ll>b[N];
    int n, m;
    struct node {
    	ll num;
    	int k = 0;
    	vector<int>ans;
    	bool operator < (const node &a)const {
    		return num < a.num;
    	}
    };
    vector<node>a;
    node res[N];
    ll jinow = 0;
    void meg(int pos) {
    	priority_queue<node>q;
    	if (jinow <= m + 1)
    		jinow *= c[pos];
    	for (int i = 1; i <= c[pos]; i++)
    	{
    		node tmpn = a[0];
    		tmpn.num = a[0].num + b[pos][i - 1];
    		tmpn.ans.push_back(i);
    		tmpn.k = 0;
    		q.push(tmpn);
    	}
    	
    	int cnt = 0;
    	while (cnt < min(jinow, 1ll * m + 1)) {
    		node tmp = q.top();
    		q.pop();
    		res[++cnt] = tmp;
    		if (tmp.k == a.size() - 1)
    			continue;
    		tmp.num = tmp.num - a[tmp.k].num + a[tmp.k + 1].num;
    		tmp.k++;
    		int now = tmp.ans.back();
    		tmp.ans = a[tmp.k].ans;
    		tmp.ans.push_back(now);
    		
    		q.push(tmp);
    	}
    	int cntn = 0;
    	a.clear();
    	for (int i = 1; i <= min(jinow, 1ll * m + 1); i++)
    		if (res[i].ans.size() == pos)
    			a.push_back(res[i]);
    }
    int main() {
    #ifdef MPDFDFL
    	freopen("D:/input.txt", "r", stdin);
    	//freopen("D:/output.txt", "w", stdout);
    #endif
    	scanf("%d", &n);
    	for (int i = 1; i <= n; i++) {
    		scanf("%d", &c[i]);
    		//b[i].push_back(LINF);
    		for (int j = 1; j <= c[i]; j++) {
    			ll x;
    			scanf("%lld", &x);
    			b[i].push_back(x);
    		}
    		reverse(ALL(b[i]));
    	}
    	scanf("%d", &m);
    	for (int i = 1; i <= m; i++) {
    		ull tmp = 0;
    		for (int j = 1; j <= n; j++) {
    			int x;
    			scanf("%d", &x);
    			tmp = tmp * base + ull(x);
    		}
    		ji[tmp] = 1;
    	}
    	for (int i = 1; i <= c[1]; i++) {
    		node tmpn;
    		tmpn.num = b[1][i - 1];
    		tmpn.ans.push_back(i);
    		a.push_back(tmpn);
    	}
    	jinow = a.size();
    	for (int i = 2; i <= n; i++) {
    		meg(i);
    	}
    	for (int i = 0; i < m + 1; i++) {
    		ull tmp = 0;
    		for (int j = 1; j <= n; j++) {
    			tmp = tmp * base + ull(c[j] - a[i].ans[j - 1] + 1);
    		}
    		if (ji[tmp])
    			continue;
    		for (int j = 1; j <= n; j++) {
    			printf("%d ", c[j] - a[i].ans[j - 1] + 1);
    		}
    		return 0;
    	}
    	cout << m << " " << a.size() << endl;
    	return TIME;
    }