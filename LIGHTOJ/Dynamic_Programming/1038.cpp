#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
double dp[100010];
int main()
{
	int t,ca=1,n;
	scanf("%d",&t);
	dp[1]=0;
	for(int i=2;i<=100000;i++)
	{
		double sum=0;
		int cnt=0;
		for(int j=1;j<=sqrt(i*1.0);j++){
			if(i%j==0){
				sum+=dp[j];cnt++;
				if(j!=1 && j != i/j) sum+=dp[i/j],cnt++;
			}
		}
		cnt++;
		sum+=cnt;
		dp[i]=sum/(cnt-1);
	}
	while(t--)
	{
		scanf("%d",&n);

		printf("Case %d: %.20lf\n",ca++,dp[n]);
	}
	return 0;
}