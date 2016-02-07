// Java Iterator
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
    Iterator<Integer> it;
    Integer nxt = null;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    it = iterator;
	    if(it.hasNext())
	        nxt = it.next();
	    else nxt = null;
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return nxt;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if(it.hasNext()){
	        Integer tmp = nxt;
	        nxt = it.next();
	        return tmp;
	    }
	    else{
	        Integer tmp = nxt;
	        nxt = null;
	        return tmp;
	    }
	}

	@Override
	public boolean hasNext() {
	    return !(nxt == null);
	}
}