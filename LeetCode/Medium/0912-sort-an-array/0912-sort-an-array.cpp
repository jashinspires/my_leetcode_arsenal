class Solution {
public:
    void heapinsert(vector<int> &heap , int value){
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i > 0){
            int parent = (i-1)/2;
            if(heap[parent] >= heap[i]){
                break;
            }
            swap(heap[parent],heap[i]);
            i = parent;
        }
    }

    void heapify(vector<int>& heap , int heapsize){
        int i = 0 ; 
        while(true){
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;
        if(left < heapsize && heap[left] > heap[largest]){
            largest = left;
        }
        if(right < heapsize && heap[right] > heap[largest]){
            largest = right;
        }
        if(largest == i){
            break;
        }
        swap(heap[largest] , heap[i]);
        i = largest;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int s = nums.size();
        vector<int> heap;
        for(int n : nums){
            heapinsert(heap,n);
        }
        for(int k = heap.size() - 1 ; k > 0 ; --k){
            swap(heap[0] , heap[k]);
            heapify(heap,k);
        }
        return heap;
    }
};