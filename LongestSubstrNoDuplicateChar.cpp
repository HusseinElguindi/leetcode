// Longest Substring Without Repeating Characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        
        unordered_map<char, int> visited;
        unordered_map<char, int>::iterator vend = visited.end();
        
        
        int left = 0;
        int slen = s.size();
        for (int right = 0; right < slen; right++) {
            unordered_map<char, int>::iterator find = visited.find(s[right]);
            if (find != vend) {
                left = max((find->second)+1, left);
            }
            
            result = max(result, right - left + 1);
            visited[s[right]] = right;
        }
        
        return result;
    }
};
