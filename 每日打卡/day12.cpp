#include <iostream>
#include <map>
using namespace std;

// 双向链表+哈希表

struct DoubleLinked{
    int val,key;
    DoubleLinked* pre;
    DoubleLinked* next;
    DoubleLinked() {}
    DoubleLinked(int key, int val)
                : key(key), val(val), pre(NULL), next(NULL) {}
    DoubleLinked(int key,int val, DoubleLinked* pre)
                : key(key), val(val), pre(pre), next(NULL) {}
    DoubleLinked(int key,int val, DoubleLinked* pre, DoubleLinked* next) 
                : key(key), val(val), pre(pre), next(next) {}

};
class LRUCache {
private:
    map<int, DoubleLinked*> m;
    int capacity;   
    DoubleLinked* head = new DoubleLinked();
    DoubleLinked* tail = new DoubleLinked(); 

    // 插入头部
    void insert(DoubleLinked* new_node) {
        DoubleLinked* temp = head->next;
        head->next = new_node;
        temp->pre = new_node;
        new_node->next = temp;
        new_node->pre = head;
    }

    // 删除尾部
    void del() {
        DoubleLinked* temp = tail->pre->pre;
        DoubleLinked* dele = tail->pre;
        temp->next = tail;
        tail->pre = temp;
        
    }

    // 提前到头部
    void move_head(DoubleLinked* target) {
        // 删除原来位置上
        target->pre->next = target->next;
        target->next->pre = target->pre;
        // 放置到头部
        target->next = head->next;
        head->next->pre = target;
        head->next = target;
        target->pre = head;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(!m.count(key)) {
            return -1;
        }
        // 提前到头部
        move_head(m[key]);
        // cout << "get : " << m[key]->val << endl;
        return m[key]->val;
    }
    
    void put(int key, int value) {

        if(!m.count(key)){
            // 不存在，插入双向链表的头部
            capacity--;
            DoubleLinked* new_node = new DoubleLinked(key, value);
            m[key] = new_node;
            insert(new_node);
            if(capacity < 0) {
                // 删除双向链表尾部最久未使用
                m.erase(tail->pre->key);
                del();
                capacity = 0;
            } 
        }
        else {
            // 存在，改变值，并且提前
            m[key]->val = value;
            move_head(m[key]);
        }
    }

};



int main() {
    LRUCache l(2);
    l.put(1, 1);
    l.put(2, 2);
    l.get(1);
    l.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    l.get(2);    // 返回 -1 (未找到)
    l.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    l.get(1);    // 返回 -1 (未找到)
    l.get(3);    // 返回 3
    l.get(4);
    cout << 1 << endl;
}

////////////////
// struct DLinkedNode {
//     int key, value;
//     DLinkedNode* prev;
//     DLinkedNode* next;
//     DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
//     DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
// };

// class LRUCache {
// private:
//     unordered_map<int, DLinkedNode*> cache;
//     DLinkedNode* head;
//     DLinkedNode* tail;
//     int size;
//     int capacity;

// public:
//     LRUCache(int _capacity): capacity(_capacity), size(0) {
//         // 使用伪头部和伪尾部节点
//         head = new DLinkedNode();
//         tail = new DLinkedNode();
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     int get(int key) {
//         if (!cache.count(key)) {
//             return -1;
//         }
//         // 如果 key 存在，先通过哈希表定位，再移到头部
//         DLinkedNode* node = cache[key];
//         moveToHead(node);
//         return node->value;
//     }
    
//     void put(int key, int value) {
//         if (!cache.count(key)) {
//             // 如果 key 不存在，创建一个新的节点
//             DLinkedNode* node = new DLinkedNode(key, value);
//             // 添加进哈希表
//             cache[key] = node;
//             // 添加至双向链表的头部
//             addToHead(node);
//             ++size;
//             if (size > capacity) {
//                 // 如果超出容量，删除双向链表的尾部节点
//                 DLinkedNode* removed = removeTail();
//                 // 删除哈希表中对应的项
//                 cache.erase(removed->key);
//                 // 防止内存泄漏
//                 delete removed;
//                 --size;
//             }
//         }
//         else {
//             // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
//             DLinkedNode* node = cache[key];
//             node->value = value;
//             moveToHead(node);
//         }
//     }

//     void addToHead(DLinkedNode* node) {
//         node->prev = head;
//         node->next = head->next;
//         head->next->prev = node;
//         head->next = node;
//     }
    
//     void removeNode(DLinkedNode* node) {
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//     }

//     void moveToHead(DLinkedNode* node) {
//         removeNode(node);
//         addToHead(node);
//     }

//     DLinkedNode* removeTail() {
//         DLinkedNode* node = tail->prev;
//         removeNode(node);
//         return node;
//     }
// };

