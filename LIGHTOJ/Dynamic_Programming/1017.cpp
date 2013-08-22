#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int mod = 1000000007;
int N , W , K;
int x[110] , y[110];
int dp[110][110];
int jmp[110];
inline void Max(int &a,int b)
{
	if(b > a) a = b;
}
void pre()
{
	sort(y+1,y+N+1);
	for(int i = 1; i <= N; i++)
	{
		int j;
		for(j = i+1; j <= N; j++)
		{
			if(y[j]-y[i] > W)  break;
		}
		j--;
		jmp[i] = j;
	}
}
int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&N,&W,&K);
		for(int i = 1; i <= N; i++) scanf("%d%d",&x[i],&y[i]);
		pre();
		fill(dp[0],dp[N+1],-1);
		for(int i = 1; i <= N; i++) dp[i][0] = 0;
		dp[0][0] = 0;
		for(int i = 1; i <= N; i++)
		{
			for(int j = 0; j <= i && j <= K; j++)  if(~dp[i-1][j])
			{
				int to = jmp[i];
				Max(dp[to][j+1],dp[i-1][j] + to - i+ 1);
				Max(dp[i][j],dp[i-1][j]);
			}
		}
		int ans = 0;
		for(int i = 1; i <= N; i++)
		{
			for(int j = 0; j <= K; j++)
			{
				Max(ans,dp[i][j]);
			}
		}
		printf("Case %d: %d\n",ca++,ans);
	}
	return 0;
}