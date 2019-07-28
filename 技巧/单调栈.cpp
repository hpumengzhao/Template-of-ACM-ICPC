stack<long long> sta;
for(int i=1;i<=n;i++){
	while(sta.size()&&a[sta.top()]>=a[i]) sta.pop();
	if(sta.empty()) L[i]=1;
	else L[i]=sta.top()+1;
	sta.push(i);
}
while(sta.size()) sta.pop();
for(int i=n;i>=1;i--){
	while(sta.size()&&a[sta.top()]>=a[i]) sta.pop();
	if(sta.empty()) R[i]=n;
	else R[i]=sta.top()-1;
	sta.push(i);
}
