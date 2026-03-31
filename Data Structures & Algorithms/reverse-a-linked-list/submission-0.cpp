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
    ListNode* reverseList(ListNode* head) {
        ListNode* cH = head;
        if (!head){
            return NULL;
        }
        if (!cH->next){
            return head;
        }
        ListNode* P = cH;
        cH = cH->next;

        while (cH->next){
            ListNode* np = cH->next;
            cH->next = P;
            P = cH;
            cH = np;
        }

        cH->next = P;
        head->next = 0;

        return cH;
    }
};
