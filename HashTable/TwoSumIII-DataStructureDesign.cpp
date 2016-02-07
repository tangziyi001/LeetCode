// Usage of unordered multiset. 
// Check if the two numbers are equal. If so, there should be two of it in the set.
class TwoSum {
public:
    unordered_multiset<int> ss;
    // Add the number to an internal data structure.
	void add(int number) {
	    ss.insert(number);
	}
    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(int i : ss){
            if(value-i != i){
                if(ss.find(value-i) != ss.end()) return true;
            }
            else{
                if(ss.count(i) > 1) return true;
            }
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);