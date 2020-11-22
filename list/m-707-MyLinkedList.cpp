class MyLinkedList {
private:
	ListNode * dummyHead;
    int size;
public:
    /** Initialize your data structure here. */

    void draw(){
        ListNode * cur = dummyHead;
        while(cur){
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "size : " << size << endl;
        
    }

    MyLinkedList() {
		dummyHead = new ListNode(0);
        size = 0;
        // draw();
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    // dummyhead -> 0 -> 1 -> 2 -> nullptr
    //              |                |           |
    int get(int index) {
        if(index < 0 || index >= size)
            return -1;
		ListNode* cur = dummyHead->next;
        while(index--)
            cur = cur->next;
        // draw();            
		return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    // dummyhead -> (val) ->0 -> 1 -> 2 -> nullptr
    void addAtHead(int val) {
		ListNode * newNode = new ListNode(val);
		newNode->next = dummyHead->next;
		dummyHead->next = newNode;
        ++ size;
        // draw();        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    // dummyhead -> 0 -> 1 -> 2 -> (val) -> nullptr
    // dummyhead -> (val) -> nullptr
    void addAtTail(int val) {
		ListNode* cur = dummyHead;
		ListNode* newNode = new ListNode(val);
        int size_l = size;
        while(size_l --)
            cur = cur->next;
        newNode->next = cur->next;
        cur->next = newNode;
        ++ size;
        // draw();
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    // dummyhead -> 0 -> 1 -> 2 -> nullptr
    // index = 0, val = 1
    // dummyhead -> (1) -> 0 -> 1 -> 2 -> nullptr
    void addAtIndex(int index, int val) {
		if(index > size)
            return;
        else if(index == size){
            addAtTail(val);
            return;
        }
        ListNode * cur = dummyHead;
        while(index--)
            cur = cur->next;
        ListNode * newNode = new ListNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        ++ size;
        // draw();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    // dummyhead -> 0 -> 1 -> 2 -> nullptr
    // index = 1
    // dummyhead -> 1 -> 2 -> nullptr
    void deleteAtIndex(int index) {
        if(index >= size)
            return;
        ListNode * cur = dummyHead;
        while(index--)
            cur = cur->next;
        ListNode * tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        -- size;
        // draw();
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
