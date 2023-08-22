#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string encoded;
        for(auto i : strs) {
            encoded += to_string(i.size());
            encoded += "#";
            encoded += i;
        }
        return encoded;
    }

    /*
     * @param str: A string
     * @return: decodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> decoded;
        int i = 0;
        while(i < str.size()) {
            // every while cycle reads in one word
            string word_length_str;
            int word_length_int;

            while(str[i] != '#') {
                word_length_str += str[i];
                i++;
            }
            word_length_int = stoi(word_length_str);
            // ignore separator #
            i++;

            // read in the next word according to the length
            decoded.push_back(str.substr(i, word_length_int));
            i += word_length_int;
        }
        return decoded;

    }
};

int main() {
    Solution sol;
    vector<string> input_strs = {"Leet", "Code", "Loves", "You"};
    string encoded_str = sol.encode(input_strs);
    vector<string> decoded_strs = sol.decode(encoded_str);

    cout << "encoded: " << encoded_str << endl;
    cout << "decoded: ";
    for(auto i : decoded_strs) {
        cout << i << " ";
    }
    cout << endl;

}
