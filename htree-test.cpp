#include "htree.cpp"
#include <assert.h>
#include <iostream>

int main() {
    HTree::tree_ptr_t lrl(new HTree(9,0,nullptr,nullptr));
    HTree::tree_ptr_t lr(new HTree(6,0,lrl, nullptr));
    HTree::tree_ptr_t ll(new HTree(-12,0,nullptr,nullptr));
    HTree::tree_ptr_t l(new HTree(-5,0,ll,lr));
    HTree::tree_ptr_t rl(new HTree(3,0));
    HTree::tree_ptr_t r(new HTree(12,0,rl, nullptr));
    HTree::tree_ptr_t root(new HTree(126,0,l,r));

    assert(root -> get_key() == 126);
    assert(root -> get_child(HTree::Direction::LEFT) -> get_key() == -5);

    assert(root->get_child(HTree::Direction::RIGHT)
     -> get_child(HTree::Direction::LEFT) -> get_key() == 3);

    HTree::path_t path_to_9 = root -> path_to(9);
    HTree::path_t expected_path_to_9 = {
        HTree::Direction::LEFT,
        HTree::Direction::RIGHT,
        HTree::Direction::LEFT
    };
    HTree::path_t path_to_3 = root -> path_to(3);
    HTree::path_t expected_path_to_3 = {
        HTree::Direction::RIGHT,
        HTree::Direction::LEFT
    };
    HTree::path_t path_to_126 = root -> path_to(126);
    HTree::path_t expected_path_to_126 = {
    };
    assert(path_to_9 == expected_path_to_9);
    assert(path_to_3 == expected_path_to_3);
    assert(path_to_126 == expected_path_to_126);
    
    // root -> path_to(45);
    // assert(false && "path_to did not exit on nonexistant value");
}
