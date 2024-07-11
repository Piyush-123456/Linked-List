class Solution {
  public:
    void linkdelete(struct Node **head, int n, int m) {
        if (!head) return;
        
        Node* current = head;
        
        for (int i = 1; i < m && current != nullptr; i++) {
            current = current->next;
        }
        
        if (!current) return;

        Node* temp = current->next;
        for (int i = 0; i < n && temp != nullptr; i++) {
            Node* nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete;
        }
        
        current->next = temp;

        linkdelete(temp, m, n);
    }
};
