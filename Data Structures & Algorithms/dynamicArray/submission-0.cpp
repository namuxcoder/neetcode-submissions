class DynamicArray {
public:
    std::vector<int> storage_;
    int size_;
    int capacity_;

    DynamicArray(int capacity) : size_(0), capacity_(capacity) {
        storage_.resize(capacity);   // allocated slots, NOT elements
    }

    int get(int i) {
        return storage_[i];
    }

    void set(int i, int n) {
        storage_[i] = n;
    }

    void pushback(int n) {
        if (size_ == capacity_) {
            resize();
        }
        storage_[size_++] = n;
    }

    int popback() {
        return storage_[--size_];
    }

    void resize() {
        capacity_ *= 2;
        storage_.resize(capacity_);  // old values are preserved
    }

    int getSize() {
        return size_;
    }

    int getCapacity() {
        return capacity_;
    }
};