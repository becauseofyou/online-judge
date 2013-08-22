#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long lld;
lld  dp[35][2];
void init()
{
	memset(dp,0,sizeof(dp));
	dp[2][1]=1;
	for(int i=3;i<=32;i++)
	{
		dp[i][1]=dp[i-1][0]+dp[i-1][1]+(1<<(i-2));
		dp[i][0]=dp[i-1][1]+dp[i-1][0];
	}
}
lld calc(int num)
{
	if(num<=0) return 0;
	lld ans=0;
	bool f=false;
	int cnt=0;
	int id;
	for(int i=31;i>=0;i--)
	{
		if(num&(1<<i))
		{
			if(f)ans+=dp[i+1][0];
			if(f==false)  id=i,f=true;
		    ans+=(lld)cnt*(1<<i);
		}
		if((i+1)<=31 &&(num&(1<<(i+1))) && (num&(1<<i))) cnt++; 
	}
	for(int i=0;i<=id;i++) ans+=dp[i][1];
	ans+=cnt;
	return ans;
}
int  main()
{
	init();
	int t,ca=1,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("Case %d: %lld\n",ca++,calc(n));
	}
	return 0;
}
