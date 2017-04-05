class Solution(object):
    def isLeadingZero(self, num):
        # Check if the number has leading zero.
        return num.startswith('00') or (int(num) != 0 and num.startswith('0'))
    # We cut the string from right to left. Iterate all possible right segment R as a valid number and solve the remaining left segment L recursively. The right segment will be appended to the left segment.
    # In the current recursion, if we want to add '*' between left (L) and right segment (R) , we must let the next recursion (the recursion on L, in which L will be splited again into smaller left and right segments L' and R') know that the multiplication operation between R' and R must happen before plus or minus operation between L' and R' (i.e. L'+R'*R). One way to do that is to make each chain of multiplications as a bundle, and pass that bundle to the next recursion. Whenever a recursion wants to add/minus the left segment with its right segment (i.e. L'+R'), we must first compute the product between the right segment and the bundle that comes from the previous recursion first (i.e. R'*R), so that we can compute (L'+R'*R) correctly. We must also compute the bundle, if any, in the base case (which means the left most operation is '*').
    # The mulexp keeps track of the multiplication chain. The mulval keeps track of the product carried to the next recursion.
    def solve(self, num, target, mulexp='', mulval=1):
        ans = []
        # Base case:
        if (not self.isLeadingZero(num)) and int(num)*mulval == target:
            ans.append(num + mulexp) # Release the bundle if any

        # Iterate all valid number that can be constructed as the right segment
        for i in range(len(num)-1): # len(num)-1 means we cannot make the right segment as an empty string (not a valid number)
            left = num[:i+1]
            right = num[i+1:]
            if self.isLeadingZero(right):
                continue # not a valid number
            # To make add/minus operations, we must check if the previous recursion requires the current recursion to be mindful of the multiplication operation on its right. If so, we retrieve the products of the bundle and apply them to the right segment. Then change the target value to reflect that we release the bundle.
            # Since add/minus operations terminate the multiplication chain, we don't need to pass them to the next recursion
            for re in self.solve(left, target-mulval*int(right)):
                ans.append(re + '+' + right + mulexp)
            for re in self.solve(left, target+mulval*int(right)):
                ans.append(re + '-' + right + mulexp)
            # For multiplication operation, the chain remains and we pass the bundle to the next recursion.
            for re in self.solve(left, target, '*'+right+mulexp, mulval*int(right)):
                ans.append(re)
        return ans
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        if(num == ''):
            return []
        else:
            return self.solve(num, target)