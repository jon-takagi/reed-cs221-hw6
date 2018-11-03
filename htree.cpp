#include "htree.hh"
#include <assert.h>
HTree::HTree(int key, uint64_t value, tree_ptr_t left, tree_ptr_t right){
    key_ = key;
    value_ = value;
    left_ = left;
    right_ = right;
}
HTree::~HTree(){
    // delete &key_;
    // delete &value_;
    // delete &left_;
    // delete &right_;

}

int HTree::get_key() const{
    return key_;
}  // Return key in current node

uint64_t HTree::get_value() const   {
    return value_;
}  // Return value in current node

// Return the child of this node indicated by dir.
// If the child is nullptr (current node is a leaf), returns nullptr.
HTree::tree_ptr_t HTree::get_child(Direction dir) const{
    if(dir == Direction::LEFT) {
        return left_?   left_ : nullptr;
    } else if(dir == Direction::RIGHT) {
        return right_?  right_ : nullptr;
    } else {
        return nullptr;
    }
}

// Return a list of directions from root to a node of a given key.
// Crashes (with an assert) if key not contained in this tree
HTree::path_t HTree::path_to(int key) const{
    if(left_ && left_->contains_key(key)) {
        path_t p = this ->left_ -> path_to(key);
        p.push_front(Direction::LEFT);
        return p;
    }
    if(this -> key_ == key) {
        path_t empty_path;
        return empty_path;
    }
    if(right_ && right_ -> contains_key(key)) {
        path_t p = this ->right_ -> path_to(key);
        p.push_front(Direction::RIGHT);
        return p;
    }
    assert(false);
}
bool HTree::in_subtree(tree_ptr_t tree, int key) const {
    return tree -> key_ == key || (tree -> left_ && in_subtree(tree->left_,key)) || (tree -> right_ && in_subtree(tree->right_,key));
}
// bool HTree::contains_key(int key) const {
//     return
//         this -> get_key() == key ||
//         (this -> get_child(HTree::Direction::LEFT)  && this -> get_child(HTree::Direction::LEFT)  -> contains_key(key)) ||
//         (this -> get_child(HTree::Direction::RIGHT) && this -> get_child(HTree::Direction::RIGHT) -> contains_key(key));
// }

bool HTree::contains_key(int key) const {
    return
        get_key() == key ||
        (left_  && left_  -> contains_key(key)) ||
        (right_ && right_ -> contains_key(key));
}
