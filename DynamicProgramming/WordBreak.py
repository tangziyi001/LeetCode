class Solution(object):
    dp = [] # dp[i] indicates if starting from i is possible
    def recur(self, s, i, ss):
        if i == len(s) or self.dp[i] == 1:
            return True
        if self.dp[i] == 0: # If previous recursion finds that starting from i is impossible, then we don't need to proceed
            return False
        flag = 0 # Record if starting from i is possible
        for j in range(i, len(s)): # Enumerate end point of this word
            now = s[i:j+1]
            if now in ss: # Lookup the dictionary
                flag = flag or self.recur(s, j+1, ss)
        self.dp[i] = flag
        return flag

    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        ss = set(wordDict) # Set has time complexity of O(1) for lookup
        self.dp = [-1]*len(s)
        if(self.recur(s,0,ss)):
            return True
        return False