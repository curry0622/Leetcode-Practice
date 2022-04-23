// class ListNode {
// private:
//     int val;
//     ListNode* next;
// public:
//     ListNode(int n):val(n),next(0){};
// friend class MyLinkedList;
// };

class MyLinkedList {
private:
    int length;
    ListNode* head;
public:
    MyLinkedList():length(0),head(0){};

    int get(int index) {
        if(index >= length)
            return -1;
        ListNode* curr = head;
        for(int i = 0; i < index; i++) {
            curr = curr -> next;
        }
        return curr -> val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode -> next = head;
        head = newNode;
        length += 1;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* curr = head;
        if(length == 0) {
            head = newNode;
            length += 1;
            return;
        }
        while(curr -> next) {
            curr = curr -> next;
        }
        curr -> next = newNode;
        length += 1;
    }

    void addAtIndex(int index, int val) {
        if(index > length)
            return;
        ListNode* newNode = new ListNode(val);
        ListNode* curr = head;
        if(index == 0) {
            newNode -> next = head;
            head = newNode;
            length += 1;
            return;
        }
        for(int i = 0; i < index - 1; i++) {
            curr = curr -> next;
        }
        newNode -> next = curr -> next;
        curr -> next = newNode;
        length += 1;
    }

    void delAtHead() {
        if(length == 0)
            return;
        head = head -> next;
        length -= 1;
    }

    void deleteAtIndex(int index) {
        if(index >= length)
            return;
        if(index == 0) {
            delAtHead();
            return;
        }
        ListNode* curr = head;
        for(int i = 0; i < index - 1; i++) {
            curr = curr -> next;
        }
        if(curr -> next)
            curr -> next = curr -> next -> next;
        else
            curr -> next = NULL;
        length -= 1;
    }

    void printList() {
        ListNode* curr = head;
        while(curr) {
            cout << curr -> val << " ";
            curr = curr -> next;
        }
        cout << endl;
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