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

int help(vector<int>& v, int low, int high)
{
	int point = v[low];
	while(low<high)
	{
		while (v[high] > point && high > low) high--;
		v[low] = v[high];
		while (point >=v[low] && low < high) low++;
		v[high] = v[low];
	}
	v[low] = point;
	return low;
}

void Sort(vector<int>& v, int low, int high)
{

	if (high > low)
	{
		int point = help(v, low, high);

		Sort(v,low, point - 1);
		Sort(v, point + 1, high);
	}
}

void QuickSort(vector<int>&v)
{
	int high = v.size()-1;
	int low = 0;
	Sort(v, low, high);

	  }
    
            
void print(vector<int>v)
{
	for (auto x : v)
		cout << x << "  ";
	}


int main()
{

	test64();
	vector<int>v = { 47,46,49,46,56,5,3,8,5,1,564,66};
	QuickSort(v);
	print(v);
	system("pause");
	return 0;
}