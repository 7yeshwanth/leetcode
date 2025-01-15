class node {
public:
    int key;
    int val;
    node* next;
    node* prev;
    node(int _key, int value) {
        key = _key;
        val = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
public:
    int cap;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    unordered_map<int, node*> m;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        node* p = m[key];
        p->prev->next = p->next;
        p->next->prev = p->prev;
        head->next->prev = p;
        p->next = head->next;
        head->next = p;
        p->prev = head;
        return p->val;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            m[key]->val = value;
            node* p = m[key];
            p->prev->next = p->next;
            p->next->prev = p->prev;
            head->next->prev = p;
            p->next = head->next;
            head->next = p;
            p->prev = head;
            return;
        }

        if (m.size() >= cap) {
            node* toDelete = tail->prev;
            m.erase(toDelete->key);
            tail->prev = toDelete->prev;
            toDelete->prev->next = tail;

            delete toDelete;
        }

        node* n = new node(key, value);
        m[key] = n;
        n->next = head->next;
        head->next->prev = n;
        head->next = n;
        n->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */