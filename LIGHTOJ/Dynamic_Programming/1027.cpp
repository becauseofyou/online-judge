#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pt[110],n;
double f[110];
int gcd(int a,int b)
{
	return !b ? a : gcd(b,a%b);
}
int main()
{
	int t,ca=1;
	scanf("%d",&t);
	while(t--)
	{
	    int n;
		scanf("%d",&n);
		int sum = 0 , cnt = 0;
		for(int i = 0 ,x;i < n; i++)
		{
			scanf("%d",&x);
			if(x > 0) sum += x,cnt++;
			else sum+= -x;
		}
		printf("Case %d: ",ca++);
		if(cnt == 0)
		{
			printf("inf\n");
		}
		else 
		{
			int g = gcd(sum,cnt);
			sum/=g; cnt/=g;
			printf("%d/%d\n",sum,cnt);
		}
		
	}
	return 0;
}