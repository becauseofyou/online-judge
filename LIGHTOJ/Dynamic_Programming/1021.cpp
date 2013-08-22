#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 100010;
const int mod = 1000000007;
long long dp[1<<16][20];
int a[20],two[20];
char s[25];
int Log[100000];
int main()
{
	two[0] = 1; Log[1] = 0;
	for(int i = 1; i <= 16; i++) Log[1<<i] = i,two[i] = two[i-1] * 2;
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		int b , K;
		scanf("%d%d",&b,&K);
		scanf("%s",s);
		int n = 0;
		for(int i = 0;s[i];i++)
		{
			n++;
			if(s[i]>='A'&&s[i]<='Z') a[i] = 10 + s[i]-'A';
			else a[i] = s[i] - '0';
		}
		memset(dp,0,sizeof(dp));
		dp[0][0] =  1;
		for(int i = 0; i < (two[n]); i++)
		{
			for(int m = 0; m < K; m++) if(dp[i][m]) {
				//下面的只是一些小技巧，看不懂找我。。。
				for(int j = ~i&(two[n]-1);j>0; j-=j&-j)
				{
					int k = Log[j&-j];
					//printf("j=%d k=%d\n",j,k);
					dp[i|two[k]][(m*b+a[k])%K] += dp[i][m];
				}
			}
		}
		printf("Case %d: %lld\n",ca++,dp[two[n]-1][0]);
	}
	return 0;
}