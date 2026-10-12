class LinkedList {
public:

    struct Node {
        int i;
        struct Node *next;
    };

    struct Node *head_;
    struct Node *tail_;

    LinkedList() {
        head_ = NULL;
        tail_ = NULL;
    }

    ~LinkedList() {
        while (head_) {
            struct Node *temp = head_->next;
            delete head_;
            head_ = temp;
        }
    }

    int get(int index) {
        struct Node *temp = head_;
        int i = 0;
        while (temp) {
            if (i == index) return temp->i;
            ++i;
            temp = temp->next;
        }
        return -1;
    }

    void insertHead(int val) {
        struct Node *node = new struct Node;
        node->i = val;
        node->next = head_;

        head_ = node;
        if (tail_ == NULL) tail_ = node;
    }
    
    void insertTail(int val) {
        struct Node *node = new struct Node;
        node->i = val;
        node->next = NULL;
        
        if (tail_ == NULL) {
            head_ = node;
        }
        else {
            tail_->next = node;
        }
        tail_ = node;
    }

    bool remove(int index) {
        struct Node *curr = head_;
        struct Node *prev = NULL;
        int i = 0;
        while (curr) {
            if (i == index) {
                // first node in list
                if (prev == NULL) {
                    head_ = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                if (curr == tail_) tail_ = prev;
                delete curr;
                return true;                
            }
            ++i;
            prev = curr;
            curr = curr->next;
        }
        return false;        
    }

    vector<int> getValues() {
        vector<int> result;
        struct Node *temp = head_;
        while (temp) {
            result.push_back(temp->i);
            temp = temp->next;
        }
        return result;
    }
};
