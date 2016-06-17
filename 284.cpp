// 284. Peeking Iterator

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    int val;
    bool saved;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    saved = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (!saved) {
            val = Iterator::next();
            saved = true;
        }
        return val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (!saved) {
	        return Iterator::next();
	    }
	    saved = false;
	    return val;
	}

	bool hasNext() const {
	    if (saved) {
	        return true;
	    }
	    if (Iterator::hasNext()) {
	        return true;
	    }
	    return false;
	}
};