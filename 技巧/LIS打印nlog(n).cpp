#include<bits/stdc++.h>
using namespace std;
 
const int inf = 0x3f3f3f3f;
const int mx = int(1e5) + 5;
 
int a[mx], dp[mx], pos[mx], fa[mx];
vector<int> ans;
 
int get_lis(int n)
{
	memset(dp, 0x3f, sizeof(dp));
	pos[0] = -1;
	int i, lpos;
	for (i = 0; i < n; ++i)
	{
		dp[lpos = (lower_bound(dp, dp + n, a[i]) - dp)] = a[i];
		pos[lpos] = i; /// *靠后打印
		fa[i] = (lpos ? pos[lpos - 1] : -1);
	}
	n = lower_bound(dp, dp + n, inf) - dp;//一定要先求出来LIS长度
	for (i = pos[n - 1]; ~fa[i]; i = fa[i]) ans.push_back(a[i]);
	ans.push_back(a[i]); //注意最后一个也要加上
	return n;
}
