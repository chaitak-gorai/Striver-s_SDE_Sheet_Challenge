/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
struct Node
{
    Node *links[2];
    bool containKey(int bit)
    {
        return (links[bit] != NULL);
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};
class Trie
{
private:
    Node *root;
    Trie()
    {
        root = new Node();
    }

public:
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node *node = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containKey(1 - bit))
            {
                maxi = maxi | 1 << i;
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxi;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie *trie = new Trie();
        for (int i = 0; i < nums.size(); i++)
        {
            trie->insert(nums[i]);
        }
        int maxi = 0;
        for (int i = 0; i < num.size(); i++)
        {
            int mx = trie->getMax(nums[i]);
            maxi = max(mx, maxi);
        }
        return maxi;
    }
};
// @lc code=end
