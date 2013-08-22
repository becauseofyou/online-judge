#include<set>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 100010;
const int mod = 1000000007;
long long fac[31];
int c[31][31];
int main()
{
	fac[0] = 1;
	for(int i = 1; i <= 30; i++)
	{
		fac[i] =fac[i-1]*i;
	}
	c[0][0] = 1;
	for(int i = 1; i <= 30; i++)
	{
		c[i][0]  = c[i][i] = 1;
		for(int j = 1; j <= 30; j++)
		{
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	int n , k;
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		printf("Case %d: ",ca++);
		if(k>n) 
		{
			printf("0\n");
		}
		else 
		{
			long long a = 1;
			for(int i = n; i >= n-k+1; i--)
			{
				a = a * i;
			}
			printf("%lld\n",c[n][k]*a);
		}
	}
	return 0;
}