#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>&, int);

int main(){
	std::vector<int> nums = { 2, 7, 11, 15 };
	std::vector<int> indices = twoSum(nums, 9);
	std::cout << "[ ";
	for(auto & idx: indices) {
		std::cout << idx << " ";
	}
	std::cout << "]" << std::endl;
	return 0;
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> map;
	std::vector<int> indices;
	int addend; 
	for(int i = 0; i < nums.size(); ++i) {
		addend = target - nums[i];

		/* If you find the second addend to create the target,
		 * insert both indices into your indices vector and 
		 * return the array.
		 */
		if(map.find(addend) != map.end()) {
			indices.push_back(map[addend]);
			indices.push_back(i);
			return indices;
		}
		// Otherwise insert the current number into the vector. 
		map[nums[i]] = i;
	}
}

