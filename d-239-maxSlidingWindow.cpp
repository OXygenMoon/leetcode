#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;

class Solution {
	private:
		struct monotonous_queue{
			private:
				deque<int> data;
			public:
				void push(int val){
					while(!data.empty() && data.back() < val){
						data.pop_back();
					}
					data.push_back(val);
				}

				void pop(int target){
					if(!data.empty() && data.front() == target){
						data.pop_front();
					}
				}
				
				int max(){
					return data.front();
				}

		};
	public:
		vector<int> maxSlidingWindow(vector<int> & nums, int k){
				// 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
				// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
				// 返回滑动窗口中的最大值。
				monotonous_queue mq;
				vector<int> res;
				for(int i = 0 ; i < nums.size() ; ++ i){
					if(i<k-1)                               //在k-1的时候,直接插入,窗口不移动		
						mq.push(nums[i]);
					else{									//滑动窗口开始移动,插入后直接返回最大值,然后尝试弹出即将离开窗口的值
						mq.push(nums[i]);
						res.push_back(mq.max());
						mq.pop(nums[i-k+1]);
					}
				}
		}
};



int main(int argc, char ** argv){
	
	return 0;
}
