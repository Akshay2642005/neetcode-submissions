class TimeMap {
private:
    unordered_map<string, map<int, string>> mapp;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
       mapp[key].insert({timestamp,value}); 
    }
    
    string get(string key, int timestamp) {
        auto it = mapp[key].upper_bound(timestamp);
        return it == mapp[key].begin() ? "": prev(it)->second;
    }
};
