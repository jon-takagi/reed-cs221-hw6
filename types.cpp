#include <utility>
#include <list>
#include <iostream>
#include "htree.cpp"

int main() {
    std::list<std::pair<int,uint64_t>> args = {std::make_pair(126,0),std::make_pair(-5,0),std::make_pair(12,0)};
    int key0 = args.front().first;
    std::cout << key0 << '\n';
    uint64_t val0 = args.front().second;
    std::cout << val0 << '\n';
    args.pop_front();

    // int key1 = args.front().first;
    // std::cout << key1 << '\n';
    // uint64_t val1 = args.front().second;
    // std::cout << val1 << '\n';
    HTree::tree_ptr_t l(new HTree(args.front().first, args.front().second));
    args.pop_front();

    // int key2 = args.front().first;
    // std::cout << key2 << '\n';
    // uint64_t val2 = args.front().second;
    // std::cout << val2 << '\n';
    HTree::tree_ptr_t r(new HTree(args.front().first,args.front().second));
    args.pop_front();

    HTree::tree_ptr_t root(new HTree(key0,val0,l,r));

    assert(root -> get_key() == 126);
    assert(root -> get_child(HTree::Direction::LEFT) -> get_key() == -5);
}
