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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto cur1 = list1; auto cur2 = list2;
        ListNode* head = nullptr;
        ListNode* saved_head = nullptr;

        while (cur1 && cur2) {
            if (!head) {
                if (cur1->val < cur2->val) {
                    head = cur1; cur1 = cur1->next;
                } else {
                    head = cur2; cur2 = cur2->next;
                } 
                saved_head = head;
                continue;
            }

            if (cur1->val < cur2->val) {
                head->next = cur1; cur1 = cur1->next;
            } else {
                head->next = cur2; cur2 = cur2->next;
            }
            head = head->next;
        }

        while (cur1) {
            if (!head) {
                head = cur1;
                cur1 = cur1->next;
                saved_head = head;
                continue;
            }
            head->next = cur1; cur1 = cur1->next;
            head = head->next;
        }

        while (cur2) {
            if (!head) {
                head = cur2;
                cur2 = cur2->next;
                saved_head = head;
                continue;
            }
            head->next = cur2; cur2 = cur2->next;
            head = head->next;
        }
        return saved_head;
    }
};
