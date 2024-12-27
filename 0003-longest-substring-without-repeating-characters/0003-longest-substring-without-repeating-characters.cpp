// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         map<pair<char,int>> unq;
//         int n = s.size();
//         int l=0,r=0,maxlen=0;

//         while(r<n){
//             if(unq.find(s[r]) == unq.end()){
//                 unq.insert({s[r],r});
//                 maxlen = max(maxlen, r-l+1);
//                 r++;
//             }else{
//                 unq.erase(s[l]);
//                 l = unq
//             }
//         }
//         return maxlen;
//     }
// };


#include <unordered_map>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            if (charMap.find(s[right]) != charMap.end() && charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1; 
            }
            charMap[s[right]] = right; 
            maxLength = max(maxLength, right - left + 1); 
        }

        return maxLength;
    }
};