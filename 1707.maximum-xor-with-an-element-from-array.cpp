/*
 * @lc app=leetcode id=1707 lang=cpp
 *
 * [1707] Maximum XOR With an Element From Array
 */

// @lc code=start
class Solution
{
public:
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

    public:
        Trie()
        {
            root = new Node();
        }
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
    static bool comparator(pair<int, pair<int, int>> &p, pair<int, pair<int, int>> &q)
    {
        return p.second.first < q.second.first;
    }
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = queries.size();
        vector<int> ans(n, -1);
        Trie *trie = new Trie();
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> q;
        for (int i = 0; i < queries.size(); i++)
        {
            q.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(q.begin(), q.end());
        int ind = 0;

        for (int i = 0; i < q.size(); i++)
        {
            while (ind < nums.size() && nums[ind] <= q[i].first)
            {
                trie->insert(nums[ind]);
                ind++;
            }
            if (ind == 0)
            {
                ans[q[i].second.second] = -1;
            }
            else
            {
                int mx = trie->getMax(q[i].second.first);

                ans[q[i].second.second] = mx;
            }
        }
        return ans;
    }
};
// @lc code=end
