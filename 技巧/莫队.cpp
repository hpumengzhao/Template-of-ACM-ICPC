 
#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const int maxn = 5e5+100;
const int maxm =1e6+100;
ll re[maxm];
ll a[maxn],anss[maxn];
struct query{
    ll l,r,id;
    ll ans;
}e[maxn];
ll ans,bl;
inline int read()
{
     int k=0;
     char c;
     c=getchar();
     while(!isdigit(c))c=getchar();
     while(isdigit(c)){k=(k<<3)+(k<<1)+c-'0';c=getchar();}
     return k;
}
void remove(int pos){
    ans-=a[pos]*((re[a[pos]]*re[a[pos]])-(re[a[pos]]-1)*(re[a[pos]]-1));
    re[a[pos]]--;
}
void add(int pos){
     ans+=a[pos]*(-(re[a[pos]]*re[a[pos]])+(re[a[pos]]+1)*(re[a[pos]]+1));
     ++re[a[pos]];
}
bool cmp1(query a,query b){
    return (a.l/bl==b.l/bl)?a.r<b.r:a.l<b.l;
}
bool cmp2(query a,query b){
    return a.id<=b.id;
}
int n,m,i;
int main(){
    //freopen("1.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(i=1;i<=m;i++){
        scanf("%lld %lld",&e[i].l,&e[i].r);
        e[i].id=i;
    }
    bl=sqrt(n);
    sort(e+1,e+m+1,cmp1);
    ans=0;
    int L,R;
    int curl=1;int curr=0;
    for(i=1;i<=m;i++){
        L=e[i].l;R=e[i].r;
        while(curl<L) remove(curl++);
        while(curl>L) add(--curl);
        while(curr>R) remove(curr--);
        while(curr<R) add(++curr);
        anss[e[i].id]=ans;
    }
    for(i=1;i<=m;i++){
       printf("%lld\n",anss[i]);
    }
    return 0;
}

//O(nlog(n))
