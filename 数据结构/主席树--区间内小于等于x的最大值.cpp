struct node
{
	ll sum,l,r;
}t[maxn*32];
int cnt;
void update(ll l,ll r,ll &x,ll y,ll pos){
	t[++cnt]=t[y];t[cnt].sum++;x=cnt;//复制节点并且更新
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(mid>=pos) update(l,mid,t[x].l,t[y].l,pos);
	else update(mid+1,r,t[x].r,t[y].r,pos);
}
int query(int a,int b,int x,int l,int r)
{
	if(l==r)
	{
		if(l==x)
			return 0;
		else
			return l;
	}
	int mid=(l+r)>>1;
	int xx=t[t[b].l].sum-t[t[a].l].sum;
	int yy=t[t[b].r].sum-t[t[a].r].sum;
	int res=0;
	if(yy&&x>mid)
		res=query(t[a].r,t[b].r,x,mid+1,r);
	if(xx&&!res)
		res=query(t[a].l,t[b].l,x,l,mid);
	return res;
}

for(int i=1;i<=n;i++) update(1,n,roots[i],roots[i-1],a[i]);
query(roots[L-1],roots[R],x,1,n);
