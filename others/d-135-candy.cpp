class Solution {
public:
    int candy(vector<int>& ratings) {
		// 分发糖果
		// 思路 : 贪心算法
		// 从左往右先考虑好每个人该拿多少糖果
		// 再从右往左考虑,此时的区别在于,索引i处的糖果有左边和右边的影响
		// 关键点在于 max(candies[i], candies[i+1] + 1);
        int size = ratings.size();
        if(size == 1)   return 1;
        vector<int> candies(size, 1);
        for(int i = 1 ; i < size ; ++ i){
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i - 1] + 1;
        }
        for(int i = size - 2; i >= 0 ; -- i){
            if(ratings[i] > ratings[i+1])
                candies[i] = max(candies[i], candies[i+1] + 1);
        }
        int res = 0;
        for(int val : candies)
            res += val;
        return res;
    }
};
