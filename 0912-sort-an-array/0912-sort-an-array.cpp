class Solution {
public:
    void heapify(vector<int>& arr, int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(arr[smallest], arr[i]);
            heapify(arr, n, smallest);
        }
    }
    void buildheap(vector<int>& arr) {
        int n = arr.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }
    vector<int> heapsort(vector<int>& arr, int size) {
        vector<int> sorted;
        sorted.reserve(size);
        while (size > 0) {
            sorted.push_back(arr[0]);
            swap(arr[0], arr[size - 1]);
            size--;
            heapify(arr, size, 0);
        }
        return sorted;
    }
    vector<int> sortArray(vector<int>& nums) {
        buildheap(nums);
        return heapsort(nums, nums.size());
    }
};