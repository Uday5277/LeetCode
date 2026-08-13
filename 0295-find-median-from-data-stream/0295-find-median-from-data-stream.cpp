class MedianFinder {
public:
    priority_queue<int>smallHeap;
    priority_queue<int,vector<int>,greater<int>>largeHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smallHeap.empty() || num<=smallHeap.top()){
            smallHeap.push(num);
        }else{
            largeHeap.push(num);
        }

        if(smallHeap.size()>largeHeap.size()+1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }else if(largeHeap.size()>smallHeap.size()){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
        
    }
    
    double findMedian() {
        if(smallHeap.size()>largeHeap.size()){
            return smallHeap.top();
        }else{
            return (smallHeap.top()+largeHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */