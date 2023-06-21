/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
struct Node
{
    int key, val, cnt;
    Node *next;
    Node *prev;
    Node(int key_, int val_)
    {
        key = key_;
        val = val_;
        cnt = 1;
    }
};
struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }
    void deleteNode(Node *node)
    {
        Node *nxt = node->next;
        Node *pre = node->prev;
        pre->next = nxt;
        nxt->prev = pre;
        size--;
    }
};
class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqMap;
    int maxCap;
    int cap;
    int minFreq;

public:
    LFUCache(int capacity)
    {
        maxCap = capacity;
        cap = 0;
        minFreq = 0;
    }
    void updateFreqMap(Node *node)
    {
        keyNode.erase(node->key);
        freqMap[node->cnt]->deleteNode(node);
        if (node->cnt == minFreq && freqMap[node->cnt]->size == 0)
        {
            minFreq++;
        }
        List *nextFreqList = new List();
        if (freqMap.find(node->cnt + 1) != freqMap.end())
        {
            nextFreqList = freqMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextFreqList->addFront(node);
        freqMap[node->cnt] = nextFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->val;
            updateFreqMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxCap == 0)
            return;
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->val = value;
            updateFreqMap(node);
        }
        else
        {
            if (cap == maxCap)
            {
                List *list = freqMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqMap[minFreq]->deleteNode(list->tail->prev);
                cap--;
            }
            cap++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqMap.find(minFreq) != freqMap.end())
            {
                listFreq = freqMap[minFreq];
            }
            Node *node = new Node(key, value);
            listFreq->addFront(node);
            keyNode[key] = node;
            freqMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
