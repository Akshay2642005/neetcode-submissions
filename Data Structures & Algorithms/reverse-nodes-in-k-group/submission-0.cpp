class Solution {
private:
    ListNode* reverseList(ListNode* head, ListNode* end) {
        ListNode* prev = end;
        ListNode* curr = head;

        while (curr != end) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            // Find kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth; ++i)
                kth = kth->next;

            // Less than k nodes remain
            if (!kth)
                break;

            ListNode* groupNext = kth->next;
            ListNode* groupHead = groupPrev->next;

            // Reverse [groupHead, kth]
            ListNode* prev = groupNext;
            ListNode* curr = groupHead;

            while (curr != groupNext) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Reconnect
            groupPrev->next = kth;
            groupPrev = groupHead;
        }

        return dummy.next;
    }
};