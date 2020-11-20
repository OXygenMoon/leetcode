/*
 * Title: 01背包问题
 * Date : 2020.11.20
 * Name : Lao Zhenyu
 */

/* 
 * 题目
 * 有 N 件物品和一个容量为 V 的背包.
 * 第 i 件物品的费用是 w[i], 价值是 v[i].
 * 求将哪些物品装入背包使价值总和最大
 */

/* 
 * 思路
 * 每一个物品仅有一件,有两种选择 : 放 or 不放
 * 状态转移方程 : f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + v[i])
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution{
	public:
		int _01_knapsack(vector<int> & w, vector<int> & v){
			int N = w.size();
			int V = v.size();
			vector<vector<int>> dp(N+1, vector<int>(V+1, 0));
			for(int i = 1; i <= N; ++ i){
				for(int j = 1; j <= V; ++ j){
					if(j - w[i-1] < 0){
						dp[i][j] = dp[i-1][j];
					} else {
						dp[i][j] = max(dp[i-1][j], v[i-1] + dp[i-1][j - w[i - 1]]);
					}
				}
			}
			return dp[N][V];
		}
};

int main(int argc, char const* argv[])
{
	vector<int> weight{2,1,3};
	vector<int> values{4,2,3};
	cout << "max vals : " << Solution()._01_knapsack(weight, values);
	return 0;
}
