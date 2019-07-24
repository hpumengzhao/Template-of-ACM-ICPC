# include<bits/stdc++.h>

using namespace std;
const int maxn=1000000+10;
int rt[maxn],ls[maxn*2],rs[maxn*2],sum[maxn*2];
int a[maxn],b[maxn];
int tot,N,n,q;
void build(int& o,int l,int r){
	o=++tot;
	sum[o]=0;
	if(l==r) return ;
	int m=(l+r)/2;
	build(ls[o],l,m);
	build(rs[o],m+1,r);
}
void update(int& o,int l,int r,int last,int k){
	o=++tot;
	ls[o]=ls[last];
	rs[o]=rs[last];
	sum[o]=sum[last]+1;
	if(l==r) return ;
	int m=(l+r)/2;
	if(k<=m) update(ls[o],l,m,ls[last],k);
	else update(rs[o],m+1,r,rs[last],k);
}
int query(int s,int e,int l,int r,int k){
	if(l==r) return l;
	int cnt=sum[ls[e]]-sum[ls[s]];
	int m=(l+r)/2;
	if(k<=cnt) return query(ls[s],ls[e],l,m,k);
	else return query(rs[s],rs[e],m+1,r,k-cnt);
}
int main()
{
	int t;
	int l,r,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		tot=0;
		sort(b+1,b+n+1);
		N=unique(b+1,b+n+1)-(b+1);
		build(rt[0],1,N);
		for(int i=1;i<=n;i++) update(rt[i],1,N,rt[i-1],lower_bound(b+1,b+N+1,a[i])-b);
		while(q--){
			scanf("%d %d %d",&l,&r,&k);
			int ans=query(rt[l-1],rt[r],1,N,k);
			printf("%d\n",b[ans]);
		}
	}
	return 0;
}
