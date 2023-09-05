#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // possible range of the the eating speed?
        // max = size of largest pile
        // min = average speed, cannot finish is slower than average
        int left, right;
        findMax(piles, right);
        left = calculateAverageEatSpeed(piles, h);
        int middle;

        while(left <= right) {
            middle = ceil((left+right) * 1.0 / 2);
            int hours = hoursNeeded(piles, middle);
            if(hours == h) {
                // is able to finish with speed = middle
                // there could be extra to spare
                return calculateMinSpeed(piles, middle);
            }
            if(hours > h) // ate too slow
                left = middle + 1;
            else // ate too fast
                right = middle - 1;
        }
        return calculateMinSpeed(piles, left);
    }

    void findMax(vector<int>& piles, int& max) {
        max = piles.front();
        for(auto it : piles) {
            if(it > max)
                max = it;
        }
        return;
    }

    int calculateAverageEatSpeed(vector<int>& piles, int h) {
        unsigned int total = 0;
        for(auto it : piles)
            total += it;
        return ceil(total * 1.0 / h);
    }

    int hoursNeeded(vector<int>& piles, int speed) {
        int hours = 0;
        for(auto it : piles) {
            hours += ceil(it*1.0 / speed);
        }
        return hours;
    }

    int calculateMinSpeed(vector<int>& piles, int speed) {
        int minSpeed = 0;
        for(auto it : piles) {
            int oldNumHours = ceil(it * 1.0 / speed);
            if(ceil(it * 1.0 / oldNumHours) > minSpeed)
                minSpeed = ceil(it * 1.0 / oldNumHours);
        }
        return minSpeed;
    }
};

int main() {
    Solution sol;

    //vector<int> piles = {3,6,7,11};
    //int h = 8; // expects 4

    //vector<int> piles = {30,11,23,4,20};
    //int h = 5; // expects 30

    //vector<int> piles = {30,11,23,4,20};
    //int h = 6; // expects 23

    //vector<int> piles = {2, 2};
    //int h = 2; // expects 2
    
    //vector<int> piles = {312884470};
    //int h = 312884469; // expects 2

    //vector<int> piles = {312884470};
    //int h = 968709470;

    vector<int> piles = {1,1,1,999999999};
    int h = 10; // expects: 142857143
    
    int result = sol.minEatingSpeed(piles, h);
    cout << "result = " << result << endl;
}
