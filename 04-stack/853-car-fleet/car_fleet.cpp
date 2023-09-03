#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef struct car {
        int position;
        int speed;

        // overloaded < operator so that cars can be sorted by std::sort
        bool operator < (const car& other) const {
            return position < other.position;
        }
    } car;

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<car> cars;
        for(auto i = 0; i < position.size(); i++) {
            car currCar = {position[i], speed[i]};
            cars.push_back(currCar);
        }

        sort(cars.begin(), cars.end());
        // a montonic decreasing stack
        stack<double> time_stack;

        for(int i = cars.size() - 1; i >= 0; i--) {
            double time = timeNeeded(cars[i], target);
            if(time_stack.empty()) {
                time_stack.push(time);
                continue;
            }
            if(time > time_stack.top())
                time_stack.push(time);
            // if less time is needed, they belong to the same fleet
        }

        return time_stack.size();
    }

    double timeNeeded(car& a, int target) {
        return (target - a.position) *1.0 / a.speed;
    }
};

int main() {
    Solution sol;
/*
    // case 1:
    int target = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    // expect: 3
*/
/*
    // case 2:
    int target = 10;
    vector<int> position = {8, 3, 7, 4, 6, 5};
    vector<int> speed = {4, 4, 4, 4, 4, 4};
    // expect: 6
*/
/*
    // case 3:
    int target = 10;
    vector<int> position = {0, 4, 2};
    vector<int> speed = {2, 1, 3};
    // expect: 1
*/
    // case 4
    int target = 31;
    vector<int> position = {5,26,18,25,29,21,22,12,19,6};
    vector<int> speed = {7,6,6,4,3,4,9,7,6,4};
    // expect: 6
    int result = sol.carFleet(target, position, speed);
    cout << "result = " << result << endl;
}
