#include<bits/stdc++.h>
using namespace std;
#include<cstring>
#include<vector>
typedef long long int ll;
typedef long double ld;
typedef double db;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll tt; cin >> tt;

    for (ll ii = 0; ii < tt; ii++)
    {
        ll r, b, d; cin >> r >> b >> d;
        ll x = r - 1;
        ll y = (b - 1) * r;
        if (x + y == d) { cout << "YES" << endl; }
        else cout << "NO" << endl;
    }
    return 0;
}
