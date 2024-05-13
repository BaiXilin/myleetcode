class Solution {
public:
    typedef std::pair<double, vector<int>> pt;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // construct a min heap to store distances of all points to the origin
        priority_queue<pt, vector<pt>, greater<pt>> minHeap;

        // calculate distances of points and store into the minHeap
        for(auto point : points)
            minHeap.push(make_pair(calculateDistance(point), point));

        // store the k closest points into the result vector
        vector<vector<int>> kClosestPts;

        for(int i = 0; i < k; i++) {
            kClosestPts.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return kClosestPts;
    }

    double calculateDistance(vector<int>& point) {
        return sqrt(pow(point[0]) + pow(point[1]));
    }
};
