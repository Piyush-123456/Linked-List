class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->next != NULL && temp->val == temp->next->val) {
                ListNode* newNode = temp->next;
                temp->next = newNode->next;
                newNode->next = NULL;
                delete newNode;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
