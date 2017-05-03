#include <iostream>
#include <vector>
#include <algorithm>
int lengthOfLongestSubstring(std::string);

int main(){
	std::string s = "pwwkew";
	std::cout << lengthOfLongestSubstring(s);
	return 0;
}

/*
 * Create a dictionary of size ASCII (this can probably be optimized)
 * as my memo. Initialize everything to -1, including your start int. 
 * Whenever you don't find the letter you are currently on in your dict, 
 * set that value to the position you are currently at. When you do find it,
 * that means you have ran into a duplicate letter, so that is your new start.
 * The max_length will always either be itself or the current position minus the
 * current start position. Because start is -1, this even calculates correctly for 
 * when you don't have a start position yet, making the code even more compact! :D
 */
int lengthOfLongestSubstring(std::string s) {
	/*
 	 * Create a dictionary of size ASCII (this can probably be optimized)
	 * as my memo. Initialize everything to -1, including your start int. 
 	 */
	std::vector<int> dict(256, -1);
	int max_length = 0, start = -1;
	for(int i = 0; i < s.size(); ++i) {
		/* Whenever you don't find the letter you are currently on in your dict, 
 	 	 * set that value to the position you are currently at. When you do find it,
     	 * that means you have ran into a duplicate letter, so that is your new start.
     	 */
		start = (dict[s[i]] > start) ? dict[s[i]] : start;
		dict[s[i]] = i;
		/* max_length is always either itself or your position minus the current start.
		 * For the sake of compactness, I just put this in one line.
		 */
		max_length = std::max(max_length, i - start);
	}
	return max_length;
}