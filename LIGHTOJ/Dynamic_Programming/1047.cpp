#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf = ~0u>>2;
int dp[25][3];
int main()
{
	int t,ca=1,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fill(dp[0],dp[n+1],inf);
		dp[0][0] = dp[0][1] = dp[0][2] = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0,k; j < 3; j++)
			{
				scanf("%d",&k);
				for(int x = 0; x < 3; x++) if(x!=j)
				{
					dp[i][j] = min(dp[i][j],dp[i-1][x]+k);
				}
			}
		}
		printf("Case %d: %d\n",ca++,*min_element(dp[n],dp[n]+3));
	}
	return 0;
}