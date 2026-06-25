#include <iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>

void test64()
{
	vector<vector<int>>v = { {1,3,1},{1,5,1},{4,2,1} };
	for (auto i : v) {
		for (auto x : i)
		{
			cout << x << " ";
		}
		cout << endl;
	}
	int gre = v.size();
	int re = v[0].size();
	vector<vector<int>>dp(gre, vector<int>(re));
	dp[0][0] = v[0][0];
	for (int i = 1;i < gre;i++)
	{
		dp[i][0] = v[i][0]+dp[i-1][0];

	}
	for (int i = 1;i < re;i++)
	{
		dp[0][i] = v[0][i]+dp[0][i-1];

	}
	for (int i = 1;i < gre;i++)
	{
		for (int j=1;j < re;j++)
		{
			int a = dp[i - 1][j] + v[i][j];
			int b = dp[i][j - 1] + v[i][j];
			int m = min(a, b);
			dp[i][j] = m;
		}
	}
	cout << dp[re - 1][gre - 1] << endl;
}

      
    
            
	


int main()
{

	test64();

	system("pause");
	return 0;
}