#include <unordered_map>
#include <utility>
#include <string>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class TimeMap {
public:
    // eg. "foo" -> <1, "bar">
    unordered_map<string, vector<string>> MapKV;
    unordered_map<string, vector<int>> MapTimestamp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        MapKV[key].push_back(value);
        MapTimestamp[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp) {
        if(MapKV.find(key) == MapKV.end())
            return "";

        int leftPtr = 0, rightPtr = MapKV[key].size() - 1;
        int middlePtr;
        while(leftPtr <= rightPtr) {
            middlePtr = (leftPtr + rightPtr) / 2;

            if(leftPtr == rightPtr || leftPtr == rightPtr - 1) {
                if(timestamp < MapTimestamp[key][leftPtr])
                    return "";
                else if(timestamp < MapTimestamp[key][rightPtr])
                    middlePtr = leftPtr;
                else
                    middlePtr = rightPtr;
                break;
            }

            if(MapTimestamp[key][middlePtr] < timestamp)
                leftPtr = middlePtr;
            else
                rightPtr = middlePtr;
        }
        return MapKV[key][middlePtr];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

 int main() {
    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar", 1);
    cout << obj->get("foo", 1) << endl;
    cout << obj->get("foo", 7) << endl;
    
    obj->set("foo", "bar2", 4);

    cout << obj->get("foo", 3) << endl;
    cout << obj->get("foo", 4) << endl;
    cout << obj->get("foo", 5) << endl;

    delete(obj);
 }
