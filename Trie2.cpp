#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    int ew = 0;
    int cp = 0;
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
    void increaseEnd()
    {
        ew++;
    }
    bool isEnd()
    {
        return (ew != 0);
    }
    void increasePrefix()
    {

        cp++;
    }
    void decreasePrefix()
    {
        cp--;
    }
    void deleteEnd()
    {
        ew--;
    }
    int pfx()
    {
        return cp;
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

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {

                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    // bool search(string word)
    // {
    //     Node *node = root;
    //     for (int i = 0; i < word.length(); i++)
    //     {
    //         if (!node->containKey(word[i]))
    //         {
    //             return false;
    //         }
    //         node = node->get(word[i]);
    //     }
    //     return node->isEnd();
    // }
    int countWordsEqualTo(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        if (node->isEnd())
        {
            return node->ew;
        }
        else
        {
            return 0;
        };
    }
    int countWordsStartingWith(string word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->pfx();
    }
    void erase(string word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            node = node->get(word[i]);
            node->decreasePrefix();
        }
        node->deleteEnd();
    }
};

int main()
{
    Trie *tri = new Trie();
    tri->insert("hello");
    tri->insert("hello");
    tri->insert("help");
    cout << tri->countWordsEqualTo("hello");
    cout << tri->countWordsStartingWith("hel");
    tri->erase("hello");
    cout << tri->countWordsEqualTo("hello");
}