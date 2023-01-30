// Tc: O(N) //Linked List deletion and insertion is O(1), and it is done N times
// sc: O(n)

class LRUCache {
private:
    class Node{
    public:
        int key;
        int value;
        Node* prev = NULL;
        Node* next = NULL;

        Node(int key, int value){
            this->key = key;
            this->value = value;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    static const int N = 1e4 + 7;
    Node* hash[N];
    int countSz = 0;

    void addNode(Node* newNode){
        Node* nextNode = head->next;
        nextNode->prev = newNode;
        head->next = newNode;
        newNode->next = nextNode;
        newNode->prev = head;
    }

    void deleteNode(Node* nodeToBeDeleted){
        Node* prevSaveNode = nodeToBeDeleted->prev;
        Node* nextSavedNode = nodeToBeDeleted->next;
        nextSavedNode->prev = prevSaveNode;
        prevSaveNode->next = nextSavedNode;
        // delete(nodeToBeDeleted);
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        for(int i = 0; i < N; i++) hash[i] = NULL;
    }
    
    int get(int key) {
        if( hash[key] != NULL ){
            // cout << hash[key]->value;
            Node* tarNode = hash[key];
            int resVal = tarNode->value;
            deleteNode(tarNode);
            addNode(tarNode);
            hash[key] = head->next;
            return resVal;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if( hash[key] != NULL ){
            Node* tarNode = hash[key];
            deleteNode(tarNode);
            addNode(new Node(key, value));
            hash[key] = head->next;
        }
        else{
            if( cap == countSz ){
                hash[tail->prev->key] = NULL;
                deleteNode(tail->prev);
                addNode(new Node(key, value));
                hash[key] = head->next;
            }
            else{
                countSz++;
                addNode(new Node(key, value));
                hash[key] = head->next;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */