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
    bool _legalArea(int i, int j, int k){
        //true : i 和 j 的各个位之后小于k
        int sum = 0;
        while(i){
            sum += i % 10;
            i /= 10;
        }
        while(j){
            sum += j % 10;
            j /= 10;
        }
        return (sum <= k);
    }

    void dfs(int i, int j, vector<vector<int>> & map){
        if(i<0 || i>=map.size() || j<0 || j>= map[0].size() || map[i][j] == 0)
            return;
        count++;
        map[i][j] = 0;
        int dx[4]{0,0,-1,1};
        int dy[4]{-1,1,0,0};
        for(int k = 0 ; k < 4; ++ k){
            dfs(i+dx[k],j+dy[k],map);
        }
        return;
    }

public:
    int count = 0;
    int movingCount(int m, int n, int k) {
		// 先绘制所有符合要求的点的二维数组, 然后通过 DFS 来计算[0,0]相连岛屿的大小
        vector<vector<int>> map(m, vector<int>(n,0));
        for(int i = 0 ; i < m ; ++ i){
            for(int j = 0 ; j < n ; ++ j){
                if(_legalArea(i,j,k) == true){
                    map[i][j] = 1;
                }
            }
        }
        dfs(0,0,map);
        return count;
    }
};


int main(int argc, char ** argv){
	

		return 0;
}
