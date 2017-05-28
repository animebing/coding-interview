struct ListNode {
    int val;
    ListNode *next;
    ListNode(int num):val(num), next(NULL) {}
};

ListNode *entryNodeOfLoop(ListNode head) {
    
    if (!head || !head->next) return NULL;
    // find a node in the cycle if there is a cycle in the list
    ListNode *fast = head, *slow = head;
    bool flag = false;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            flag = true;
            break;
        }
    }
    // get the length of the circle
    if (!flag) return NULL;
    int len = 1;
    ListNode *tmp_node = fast;
    while (tmp_node->next != fast) {
        len++;
        tmp_node = tmp_node->next;
    }
    // for one node, move len steps first, then move together with another node starting from head, 
    // when these two nodes meet, the meeting node is what we want
    tmp_node = head;
    while (len-->0) tmp_node = tmp_node->next;
    ListNode *tmp_head = head;
    while (tmp_head != tmp_node) {
        tmp_head = tmp_head->next;
        tmp_node = tmp_node->next;
    }
    
    return tmp_head;

}
