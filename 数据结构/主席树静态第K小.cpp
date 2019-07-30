#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+100;
struct node{
	int l,r,num;
}T[N*30];
vector<int> v;
int n,m,a[N],t,cnt,roots[N];
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void update(int l,int r,int &x,int y,int pos){
	T[++cnt]=T[y];T[cnt].num++;x=cnt;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(pos<=mid) update(l,mid,T[x].l,T[y].l,pos);
	else update(mid+1,r,T[x].r,T[y].r,pos);
}
int query(int l,int r,int x,int y,int k){
	if(l==r) return l;
	int sum=T[T[x].l].num-T[T[y].l].num;
	int mid=(l+r)>>1;
	if(sum>=k) return query(l,mid,T[x].l,T[y].l,k);
	else return query(mid+1,r,T[x].r,T[y].r,k-sum);
}
int main(){
	scanf("%d",&t);
	while(t--){
		v.clear();
		cnt=0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			v.push_back(a[i]);
		}
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		for(int i=1;i<=n;i++) update(1,n,roots[i],roots[i-1],getid(a[i]));
		while(m--){
			int l,r,k;
			scanf("%d %d %d",&l,&r,&k);
			printf("%d\n",v[query(1,n,roots[r],roots[l-1],k)-1]);
		}
	}
	return 0;
}
