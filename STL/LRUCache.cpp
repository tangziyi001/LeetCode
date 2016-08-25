class LRUCache{
    unordered_map<int, list<pair<int, int>>::iterator> mm;
    list<pair<int,int>> ll;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        auto iter = mm.find(key);
        if(iter == mm.end()){
            return -1;
        }
        ll.splice(ll.begin(), ll, iter->second);
        return (ll.begin())->second;
    }
    
    void set(int key, int value) {
        auto iter = mm.find(key);
        if(iter != mm.end()){
            iter->second->second = value;
            ll.splice(ll.begin(), ll, iter->second); // move the record
        }
        else {
            if(mm.size() == cap){
                auto back = ll.back(); // NOTICE: back() return a reference
                mm.erase(back.first);
                ll.pop_back();
            }
            ll.emplace_front(key, value);
            mm[key] = ll.begin();
        }
    }
};