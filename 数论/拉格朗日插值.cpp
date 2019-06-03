#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+100;
typedef long long ll;
const ll mod = 1e9+7;
ll p[N],x[N],s1[N],s2[N],ifac[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans%mod*a%mod)%mod;
		a=(a%mod*a%mod)%mod;
		b>>=1;
	}
	return (ans%mod+mod)%mod;
}

//拉格朗日插值，n项，每个点的坐标为(x_i,y_i)，求第xi项的值，保证x是连续的一段 
ll lagrange(ll n, ll *x, ll *y, ll xi) {
    ll ans = 0;
    s1[0] = (xi-x[0])%mod, s2[n+1] = 1;
    for (ll i = 1; i <= n; i++) s1[i] = 1ll*s1[i-1]*(xi-x[i])%mod;
    for (ll i = n; i >= 0; i--) s2[i] = 1ll*s2[i+1]*(xi-x[i])%mod;
    ifac[0] = ifac[1] = 1;
    for (ll i = 2; i <= n; i++) ifac[i] = -1ll*mod/i*ifac[mod%i]%mod;
    for (ll i = 2; i <= n; i++) ifac[i] = 1ll*ifac[i]*ifac[i-1]%mod;
    for (ll i = 0; i <= n; i++)
        (ans += 1ll*y[i]*(i == 0 ? 1 : s1[i-1])%mod*s2[i+1]%mod
            *ifac[i]%mod*(((n-i)&1) ? -1 : 1)*ifac[n-i]%mod) %= mod;
    return (ans+mod)%mod;
}
int main(){
	ll n,k;
	cin>>n>>k;
	if(k==0){
		cout<<n<<endl;
		return 0;
	}
	p[0]=0;
	for(ll i=1;i<=k+2;i++) p[i]=(p[i-1]%mod+qpow(i,k))%mod;
	for(ll i=1;i<=k+2;i++) x[i]=i;
	if(n<=k+2){
		cout<<p[n]<<endl;
	}
	else{
		cout<<lagrange(k+2,x,p,n)<<endl;
	}
	return 0;
}
