struct Node {
    Node* links[26];
    int cntPrefix = 0;
    
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }
    
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    
    void increasePrefix() {
        ++cntPrefix;
    }
    int getPrefixCnt() {
        return cntPrefix;
    }
};
class Solution {
  public:
    Node* root = new Node();
    void insert(string s) {
        Node *node = root;
        for (auto &c: s) {
            if (!node->containsKey(c)) {
                node->put(c, new Node());
            }
            node = node->get(c);
            node->increasePrefix();
        }
    }
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        for (auto &s: arr) {
            insert(s);
        }
        
        vector<string> res;
        for (auto &s: arr) {
            string sp;
            Node* node = root;
            for (auto &c: s) {
                sp += c;
                node = node->get(c);
                
                if (node->getPrefixCnt() == 1) {
                    break;
                }
            }
            res.push_back(sp);
        }
        
        return res;
    }
};