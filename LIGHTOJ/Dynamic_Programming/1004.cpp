#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[110][110];
int num[110][110];
int main()
{
	int t,ca=1,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(num,0,sizeof(num));memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				scanf("%d",&num[i][j]);
				dp[i][j]=max(dp[i-1][j]+num[i][j],dp[i-1][j-1]+num[i][j]);
			}
		}
		for(int i=n+1;i<2*n;i++)
		{
			for(int j=1;j<=2*n-i;j++)
			{
				scanf("%d",&num[i][j]);
				dp[i][j]=max(dp[i-1][j+1]+num[i][j],dp[i-1][j]+num[i][j]);
			}
		}
	    printf("Case %d: %d\n",ca++,dp[2*n-1][1]);
	}
}