#include <algorithm>
#include "htree.hh"
#include <vector>
bool compare_trees(HTree::tree_ptr_t, HTree::tree_ptr_t);
class HForest {
public:
    HForest(std::vector<HTree::tree_ptr_t>);
    ~HForest();
    int size() const;
    void add_tree(HTree::tree_ptr_t);
    HTree::tree_ptr_t pop_tree();
private:
    std::vector<HTree::tree_ptr_t> heap;
};
