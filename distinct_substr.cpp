struct Node
{
    Node *links[26];
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int cnt = 0;
    Node *node = new Node();
    for (int i = 0; i < s.size(); i++)
    {
        Node *temp = node;
        for (int j = i; j < s.size(); j++)
        {
            if (!temp->containKey(s[j]))
            {
                cnt++;
                temp->put(s[j], new Node);
            }
            temp = temp->get(s[j]);
        }
    }
    return cnt + 1;
}