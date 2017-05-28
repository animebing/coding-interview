struct ListNode {
    int val;
    ListNode *next;
    ListNode(int num):val(num), next(NULL) {}
};

void deleteDuplication(ListNode *head) {
    if (!head) return;

    ListNode *p_cur = head, p_pre = NULL, p_next = NULL;
    while (p_cur) {
        if (!p_cur->next) return;
        bool is_delete = false;
        if (p_cur->val == p_cur->next->val) is_delete = true;

        if (!is_delete) {
            p_pre = p_cur;
            p_cur = p_cur->next;
        } else {
            int val = p_cur->val;
            ListNode *to_be_deleted = p_cur;
            while (to_be_deleted && to_be_deleted->val == val) {
                p_next = to_be_deleted->next;
                delete to_be_deleted;
                to_be_deleted = p_next;
            }
            if (!p_pre) head = p_next;
            else p_pre->next = p_next;

            p_cur = p_next;
        }
    }
}
