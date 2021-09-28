    #include <bits/stdc++.h>
    #define rep(a,b,c) for(int a=(b);a<=(c);a++)
    #define per(a,b,c) for(int a=(b);a>=(c);a--)
    #define mem(a,b) memset(a,b,sizeof(a))
    #define pb emplace_back
    #define ll long long
    using namespace std;
    const int p=998244353;
    inline int inc(int x,int y) { if((x+=y)>=p) x-=p; return x; }
    inline void Inc(int &x,int y) { x=inc(x,y); }
    const int N=3e5+5;
    int fa[N],sz[N];
    inline int ksm(int a,int b) { int ans=1; for(;b;b>>=1,a=1ll*a*a%p) if(b&1) ans=1ll*a*ans%p; return ans; }
    inline int find(int x) { return (fa[x]==x)?x:fa[x]=find(fa[x]); }
    int n,m,k,las[N],nex[N],fi[N],a[N],ava[N],tag[N],C[N],tot,B[N],Ky[N],f[N];
    inline void merge(int x,int y) {
    	x=find(x); y=find(y);
    	if(x==y) return;
    	if(sz[x]<sz[y]) swap(x,y);
    	fa[y]=x; sz[x]+=sz[y];
    }
    inline void solve() {
    	scanf("%d %d %d",&n,&m,&k);
    	rep(i,1,k) fa[i]=i,sz[i]=1;
    	rep(asd,1,n) {
    		int A;
    		scanf("%d",&A);
    		rep(i,1,A) scanf("%d",&a[i]);
    		rep(i,1,A) fi[a[i]]=0;
    		rep(i,1,A) {
    			if(fi[a[i]]) ava[a[i]]=1;
    			fi[a[i]]=1;
    		}
    		rep(i,2,A) {
    			merge(a[i],a[1]);
    			if(!las[a[i]]) las[a[i]]=a[i-1];
    			else if(las[a[i]]!=a[i-1]) ava[a[i]]=1;
    		}
    		rep(i,1,A-1) {
    			if(!nex[a[i]]) nex[a[i]]=a[i+1];
    			else if(nex[a[i]]!=a[i+1]) ava[a[i]]=1;
    		}
    	}
    	rep(i,1,k) ava[find(i)]|=ava[i],tag[find(i)]|=(!nex[i]);
    	rep(i,1,k) if(fa[i]==i&&!ava[i]&&tag[i]) {
    		if(!Ky[sz[i]]) Ky[sz[i]]=(++tot),B[tot]=sz[i];
    		C[Ky[sz[i]]]++;
    	}
    	f[0]=1;
    	rep(i,1,m) rep(j,1,tot) if(B[j]<=i) Inc(f[i],1ll*f[i-B[j]]*C[j]%p);
    	printf("%d\n",f[m]);
    }
    int main() {
    	//int T; cin>>T; while(T--)
    	solve();
    }