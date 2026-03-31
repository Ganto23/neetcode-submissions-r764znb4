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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head){
            return nullptr;
        } else if (!head->next){
            return nullptr;
        }

        ListNode* forward = head;
        ListNode* back = head;

        for (int i = 0; i < n; ++i){
            forward = forward->next;
        }

        if (forward == nullptr){
            return head->next;
        }

        while (forward->next != nullptr){
            forward = forward->next;
            back = back->next;
        }
        
        back->next = back->next->next;
        return head;
    }
};
