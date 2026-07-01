class Node {
public:
    int key, value, freq;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        freq = 1;
        prev = next = nullptr;
    }
};

class List {
public:
    int size;
    Node *head, *tail;

    List() {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLast() {
        if (size == 0) return nullptr;
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LFUCache {
    int capacity;
    int currSize;
    int minFreq;

    unordered_map<int, Node*> keyMap;
    unordered_map<int, List*> freqMap;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int freq = node->freq;

        freqMap[freq]->removeNode(node);

        if (freq == minFreq && freqMap[freq]->size == 0)
            minFreq++;

        node->freq++;

        if (freqMap.find(node->freq) == freqMap.end())
            freqMap[node->freq] = new List();

        freqMap[node->freq]->addFront(node);
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end())
            return -1;

        Node* node = keyMap[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (currSize == capacity) {
            Node* node = freqMap[minFreq]->removeLast();
            keyMap.erase(node->key);
            delete node;
            currSize--;
        }

        Node* node = new Node(key, value);

        minFreq = 1;

        if (freqMap.find(1) == freqMap.end())
            freqMap[1] = new List();

        freqMap[1]->addFront(node);
        keyMap[key] = node;
        currSize++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */