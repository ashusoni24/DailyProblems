There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
Given the array answers, return the minimum number of rabbits that could be in the forest.

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for (int x : answers) {
            ++cnt[x];
        }
        int ans = 0;
        for (auto& [x, v] : cnt) {
            int group = x + 1;
            ans += (v + group - 1) / group * group;
        }
        return ans;
    }
};
