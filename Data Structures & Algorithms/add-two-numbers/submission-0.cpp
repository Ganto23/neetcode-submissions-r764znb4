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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        int carry = 0;

        while (l1 && l2) {
            ListNode* current = new ListNode();
            int raw_sum = l1->val + l2->val + carry;
            int new_val = raw_sum % 10;
            carry = (raw_sum - new_val) / 10;

            current->val = new_val;
            cur->next = current;
            cur = cur->next; 

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            ListNode* current = new ListNode();
            int raw_sum = l1->val + carry;
            int new_val = raw_sum % 10;
            carry = (raw_sum - new_val) / 10;

            current->val = new_val;
            cur->next = current;
            cur = cur->next; 

            l1 = l1->next;
        }

        while (l2) {
            ListNode* current = new ListNode();
            int raw_sum = l2->val + carry;
            int new_val = raw_sum % 10;
            carry = (raw_sum - new_val) / 10;

            current->val = new_val;
            cur->next = current;
            cur = cur->next; 

            l2 = l2->next;
        }

        while (carry > 0) {
            ListNode* current = new ListNode();
            int raw_sum = carry;
            int new_val = raw_sum % 10;
            carry = (raw_sum - new_val) / 10;

            current->val = new_val;
            cur->next = current;
            cur = cur->next;
        }

        return head->next;
    }
};
