#include <iostream>
using namespace std;

struct Trie
{
    struct Trie *children[27];
    bool endofword;
};
struct Trie *WordDictionary()
{
    struct Trie *root =  new Trie;

    root->endofword = false;

    for (int i = 0; i < 26; i++)
    {
        root->children[i] = NULL;
    }
    //cout<<"Object Created"<<endl;
    return root;
}

void addWord(struct Trie *root, string key)
{
    struct Trie *node = root;

    for (int i = 0; i < key.length(); i++)
    {
        if(key[i]=='.')
        {
            if (!node->children[27])
            {
                node->children[27] = WordDictionary();
            }
            node = node->children[27];
        }
        else
        {
            int index = key[i] - 'a';
            if (!node->children[index])
            {
                node->children[index] = WordDictionary();
            }
            node = node->children[index];
        }
    }
    node->endofword = true;
    cout<<"Word Added"<<endl;
}

bool search(struct Trie *root, string key)
{
    struct Trie *node = root;
    int dot=0;
    for (int i = 0; i < key.length(); i++)
    {
        if(key[i]=='.')
        {
            for (int i = 0; i < 27; i++)
            {
                if(node->children[i] != NULL)
                {
                    dot=1;
                    node = node->children[i];
                    break;
                }
            }
            if(dot==0)
            {
                return false;
            }
        }
        else
        {

        int index = key[i] - 'a';
        if (!node->children[index])
        {
            return false;
        }
        node = node->children[index];

    }

        }

    return (node->endofword);
}



int main()
{
    struct Trie *root = WordDictionary();
    addWord(root,"bad");
    addWord(root,"dad");
    addWord(root,"mad");
    if(search(root,".ac"))
    {
        cout<<"Word Found"<<endl;
    }
    else
    {
        cout<<"Word Not Found"<<endl;

    }
    return 0;
}


