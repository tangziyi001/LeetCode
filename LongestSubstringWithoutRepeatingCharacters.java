public class Solution {
    public int lengthOfLongestSubstring(String s) {
		int length = 0;

		LinkedList<String> tmp = new LinkedList<String>();
		for (int i = 0; i < s.length(); i++) {

			if (tmp.contains(s.substring(i, i + 1)) == false) {
				tmp.add(s.substring(i, i + 1));
			} else {
				int len = tmp.size();
				if (len > length) {
					length = len;
				}
				int newbegin = tmp.indexOf(s.substring(i, i + 1));

				for (int j = 0; j <= newbegin; j++) {
					tmp.removeFirst();
				}
				tmp.add(s.substring(i, i + 1));

			}

		}
		int len = tmp.size();
		if (len > length) {
			length = len;
		}

		return length;

	}
    
}