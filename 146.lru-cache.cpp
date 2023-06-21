/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };
    int cap;
    unordered_map<int, node *> mp;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node *nde)
    {
        node *temp = head->next;
        head->next = nde;
        nde->prev = head;
        nde->next = temp;
        temp->prev = nde;
    }
    void deletenode(node *deln)
    {
        node *pre = deln->prev;
        node *nxt = deln->next;
        pre->next = nxt;
        nxt->prev = pre;
    }
    int get(int key_)
    {
        if (mp.find(key_) != mp.end())
        {
            node *gt = mp[key_];
            mp.erase(key_);
            deletenode(gt);
            addnode(gt);
            mp[key_] = head->next;
            return head->next->val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key_, int value)
    {
        if (mp.find(key_) != mp.end())
        {
            node *existing = mp[key_];
            mp.erase(key_);
            deletenode(existing);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key_, value));
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
