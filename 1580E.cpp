    #include <iostream>
    #include <cstdio>
    #include <cmath> 
    #include <cstring> 
    #include <queue>
    #include <utility> 
    #include <algorithm> 
    #include <set> 
    #define MAXN 200020 
    #define MAXM 600060 
    #define INF 0x3f3f3f3f 
    #define INF64 0x3f3f3f3f3f3f3f3fll 
    using namespace std;
    using ull=unsigned long long;
    using ll=long long;
    ull res[MAXN],ans;ll dis[MAXN],w[MAXN];
    int n,m,q,qs[MAXN][2],pos[MAXN],endpos[MAXN],sum[MAXN];
    int tot=1,head[MAXN],a[MAXN],t,cnt[MAXN],fa[MAXN],rt[MAXN];
    set<int> s;
    struct Node{
        int f,s;
        Node(int a=0,int b=0):f(a),s(b){}
        bool operator==(const Node&b)const{return f==b.f&&s==b.s;}
        void swap(){int t=f;f=s;s=t;}
    }minv,val[MAXN];
     
    struct Edge{
        int to,nxt,w;
    }edge[MAXM];
    void addedge(int u,int v,int w){
        edge[++tot].to=v;edge[tot].w=w;edge[tot].nxt=head[u];head[u]=tot;
    }
    namespace SGT{
        const int MAX=10000000;
        int tot;
        struct Node{
            int sum,ls,rs;
        }node[MAX];
        void modify(int &i,int l,int r,int x){
            i=i?i:++tot;
            node[i].sum++;
            if(l==r)return;
            int m=(l+r)>>1;
            m<x?modify(node[i].rs,m+1,r,x):modify(node[i].ls,l,m,x);
        }
        int query(int i,int l,int r,int ql,int qr){
            if(!i)return 0;
            if(l>=ql&&qr>=r)return node[i].sum;
            int m=(l+r)>>1,res=0;
            if(m>=ql)res=query(node[i].ls,l,m,ql,qr);
            if(m<qr)res+=query(node[i].rs,m+1,r,ql,qr);
            return res;
        }
    }
    int count_illegal(int idx,int l,int r){
        if(r<l||idx==1)return 0;
        return SGT::query(rt[idx],1,n,l,r);
    }
    int count_legal(int idx,int l,int r){
        if(r<l)return 0;
        return sum[r]-sum[l-1]-count_illegal(idx,l,r);
    }
    int main(){
    #ifdef WINE
        freopen("data.in","r",stdin);
    #endif
        scanf("%d%d%d",&n,&m,&q);
        for(int i=1;i<=n;i++){scanf("%d",&w[i]);pos[i]=n+1;}
        for(int i=1;i<=m;i++){
            int u,v,d;scanf("%d%d%d",&u,&v,&d);
            addedge(u,v,d);addedge(v,u,d);
        }
        for(int i=1;i<=q;i++){
            scanf("%d%d",&qs[i][0],&qs[i][1]);
            w[qs[i][0]]+=qs[i][1];
        }
        // single source shortest path
        memset(dis,INF,sizeof(dis));dis[1]=0;
        priority_queue<pair<ll,int>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            int u=pq.top().second;
            ll d=-pq.top().first;
            pq.pop();
            if(dis[u]!=d)continue;
            a[++t]=u; // with dis increasing 
            for(int i=head[u];i;i=edge[i].nxt){
                int v=edge[i].to;
                if(d+edge[i].w<dis[v]){
                    dis[v]=d+edge[i].w;
                    pq.push({-dis[v],v});
                }
            }
        }
        for(int i=2;i<=tot;i++){
            int u=edge[i^1].to,v=edge[i].to;
            if(dis[u]+edge[i].w==dis[v]){
                cnt[v]++;fa[v]=u;
            }
        }
        ans=0;s.insert(1);pos[1]=1;minv.f=1;minv.s=n+1;
        val[1]=minv;
        w[n+1]=INF64;
        for(int i=2,j=2;i<=n;i++){
            int u=a[i];
            for(;dis[a[j]]<dis[u];j++){
                int v=a[j];
                pos[v]=i;
                if(w[v]<w[minv.f]){
                    s.insert(i);
                    endpos[minv.f]=i;
                    minv.s=minv.f;
                    minv.f=v;
                    val[i]=minv;
                }else if(w[v]<w[minv.s]){
                    s.insert(i);
                    minv.s=v;
                    val[i]=minv;
                }
            }
            sum[i]=sum[i-1];
            if(cnt[u]<2){
                sum[i]++;
                if(fa[u]>1)SGT::modify(rt[fa[u]],1,n,i);
                ans+=w[(minv.f==1||minv.f!=fa[u])?minv.f:minv.s];
            }
        }
        endpos[minv.f]=n+1;
        s.insert(n+1);
        res[q]=ans;
        for(int i=q;i>=1;i--){
            int k=qs[i][0],x=qs[i][1];
            w[k]-=x;
            if(pos[k]>n){
                res[i-1]=ans;
                continue;
            }
            auto it=--s.upper_bound(pos[k]);
            auto lst=it;
            minv=Node();
            int rsp=0,p=pos[k];
            if(k==val[*it].f)rsp=1;
            else if(k==val[*it].s)rsp=2;
            while (rsp >= 0 && *it <= n) {
                lst = it ++;
                if (rsp == 0) {
                    if (w[val[*lst].s] <= w[k]) break;
                    if (w[k] < w[val[*lst].f]) {
                        if (!minv.f) endpos[val[*lst].f] = p;
                        int c = count_illegal(val[*lst].f, p, (*it) - 1), tot = sum[(*it) - 1] - sum[p - 1];
                        ans -= 1ull * c * w[val[*lst].s] + 1ll * (tot - c) * w[val[*lst].f];
                        if (p != *lst) val[p] = val[*lst];
                        val[p].s = val[p].f;
                        val[p].f = k;
                        c = count_illegal(k, p, (*it) - 1);
                        ans += 1ull * c * w[val[p].s] + 1ll * (tot - c) * w[k];
                        if (p != *lst) {
                            s.insert(p);
                            minv = val[p];
                        }else if (minv == val[p]) s.erase(lst);
                        else minv = val[p];
                        endpos[k] = p = *it;
                    }else {
                        ans += 1ull * count_illegal(val[*lst].f, p, (*it) - 1) * (w[k] - w[val[*lst].s]);
                        if (p != *lst) val[p] = val[*lst];
                        val[p].s = k;
                        if (p != *lst) {
                            s.insert(p);
                            minv = val[p];
                        }else if (minv == val[p]) s.erase(lst);
                        else minv = val[p];
                        p = *it;
                    }
                }else if (rsp == 1) {
                    it = s.lower_bound(endpos[k]);
                    ans -= 1ull * count_legal(k, p, (*it) - 1) * x;
                    p = *it; lst = it; lst --;
                    minv = val[*lst];
                    rsp = val[p].s == k ? 2 : 0;
                }else {
                    if (w[val[*lst].f] <= w[k]) {
                        ans -= 1ull * count_illegal(val[*lst].f, p, (*it) - 1) * x;
                        minv = val[*lst]; p = *it;
                    }else {
                        endpos[val[*lst].f] = p;
                        int c = count_illegal(val[*lst].f, p, (*it) - 1), tot = sum[(*it) - 1] - sum[p - 1];
                        ans -= 1ull * c * (w[val[*lst].s] + x) + 1ull * (tot - c) * w[val[*lst].f];
                        if (p != *lst) val[p] = val[*lst];
                        val[p].swap();
                        c = count_illegal(val[p].f, p, (*it) - 1);
                        ans += 1ull * c * w[val[p].s] + 1ull * (tot - c) * w[val[p].f];
                        if (p != *lst) {
                            s.insert(p);
                            minv = val[p];
                        }else if (minv == val[p]) s.erase(lst);
                        else minv = val[p];
                        endpos[k] = p = *it;
                    }
                    rsp = 0;
                }
            }
            res[i - 1] = ans;
        }
        for (int i = 0; i <= q; i ++) printf("%llu\n", res[i]);
        return 0; 
    }