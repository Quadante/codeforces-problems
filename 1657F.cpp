#include <bits/stdc++.h>
using namespace std;
const int N = 4e6;
vector<int> edge[N], sat[N];
int n, m;
bool vis[N], vis2[N * 2];
int fa[N], sta[N * 2], top, cnt, dfn[N], low[N], deep[N], mid[N], belong[N], tot;
char a1[N], fi[N], se[N];
void dfs(int x, int f)
{
    fa[x] = f;
    deep[x] = deep[f] + 1;
    for (int i = 0; i < edge[x].size(); i++)
    {
        int to = edge[x][i];
        if (to != f)
            dfs(to, x);
    }
}
void tarjan(int x)
{

    dfn[x] = ++cnt;
    low[x] = cnt;
    sta[++top] = x;
    vis2[x] = 1;
    for (int i = 0; i < sat[x].size(); i++)
    {
        int to = sat[x][i];
        if (!dfn[to])
        {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        }
        if (vis2[to])
            low[x] = min(low[x], dfn[to]);
    }
    if (low[x] == dfn[x])
    {
        tot++;
        int now;
        do
        {
            belong[now = sta[top--]] = tot;
            vis2[now] = 0;
        } while (now != x);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n - 1; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        edge[l].push_back(r);
        edge[r].push_back(l);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d %d %s", &l, &r, a1 + 1);
        int head = 1, len = strlen(a1 + 1), lenth = len;
        int poss = 2 * n + i, posnf = poss + m;
        while (head <= lenth)
        {
            if (deep[l] > deep[r])
                mid[head++] = l, l = fa[l];
            else
                mid[lenth--] = r, r = fa[r];
        }

        for (int j = 1; j <= len; j++)
        {
            int x = mid[j];
            if (!vis[x])
                vis[x] = 1, fi[x] = a1[j], se[x] = a1[len - j + 1];
            if (fi[x] != a1[j])
                sat[x].push_back(posnf), sat[poss].push_back(x + n);
            if (se[x] != a1[j])
                sat[x + n].push_back(posnf), sat[poss].push_back(x);
            if (fi[x] != a1[len - j + 1])
                sat[x].push_back(poss), sat[posnf].push_back(x + n);
            if (se[x] != a1[len - j + 1])
                sat[x + n].push_back(poss), sat[posnf].push_back(x);
        }
    }

    for (int i = 1; i <= 2 * (m + n); i++)
        if (dfn[i] == 0)
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (belong[i] == belong[i + n])
        {

            puts("NO\n");
            return 0;
        }
    for (int i = 1; i <= m; i++)
        if (belong[2 * n + i] == belong[2 * n + i + m])
        {
            puts("NO\n");
            return 0;
        }
    puts("YES");
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            putchar('b');
        else
            putchar(belong[i] < belong[i + n] ? fi[i] : se[i]);
    }
    return 0;
}
