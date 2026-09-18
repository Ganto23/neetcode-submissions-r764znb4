class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }
    }

    int find(int val) {
        if (parent[val] == val) return val;
        return parent[val] = find(parent[val]);
    }

    bool merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr) return false;
        
        if (size[xr] >= size[yr]) {
            parent[yr] = xr;
            size[xr] += size[yr];
        } else {
            parent[xr] = yr;
            size[yr] += size[xr];
        }
        return true;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind nodes(edges.size());
        for (auto& edge : edges) {
            if (!nodes.merge(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};
