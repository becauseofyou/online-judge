#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 100010;
const int mod = 1000000007;
long long dp[65][65];
char s[110];
int n ;
long long dfs(int l,int r)
{
	if(l > r) return dp[l][r]=0;
	if(l == r)  return dp[l][r]=1 ;
	if(~dp[l][r]) return dp[l][r];
	dp[l][r] = 0;
	if(s[l]==s[r]) dp[l][r] += dfs(l+1,r-1)+1;
	dp[l][r] += dfs(l+1,r) + dfs(l,r-1) - dfs(l+1,r-1);
	return dp[l][r];
}
int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		n = strlen(s+1);
		memset(dp,-1,sizeof(dp));
		printf("Case %d: %lld\n",ca++,dfs(1,n));
	}
	return 0;
}