struct ListNode {
    int val;
    ListNode *next;
    ListNode(int num):val(num), next(NULL) {}
};

ListNode *findFirstCommonNode(ListNode *head_1, ListNode *head_2) {
    if (!head_1 || !head_2) return NULL;

    ListNode *res = NULL;
    int len_1 = 1, len_2 = 1;
    ListNode *node_1 = head_1, *node_2 = head_2;
    while (node_1->next) {
        len_1++;
        node_1 = node_1->next;
    }

    while (node_2->next) {
        len_2++;
        node_2 = node_2->next;
    }

    node_1 = head_1;
    node_2 = head_2;
    
    if (len_1 < len_2) {
        int tmp = len_2 - len_1;
        while (tmp-->0) node_2 = node_2->next;
    } else if (len_1 > len_2) {
        int tmp = len_1 - len_2;
        while (tmp-->0) node_1 = node_1->next;
    }

    while (node_1) {
        if (node_1 == node_2) {
            res = node_1;
            break;
        }

        node_1 = node_1->next;
        node_2 = node_2->next;
    }

    return res; // return node_1 is okay here
}
