#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cmath>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
		//将长度n的绳子切成m段,使得各个m段之积达到最大
		//思路: 尽可能切成3的段,但是有特殊情况,4 = 2 + 2 , 4 = 1 + 3 . 如果最终一段是4,那么应当切成 2 和 2
		if(n == 2 || n == 3)	return n - 1;
		int count = n / 3;
		int rest  = n % 3;
		return (rest == 1) ? pow(3, count - 1) * 4 : (rest == 0) ? pow(3, count) : rest * pow(3, count);
	}	
};



int main(int argc, char ** argv){
	
		int n1 = 2;
		int n2 = 10;
		cout << Solution().cuttingRope(n1) << endl;
		cout << Solution().cuttingRope(n2) << endl;
		return 0;
}
