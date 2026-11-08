class MedianFinder {
private:
    std::priority_queue<int,std::vector<int>> max_heap;
    std::priority_queue<int,std::vector<int>,std::greater<int>> min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (!min_heap.empty() and num > min_heap.top()) {
            min_heap.push(num);
        }
        else {
            max_heap.push(num);
        }

        if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if (min_heap.size() < max_heap.size()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        
    }
    
    double findMedian() {
        if (min_heap.size() > max_heap.size()) {
            return min_heap.top();
        }
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        }
        return static_cast<double>
        ((static_cast<double>(min_heap.top()) + static_cast<double>(max_heap.top())) /2);
    }
};
