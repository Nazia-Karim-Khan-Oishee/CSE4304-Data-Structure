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
        int index = key[i] - 'a';
        if (!node->children[index])
        {
            node->children[index] = WordDictionary();
        }
        node = node->children[index];
    }

    node->endofword = true;
    //cout<<"Word Added"<<endl;
}
void Search(struct Trie *n,string prefix)
{
    int searchCount=0;

    if(searchCount>=3)
    {
        return;
    }
    if (n->endofword)
    {

        cout << prefix << endl;
        searchCount++;
    }

    for (int i = 0; i < 26; i++)
        if (n->children[i])
        {
            char child = 'a' + i;
            Search(n->children[i],prefix + child);
        }
}

void Prefix(struct Trie *root, string prefix)
{
    struct Trie *temp = root;
    for(int i=0; i<prefix.length(); i++)
    {
        if(temp->children[prefix[i]-'a'])
        {
            temp = temp->children[prefix[i]-'a'];
        }
        else
        {
            return;
        }
    }
    Search(temp,prefix);
}


int main()
{
    struct Trie *root = WordDictionary();
    string keys[] = {"mobile","mouse","monitor","moneypot","mousepad"};
    int n= sizeof(keys)/sizeof(keys[0]);
    for(int i=0; i<n; i++)
    {
        addWord(root,keys[i]);
    }
    cout<<"Enter String:";
    string str;
    cin>>str;
    for(int i=0; i<str.length(); i++)
    {
        //searchCount=0;
        Prefix(root,str.substr(0,i+1));
        cout<<endl;
    }

    return 0;
}


