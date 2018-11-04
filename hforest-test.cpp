#include <assert.h>
#include "hforest.cpp"
#include "htree.cpp"
int main() {
    std::vector<std::shared_ptr<std::pair<int,uint64_t>>> args1 {
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
    HTree::tree_ptr_t root1 = make_tree(args1,1);

    std::vector<std::shared_ptr<std::pair<int,uint64_t>>> args2 {
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(-5,0)),
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(9,0)),
        std::make_shared<std::pair<int,uint64_t>>(std::pair<int,uint64_t>(12,0))
    };
    HTree::tree_ptr_t root2 = make_tree(args2,1);

    HTree::tree_ptr_t node00(new HTree(0,0));
    HTree::tree_ptr_t node01(new HTree(1,0));
    HTree::tree_ptr_t node02(new HTree(2,0));
    HTree::tree_ptr_t node03(new HTree(3,0));
    HTree::tree_ptr_t node04(new HTree(4,0));
    HTree::tree_ptr_t node05(new HTree(5,0));
    HTree::tree_ptr_t node06(new HTree(6,0));
    HTree::tree_ptr_t node07(new HTree(7,0));
    HTree::tree_ptr_t node08(new HTree(8,0));
    HTree::tree_ptr_t node09(new HTree(9,0));

    std::vector<HTree::tree_ptr_t> nodes {
        node00,
        node01,
        node02,
        node03,
        node04,
        node05,
        node06,
        node07,
        node08,
        node09
    };
    HForest forest(nodes);
    assert(forest.size() == 10);
    std::vector<HTree::tree_ptr_t> nodes2 {};
    HForest forest2(nodes2);
}
