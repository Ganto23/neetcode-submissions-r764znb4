/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        Node* saved_head = new Node(node->val);
        Node* head = saved_head;
        unordered_map<Node*, Node*> seen;
        seen[node] = head;

        queue<Node*> q;
        queue<Node*> q_n;
        q.push(node);
        q_n.push(head);

        while (!q.empty()) {
            Node* cur = q.front();
            Node* cur_new = q_n.front();
            q.pop();
            q_n.pop();

            for (Node* n : cur->neighbors) {
                if (seen.contains(n)) {
                    cur_new->neighbors.push_back(seen[n]);
                    continue;
                }
                Node* new_node = new Node(n->val);
                cur_new->neighbors.push_back(new_node);
                seen[n] = new_node;
                q.push(n);
                q_n.push(new_node);
                
            }
        }
        return head;

    }
};
