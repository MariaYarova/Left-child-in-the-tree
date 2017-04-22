
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int counter = 0;
int counter1 = 0;
struct Tree
{
    Tree *right = NULL;
    Tree *left = NULL;
    Tree *parent;
    int key;
    void add_tree(int key);
    int left_child(int key);
};

void Tree::add_tree(int key)
{
    if (this->key > key)
    {
        if (left == NULL)
        {
            left = new Tree;
            left->key = key;
            left->parent = this;

        }
        else left->add_tree(key);
    }
    else if (this->key < key)
    {
        if (right == NULL)
        {
            right = new Tree;
            right->key = key;
            right->parent = this;
        }
        else right->add_tree (key);
    }
}
int Tree::left_child(int key)
{
   int znach;
   if ((left != NULL)&&(right == NULL))
        {
            counter++;
            znach = this->key;
            if (counter1 == 0)
            {
                counter1++;
                cout << "The answer is:" << " " << znach << " ";
                left->left_child(key);
            }
            else
            {
                cout << znach << " ";
                left->left_child(key);
            }
        }
   if ((left == NULL) && (right == NULL)) {return 0;}
   if ((right != NULL)&&(left == NULL))
            right->left_child(key);
   if ((right != NULL)&&(left != NULL))
   {
       left->left_child(key);
       right->left_child(key);
   }

}
int main() {
    Tree* tree = new Tree();
    cin >> tree->key;
    int a = tree->key;
    string e = "";
    while (e != ".")
    {
        cin >> e;
        if (e == ".") break;
        else
        {
            int key = stoi(e, nullptr, 0);
            tree->add_tree(key);
        }
    }
    tree->left_child(a);
    if (counter == 0) cout << "There is no needed elements";
}
