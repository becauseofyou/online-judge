#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 100010;
const int mod = 1000000007;
long long dp[65][35][35];
char s1[110],s2[110];
int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",s1+1,s2+1);
		int n = strlen(s1+1);
		int m = strlen(s2+1);
		s1[n+1] = '@'; s2[m+1]='@';
		for(int i = 0; i <= m+n; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				for(int k = 0; k <= m; k++)
				{
					dp[i][j][k]  = 0;
				}
			}
		}
		dp[0][0][0] = 1;
		for(int i = 0; i <= m+n; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				for(int k = 0; k <= m; k++) if(dp[i][j][k])
				{
					if(s1[j+1]==s2[k+1])
					{
						dp[i+1][j+1][k+1] += dp[i][j][k];
					}
					if(s1[j+1]!=s2[k+1]) 
					{
						dp[i+1][j+1][k] += dp[i][j][k];
						dp[i+1][j][k+1] += dp[i][j][k];
					}
				}
			}
		}
		int ans_len = -1;
		for(int i = 1; i <= m+n; i++)
		{
			if(dp[i][n][m])
			{
				ans_len = i;
				break;
			}
		}
		printf("Case %d: %d %lld\n",ca++,ans_len,dp[ans_len][n][m]);
	}
	return 0;
}