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
public:
    ListNode* insertionSortList(ListNode* head) {
        
		//对一个以head为头节点的链表进行插入排序
		//
        typedef ListNode* list_ptr;
        if(head == nullptr)
			return nullptr;
		//prehead - 前置节点保证在头节点之前插入和其他节点的操作的一致性
        list_ptr prehead = new ListNode(0);
        prehead->next = head;
		//lastsorted - 维护已经有序的末节点,初始是head
        list_ptr lastsorted = head;
		//cur - 遍历的指针
        list_ptr cur = head->next;
        while(cur != nullptr){
            //迭代部分,取出当前节点插入到前面有序的部分中
			//如果有序部分的末节点值小于当前遍历节点,说明cur插入就是当前位置
			//否则需要从头开始找到需要插入的位置
            if(lastsorted->val <= cur->val){
                lastsorted = lastsorted->next;
            } else {
                list_ptr prev = prehead;
                while(prev->next->val <= cur->val)
                    prev = prev->next;
                lastsorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = lastsorted->next;
        }
        return prehead->next;
    }
};



int main(int argc, char ** argv){
	

		return 0;
}



