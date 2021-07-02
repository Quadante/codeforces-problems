#include <bits/stdc++.h>
using namespace std;
#define fast       ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define prt(v);    for(auto &i:v) cout<<i<<" "; cout<<"\n";
#define take(v);   for(auto &i:v) cin>>i;
#define ll         long long
#define vi(x,n)    vector<int> x(n,0);
#define vl(x,n)    vector<long long> x(n,0);
#define pb         push_back
#define alr(s)     s.rbegin(),s.rend()
#define all(s)     s.begin(),s.end()
#define fi         first
#define sc         second

int main()
{
    fast;
    ll t; cin >> t;
    while (t--) {
        ll k = 0, n; cin >> n; vl(v, n); vl(p, n);
        vector<pair<pair<ll, ll>, pair<ll, ll>>>a;
        ll s = 2e15, d;
        for (ll i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] < s) s =R v[i], d = i;
        }
        ll w = 0, i = d - 1, e = s + 1; p[d] = s;
        while (i >= 0) {
            if (w == 0) p[i] = e;
            else p[i] = s;
            w = 1 - w; i--;
        }
        i = d + 1; w = 0;
        while (i < n) {
            if (w == 0) p[i] = e;
            else p[i] = s;
            w = 1 - w; i++;
        }
        //prt(v); prt(p);
        for (ll i = 0; i < n; i++) {
            if (p[i] != v[i]) {
                if (i < d) a.pb({ {i + 1,d + 1},{(p[i] == s) ? s : e,s} });
                else a.pb({ {d + 1,i + 1},{s,(p[i] == s) ? s : e} });
                k++;
            }
        }
        cout << k << "\n";
        for (auto i : a) cout << i.fi.fi << " " << i.fi.sc << " " << i.sc.fi << " " << i.sc.sc << "\n";
    }
    return 0;
}