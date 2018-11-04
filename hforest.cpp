#include "hforest.hh"

bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) {
    return t1->get_value() < t2->get_value();
}
int HForest::size() const{
    return this -> heap.size();
}
void HForest::add_tree(HTree::tree_ptr_t new_node){
    this -> heap.push_back(new_node);
    std::make_heap(this -> heap.begin(), this->heap.end(), compare_trees);
}
// HTree::tree_ptr_t HForest::pop_tree(){
//
// }
