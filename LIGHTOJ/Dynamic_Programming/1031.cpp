#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int inf = ~0u>>2;
int sum[110];
int dp[110][110];
inline int max(int a,int b){
    return a>b?a:b;
}
int main()
{
    int t,n,ca=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum[0]=0;
		memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sum[i]);
            dp[i][i]=sum[i];
            sum[i]+=sum[i-1];
        }
        for(int len=1;len<n;len++)
        {
            for(int i=1;i+len<=n;i++)
            {
                dp[i][i+len]=sum[i+len]-sum[i-1];
                for(int j=i;j<i+len;j++)
                {
                       dp[i][i+len]=max(dp[i][i+len],sum[j]-sum[i-1]-dp[j+1][i+len]);
                       dp[i][i+len]=max(dp[i][i+len],sum[i+len]-sum[j]-dp[i][j]);
				}
            }
        }
        printf("Case %d: %d\n",ca++,dp[1][n]);
    }
    return 0;
}