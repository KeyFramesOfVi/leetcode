class Solution {
public:
	double findMedian(vector<int>& search_array, vector<int>& compare_array) {
		
	}




    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	size_one = nums1.size();
    	size_two = nums2.size();
    	if(size_one >= size_two){
    		findMedian(nums1, nums2);
    	} 
    	else{
    		findMedian(nums2, nums1);
    	}
    }
};