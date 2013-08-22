#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = ~0u>>2;
int dp[1<<15];
int hp[15];
int two[16];
char mp[20][20];
int a[20][20];
int main()
{
	two[0] = 1;
	for(int i = 1; i < 16; i++) two[i] = two[i-1] * 2;
	int t,ca=1,n;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
		for(int i = 0; i < n; i++) scanf("%d",&hp[i]);
		for(int i = 0; i < n; i++)
		{
			scanf("%s",mp[i]);
			for(int j = 0; j < n; j++)
			{
				a[i][j] = mp[i][j] - '0';
			}
		}
	
		fill(dp,dp+two[n],inf);
		dp[0] = 0;
		for(int i = 0; i < n ;i++) dp[two[i]] = hp[i]; 
		for(int i = 0; i < two[n]; i++)
		{
			for(int j = 0; j < n; j++) if(dp[i]!=inf)if(i&two[j])
			{
				for(int k = 0; k < n; k++) 
				{
					if(!(i&two[k]) && a[j][k])
					dp[i|two[k]] = min(dp[i|two[k]],dp[i]+(hp[k]+a[j][k]-1)/a[j][k]);
					dp[i|two[k]] = min(dp[i|two[k]],dp[i]+hp[k]);
				}
				
			}
		}
		printf("Case %d: %d\n",ca++,dp[two[n]-1]);
	}
	return 0;
}