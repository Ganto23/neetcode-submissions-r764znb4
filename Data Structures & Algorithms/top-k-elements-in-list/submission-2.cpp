class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Build the frequency map completely. This is the robust approach.
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        // Use a pair of {frequency, number}
        using pii = std::pair<int, int>;
        
        // A min-heap that will be ordered by frequency (the first element of the pair)
        priority_queue<pii, vector<pii>, greater<pii>> min_heap;

        // Step 2: Iterate through the completed map to manage the heap.
        for (auto const& [number, frequency] : freq_map) {
            if (min_heap.size() < k) {
                // Push {frequency, number}
                min_heap.push({frequency, number});
            } else if (frequency > min_heap.top().first) { // Compare frequencies
                min_heap.pop();
                // Push {frequency, number}
                min_heap.push({frequency, number});
            }
        }

        // Step 3: Extract the results from the heap.
        vector<int> result;
        while (!min_heap.empty()) {
            // THE FIX: Push the .second element (the number), not the .first
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        return result;
    }
};