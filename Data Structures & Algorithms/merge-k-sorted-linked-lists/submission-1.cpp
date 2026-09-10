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

 struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* head = new ListNode();
        ListNode* cur = head;

        for (auto& l : lists) {
            if (!l) continue;
            pq.push(l);
        }

        while (!pq.empty()) {
            if (pq.top()->next != nullptr) {
                pq.push(pq.top()->next);
            }
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();
        }
        return head->next;
    }
};
