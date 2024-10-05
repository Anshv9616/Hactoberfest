#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (const string& str : strs) {
            vector<int> count(26, 0);
            for (char c : str) {
                count[c - 'a']++;
            }

            // Create a unique key from the count array
            string key;
            for (int e : count) {
                key += to_string(e) + '#';
            }

            groups[key].push_back(str);
        }

        // Reserve space for performance
        vector<vector<string>> ans;
        ans.reserve(groups.size());
        
        for (auto& entry : groups) {
            ans.push_back(move(entry.second)); // Move to avoid copying
        }

        return ans;
    }
};
