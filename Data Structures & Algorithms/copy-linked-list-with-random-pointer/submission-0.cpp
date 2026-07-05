/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> old;
        old[nullptr] = nullptr;

        Node* current = head;
        while (current != nullptr) {
            if (old.find(current) == old.end()) {
                old[current] = new Node(0);
            }
            old[current]->val = current->val;
            if (old.find(current->next) == old.end()) {
                old[current->next] = new Node(0);
            }
            old[current]->next = old[current->next];
            if (old.find(current->random) == old.end()) {
                old[current->random] = new Node(0);
            }
            old[current]->random = old[current->random];
            current = current->next;
        }

        return old[head];
    }
};
