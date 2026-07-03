/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        ListNode* new_head = head;
        if (head->next) {
            new_head = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;
        return new_head;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        // divide the list into two halves
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second list
        ListNode* second = slow->next;
        slow->next = nullptr;
        second = reverseList(second);

        ListNode* first = head;
        while (second != nullptr) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
