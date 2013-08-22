#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = ~0u>>2;
int dp[1010];
char s[1010];
int n;
bool ok(int l,int r)
{
	//printf("dddd");
	while(l<=r)
	{
		if(s[l]!=s[r]) return false;
		l++;
		r--;
	}
	return true;
}
int dfs(int l)
{
	if(l>n) return 0;
	if(~dp[l]) return dp[l];
	dp[l] = inf;
	for(int i = l; i <= n; i++)
	{
		if(ok(l,i))
		{
		//	printf("l=%d i=%d\n",l,i);
			dp[l] = min(dp[l],dfs(i+1)+1);
		}
	}
	return dp[l];
}
int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%s",s+1);
		n = strlen(s+1);
		//memset(dp,-1,sizeof(dp));
		fill(dp,dp+n+1,-1);
		printf("Case %d: %d\n",ca++,dfs(1));
	}
	return 0;
}