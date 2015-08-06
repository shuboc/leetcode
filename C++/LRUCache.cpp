class LRUCache{

    struct Node {
        int key;
        int value;
        Node *next;
        Node *prev;
        Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
    };
    
    typedef std::unordered_map<int, Node *> Map;
    typedef Map::iterator MapIter;

    Node *_head; // A doubly-linked list whose first element is  from which getting head and tail is fast
    Node *_tail;
    int _size;
    int _capacity;
    Map _map; // A hash table to quickly find a node in a doubly-linked list.
    
public:
    LRUCache(int capacity) : _size(0), _capacity(capacity) {
        if (capacity < 1) return;
        _head = new Node(0, 0);
        _tail = new Node(0, 0);
        _head->next = _tail;
        _tail->prev = _head;
    }
    
    void putToHead(Node *cur) {
        cur->next = _head->next;
        cur->prev = _head;
        _head->next->prev = cur;
        _head->next = cur;
    }
    
    void detach(Node *cur) {
        cur->next->prev = cur->prev;
        cur->prev->next = cur->next;
    }
    
    void removeLast() {
        Node *toDelete = _tail->prev;
        toDelete->prev->next = _tail;
        _tail->prev = toDelete->prev;
        _map.erase(toDelete->key);
        delete toDelete;
    }

    int get(int key) {
        MapIter it = _map.find(key);
        if (it == _map.end()) {
            return -1;
        }
        else {
            // Found. Move this entry to the head of Cache
            Node *cur = it->second;
            detach(cur);
            putToHead(cur);
            return cur->value;
        }
    }
    
    void set(int key, int value) {
        if (_capacity < 1) return;
        MapIter it = _map.find(key);
        if (it == _map.end()) {
            // Insert new node to the front
            Node *cur = new Node(key, value);
            putToHead(cur);
            _map[key] = cur;
            
            if (_size < _capacity) {
                ++_size;
            }
            else {
                // Remove the last node if cache is full
                removeLast();
            }
        } else {
            // Found. Move this entry to the head of Cache
            Node *cur = it->second;
            detach(cur);
            putToHead(cur);
            cur->value = value;
        }
    }
};