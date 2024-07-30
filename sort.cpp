#include <bits/stdc++.h>
using namespace std;


typedef long long int ll;
typedef pair<int,int> pii;
#define MOD 1000000007

vector<int> nums;

/*      Merge Sort      */

void merge(int low ,int high,int mid){
    int left = low ;
    int right = mid+1; 

    vector<int> temp;

    while(left <= mid && right <= high){
        if(nums[left] < nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(nums[right]);
        right++;
    }

    for(int i = low ; i <= high ; i++){
        nums[i] = temp[i-low];
    }

}

void mergeSort(int low ,int high){
    if(low >= high) return;

    int mid = (low+high)/2;

    mergeSort(low,mid);
    mergeSort(mid+1,high);

    merge(low,high,mid);
}


/*      Quick Sort      */

int partition(int low,int high){
    int pivot = nums[low];
    int i = low , j = high;

    while(i < j){
        while(nums[i] <= pivot  && i <= high -1) i++;
        while(nums[j] > pivot && j >= low+1) j--;

        if(i < j) swap(nums[i],nums[j]);
    }

    swap(nums[low],nums[j]);
    return j;
}

void QuickSort(int low,int high){
    if(low >= high) return;
    
    int pIndex = partition(low,high);
    QuickSort(low,pIndex-1);
    QuickSort(pIndex+1,high);
}

int main(){
    nums = {5,4,2,1,3};
    int n = nums.size();
    QuickSort(0,n-1);
    for(int i = 0 ; i < nums.size() ; i++){
        cout << nums[i] << " ";
    }

    return 0;
}