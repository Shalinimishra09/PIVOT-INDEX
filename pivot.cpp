/*Question:
You have a sorted list of numbers that has been rotated at some unknown point.
 Given this rotated list and a target number, find the index of the target number.
  If the target is not in the list, return -1.

The solution should be efficient and work in O(log n) time.*/



#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>&nums,int target){
    int left=0;
    int right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[left]<=nums[mid]){
            if(nums[left]<=target && target<nums[mid]){
                right =mid-1;
            }
            else{
                left=mid+1;
            }
         
        }
           else{
            if(nums[mid]<target && target<=nums[right]){
                left=mid+1;

            }
            else{
                right=mid-1;
            }
           }
        
    }
    return -1;
}
int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    int target= 0;
    int result=search(nums,target);
    if(result!=-1){
        cout<<"target foumd at index : "<<result<<endl;
        
    }
    else{
        cout<<"target is not found"<<endl;

    }
return 0;
}