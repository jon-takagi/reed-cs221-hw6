#include "hforest.hh"


HForest::HForest(std::vector<HTree::tree_ptr_t> h) {
    heap = h;
    this -> heapify();
}
HForest::~HForest() {

}
void HForest::heapify() {
    std::make_heap(this -> heap.begin(), this->heap.end(), compare_trees);
}
bool compare_trees(HTree::tree_ptr_t t1, HTree::tree_ptr_t t2) {
    return t1->get_value() < t2->get_value();
}
int HForest::size() const{
    return this -> heap.size();
}
void HForest::add_tree(HTree::tree_ptr_t new_node){
    this -> heap.push_back(new_node);
    this -> heapify();
}
HTree::tree_ptr_t HForest::pop_tree(){
    std::pop_heap(this -> heap.begin(), this -> heap.end());
    HTree::tree_ptr_t max = this -> heap.back();
    this -> heap.pop_back();
    return max;
}
