class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

		// 一组信息,存储的是{身高,在前面有多少个比自己身高相同或者高的同学}
		// 排出合理的方案
		// 贪心
		// 先对身高进行排序,再对前面有多少人进行插入
		// 比如说,{7,0},{7,1},{5,0}...
		// {7,0} : 插入到第0个位置
		// {7,1} : 插入到第1个位置,{7,0}不受影响
		// {5,0} : 插入到第0个位置,但是后面两位7身高的大哥并不会受到影响

        sort(people.begin(), people.end(),[](vector<int> &p1, vector<int> &p2)->bool{
            return (p1[0] > p2[0]) || (p1[0] == p2[0] && p1[1] < p2[1]);
        });
        // for(auto v : people)
            // cout << v[0] << " " << v[1] << endl;
        list<vector<int>> q;
        for(int i = 0 ; i < people.size() ; ++ i){
            int position = people[i][1];
            list<vector<int>>::iterator it = q.begin();
            while(position--)
                it++;
            q.insert(it, people[i]);
        }
        return vector<vector<int>>(q.begin(), q.end());
    }
};
