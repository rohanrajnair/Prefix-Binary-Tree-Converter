#include <iostream>
#include <stack>
#include <iomanip>

using namespace std;


class Node {
public:
    Node(const char& data, Node* left, Node* right) {
        data_ = data;
        left_ = left;
        right_ = right;
    }
    char get_data();
    Node* get_left();
    Node* get_right();
private:
    char data_;
    Node* left_;
    Node* right_;
};

void print_tree(Node* root, int indent);

string reverse(string s);

Node* makeBinary(stack<char>& st);

int main(){
    string s;
    cout << "enter an expression in prefix using letter variables: " << endl;
    getline(cin, s);
    s = reverse(s);
    stack<char> st;
    for (int i = 0; i < s.length(); ++i){
        st.push(s[i]);
    }
    Node* root = makeBinary(st);
    print_tree(root, 4);
}

Node* makeBinary(stack<char>& st){
    char c;
    if (st.empty())
        return nullptr;
    c = st.top();
    st.pop();
    if (isalpha(c)){
        Node* tmp = new Node(c, nullptr, nullptr);
        return tmp;
    }
    else{
        Node* left = makeBinary(st);
        Node* right = makeBinary(st);
        Node* tmp = new Node(c, left, right);
        return tmp;
    }
}

string reverse(string s){
    string s2 = s;
    int j = 0;
    for (int i = s.length()-1; i >=0; --i){
        s2[j] = s[i];
        ++j;
    }
    return s2;
}

Node* Node :: get_left(){
    return this->left_;
}

Node* Node :: get_right(){
    return this->right_;
}

char Node :: get_data(){
    return this->data_;
}

void print_tree(Node* root, int indent){
    if(root != nullptr) {
        if(root->get_right()) {
            print_tree(root->get_right(), indent+4);
        }
        if (indent) {
            cout << setw(indent) << ' ';
        }
        if (root->get_right()){
            cout<<" /\n" << setw(indent) << ' ';
        }
        cout<< root->get_data()<< "\n ";
        if(root->get_left()) {
            cout << setw(indent) << ' ' <<"\\\n";
            print_tree(root->get_left(), indent+4);
        }
    }
}
