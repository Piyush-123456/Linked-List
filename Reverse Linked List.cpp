class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* newnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newnode;
        }
        head = prev;
        return head;
    }
};
