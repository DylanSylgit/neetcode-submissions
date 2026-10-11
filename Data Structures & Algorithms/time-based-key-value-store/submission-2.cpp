#include <iostream>
using namespace std;
#include <unordered_map>
#include <string>
#include <vector>


class TimeMap {
public:

    unordered_map<string,vector<pair<int,string>>> m;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        const auto& h = m[key];
        int l = 0;
        int r = h.size()-1;
        string ans = "";


        while (l<=r){
            int m = (l+r) / 2;
            if (h[m].first <= timestamp) {
                ans = h[m].second;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;

        
    }
};
