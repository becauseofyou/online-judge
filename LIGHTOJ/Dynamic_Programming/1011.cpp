#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 100010;
const int mod = 1000000007;
int dp[17][1<<17];
int a[17][17];
int two[17];
int main()
{
	two[0] = 1; 
	for(int i = 1; i <= 16; i++) two[i]=two[i-1]*2;
	int n;
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < two[n]; j++) dp[i][j] = -1;//一开始所有的状态都是非法的
		}
		for(int i = 0; i < n; i++) dp[0][1<<i] = a[0][i];
		for(int i = 1; i < n; i++)
		{
            //枚举前i-1行所有已经存在的状态，去更新前i行的状态
			for(int j = 0; j < (1<<n); j++) if(dp[i-1][j]!=-1)//前i-1行j的状态存在的前提下才能转移
			{
                 for(int k = 0; k < n; k++) if(!(j&(1<<k))) // k 不在j集合中
				 {
					 dp[i] [j | ( 1<<k ) ] = max(dp[i][j | ( 1<<k ) ],dp[i-1][j] + a[i][k]);
				 }
			}
		}
		printf("Case %d: ",ca++);
		printf("%d\n",dp[n-1][(1<<n)-1]);
	}
	return 0;
}
