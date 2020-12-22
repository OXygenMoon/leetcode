class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
		// 爬楼梯问题
		// 楼梯上有不同的价值
		// 每一次可以爬一级或者两级
		// 使用DP来记录到达某一个位置最小的价值
        int dp_0,dp_1,dp_2;
        dp_0 = dp_1 = 0;
        for(int i = 2 ; i <= cost.size() ; ++ i){
            dp_2 = min(dp_0 + cost[i-2], dp_1 + cost[i-1]);
            dp_0 = dp_1;
            dp_1 = dp_2;
        }
        return dp_2;
    }
};
