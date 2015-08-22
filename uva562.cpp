#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int a[105];
int dp[105][50005];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int num = 0,sum = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		num = sum / 2; 
		memset(dp,0,sizeof(dp));
		for(int i = 0; i <= n; i++)
		{
			dp[i][0] = 1;
		}
		for(int i = 1 ; i <= n;i++)
		{
		
			for(int j = 1; j <= num; j++)
			{
				if(j >= a[i])
				{
					
					dp[i][j] = dp[i-1][j] | dp[i-1][j-a[i]];
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
				
			}
		}
		for(int i = num; i >= 0; i --)
		{
			if(dp[n][i])
			{
				printf("%d\n",sum - 2 * i);
				break;
			}
		}

	}
	return 0;
}
