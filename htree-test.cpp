#include "htree.cpp"
#include <assert.h>
#include <iostream>
#include <utility>

void inorder_traversal(HTree::tree_ptr_t node) {
    if(node -> get_child(HTree::Direction::LEFT)) {
        inorder_traversal(node -> get_child(HTree::Direction::LEFT));
    }
    std::cout << std::to_string(node -> get_key()) << "\n";
    if (node ->get_child(HTree::Direction::RIGHT)) {
        inorder_traversal(node ->get_child(HTree::Direction::RIGHT));
    }
}
void preorder_traversal(HTree::tree_ptr_t node) {
    std::cout << std::to_string(node -> get_key()) << "\n";
    if(node -> get_child(HTree::Direction::LEFT)) {
        preorder_traversal(node -> get_child(HTree::Direction::LEFT));
    }
    if (node ->get_child(HTree::Direction::RIGHT)) {
        preorder_traversal(node ->get_child(HTree::Direction::RIGHT));
    }
}
int main() {
    // HTree::tree_ptr_t lrl(new HTree(9,0,nullptr,nullptr));
    // HTree::tree_ptr_t lr(new HTree(6,0,lrl, nullptr));
    // HTree::tree_ptr_t ll(new HTree(-12,0,nullptr,nullptr));
    // HTree::tree_ptr_t l(new HTree(-5,0,ll,lr));
    // HTree::tree_ptr_t rl(new HTree(3,0));
    // HTree::tree_ptr_t r(new HTree(12,0,rl, nullptr));
    // HTree::tree_ptr_t root(new HTree(126,0,l,r));

    std::vector<std::shared_ptr<std::pair<int,uint64_t>>> args {
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(126,0)),
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(-5,0)),
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(12,0)),
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(-12,0)),
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(6,0)),
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(3,0)),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(9,0))
    };

    // std::vector<std::shared_ptr<std::pair<int,uint64_t>>> args {
    //     std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(1,0)),
    //     std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(2,0)),
    //     std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(3,0)),
    //     std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(4,0)),
    //     std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(5,0))
    // };
    // std::vector<std::shared_ptr<std::pair<int,uint64_t>>> args {
    //     std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(12,0)),
    //     nullptr,
    //     std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(3,0))
    // };

    HTree::tree_ptr_t root = make_tree(args);
    HTree::Direction left = HTree::Direction::LEFT;
    HTree::Direction right = HTree::Direction::RIGHT;

    // std::cout<<root->get_child(left) -> get_key() <<"\n";

    //
    assert(root -> get_key() == 126);
    assert(root -> get_child(left) -> get_key() == -5);
    assert(root -> get_child(right) -> get_key() == 12);
    //
    // // std::cout << root -> get_child(HTree::Direction::LEFT)
    // //     -> get_child(HTree::Direction::RIGHT) -> get_key() << "\n";
    // //
    assert(root->get_child(right) -> get_child(left) -> get_key() == 3);
    //
    // std::cout<<root->get_child(right) -> get_key() <<"\n";
    // std::cout<<root->get_child(right) -> get_child(left) -> get_key() <<"\n";

    // std::cout<<"~inorder~" << "\n";
    // inorder_traversal(root);
    // std::cout<<"~~~~~~~~~~~~~~~~~~~" << "\n";
    // std::cout<<"~preorder~" << "\n";
    // preorder_traversal(root);

    HTree::path_t path_to_9 = root -> path_to(9);
    // for(HTree::Direction d : path_to_9) {
    //     std::cout << direction_to_string(d) << "\n";
    // }
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
