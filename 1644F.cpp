#include<iostream>
#include<algorithm>
#define int long long
#define pl(x) ((x)<p?(x):(x)-p)
using namespace std;
const int p=998244353;
int n,k,s[200003],ans,c[200003],ic[200003],f[200003];
int powx(int x,int k){
	int e=1;
	while(k){
		if(k&1)e=e*x%p;
		x=x*x%p,k>>=1;
	}
	return e;
}
signed main(){
	cin>>n>>k;
	if(n==1||k==1){
		cout<<1;
		return 0;
	}
	c[0]=1;
	for(int i=1;i<=n;++i)c[i]=c[i-1]*i%p;
	ic[n]=powx(c[n],p-2);
	for(int i=n;i>=1;--i)ic[i-1]=ic[i]*i%p;
	f[0]=0;
	for(int i=1;i<=n;++i)f[i]=pl(f[i-1]+((i&1)?ic[i-1]:p-ic[i-1]));
	s[n]=1;
	for(int i=n;i>=1;--i){
		if(s[i]==0)continue;
		int x=0,m=min(i,k);
		for(int j=1;j<=m;++j){
			x=pl(x+powx(j,i)*f[m+1-j]%p*ic[j]%p);
		}
		ans=pl(ans+x*s[i]%p);
		for(int l=2,r;l<i;){
			x=(i-1)/l;
			r=(i-1)/x;
			s[x+1]=pl(s[x+1]+(r-l+1)*(p-s[i])%p);
			l=r+1;
		}
		s[1]=pl(s[1]+p-s[i]);
	} 
	cout<<ans<<endl;
}