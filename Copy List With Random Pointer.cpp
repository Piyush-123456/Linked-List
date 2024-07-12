class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        // Step->1 Copy Linked List
        Node* it = head;
        while (it) {
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        // Step->2 Assign the Random Link
        it = head;
        while (it) {
            Node* clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;
        }
        // Step->3 Remove the Old Node
        it = head;
        Node* clonedHead=it->next;
        while (it) {
            Node* clonedNode = it->next;
            it->next = it->next->next;
            if (clonedNode->next) {
                clonedNode->next = clonedNode->next->next;
            }
            it = it->next;
        }
        return clonedHead;
    }
};
