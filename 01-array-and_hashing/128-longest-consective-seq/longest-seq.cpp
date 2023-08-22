#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // construct a map that indicates if a number has been explored
        unordered_map<int, bool> explored;
        for(auto i : nums) {
            explored[i] = false;
        }

        // for every number, explore their left and right side
        // for the longest sequence
        int longest_seq = 0;
        for(auto i : nums) {
            // if already explored, don't explore again
            if(explored[i])
                continue;
            // if not, it is explored now
            int seq_length = 0;
            explored[i] = true;
            seq_length++;
            // explore left and right
            exploreLeft(explored, i, seq_length);
            exploreRight(explored, i, seq_length);

            if(seq_length > longest_seq)
                longest_seq = seq_length;
        }
        return longest_seq;
    }

    void exploreLeft(unordered_map<int, bool> &explored, int current, int& seq_length) {
        int left_iter = current - 1;
        while(explored.find(left_iter) != explored.end()) {
            seq_length++;
            explored[left_iter] = true;
            left_iter--;
        }
    }

    void exploreRight(unordered_map<int, bool> &explored, int current, int& seq_length) {
        int right_iter = current + 1;
         while(explored.find(right_iter) != explored.end()) {
            seq_length++;
            explored[right_iter] = true;
            right_iter++;
         }
    }
};

int main() {
    vector<int> nums1 = {100,4,200,1,3,2}; // 4
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1}; // 9

    Solution sol;
    std::cout << "ans 1: " << sol.longestConsecutive(nums1) << std::endl;
    std::cout << "ans 2: " << sol.longestConsecutive(nums2) << std::endl;

    return 0;
}
