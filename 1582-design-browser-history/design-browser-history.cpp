class BrowserHistory {
    struct Node {
        string url;
        Node* pre;
        Node* nxt;
        Node(string _url) : url(_url), pre(nullptr), nxt(nullptr) {}
    };

    Node* node;
public:
    BrowserHistory(string homepage) {
        node = new Node(homepage);
    }
    
    void visit(string url) {
        Node* nnode = new Node(url);
        node->nxt = nnode;
        nnode->pre = node;
        node = nnode;
    }
    
    string back(int steps) {
        while (node->pre != nullptr && steps--) {
            node = node->pre;
        }
        return node->url;
    }
    
    string forward(int steps) {
        while (node->nxt != nullptr && steps--) {
            node = node->nxt;
        }
        return node->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */