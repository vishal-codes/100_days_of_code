class Solution:
	# @param A : integer
	# @return an integer
	def chordCnt(self, A):
	    x = math.factorial(2*A)
	    y = math.factorial(A)
	    z= (A+1)*y
	    ans = x//(y*z)
	    return ans%(pow(10,9)+7)
    