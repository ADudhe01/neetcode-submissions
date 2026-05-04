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

 /*
    -> reverse nodes in k groups: 1st k nodes, then next k;
    -> store pointers to the nodes in a vector
    -> for every block of k nodes, reverse the order in that block
        -> leaving the elements with less that k nodes at the end alone
    -> iterate through the vector and do nodes[i]->next = nodes[i + 1];
 */

class Solution {
public:
    // groupPrev -> node before the group
    // groupNext -> node after the group
    // 
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(-1);
        ListNode *groupPrev = &dummy;
        groupPrev->next = head;

        while (true) {
            // get kth node
            ListNode *kth = groupPrev;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }

            if (!kth) break;

            ListNode* groupNext = kth->next;

            // reverse group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // reconnect group
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;

        }


        return dummy.next;
    }
};
