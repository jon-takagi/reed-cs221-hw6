/*
 * HTree: a class to represent a tree node with two values: a key
 * and a value.
 */

#pragma once
#include <memory>
#include <utility>
#include <vector>
#include <list>

class HTree {
    public:
        using tree_ptr_t = std::shared_ptr<const HTree>;
        enum class Direction { LEFT, RIGHT };
        using path_t = std::list<Direction>;

        // Initialize with a key and a value:
        HTree(int key,
            uint64_t value,
            tree_ptr_t left = nullptr,
            tree_ptr_t right = nullptr);
        ~HTree();

        int get_key() const;  // Return key in current node
        uint64_t get_value() const;      // Return value in current node

        // Return the child of this node indicated by dir.
        // If the child is nullptr (current node is a leaf), returns nullptr.
        tree_ptr_t get_child(Direction dir) const;

        // Return a list of directions from root to a node of a given key.
        // Crashes (with an assert) if key not contained in this tree
        path_t path_to(int key) const;
        // void set_child(Direction d, tree_ptr_t child);
        // void set_key(int k);
        // void set_value(uint64_t v);
    private:
        bool contains_key(int key) const;
        int key_;
        uint64_t value_;
        tree_ptr_t left_;
        tree_ptr_t right_;
};

std::string direction_to_string(HTree::Direction);
//takes a vector of pointers to key/value pairs
//creates a tree using those pairs as if the vector was a heap
//just calls the helper function with index=1
//this is implementation hiding!
HTree::tree_ptr_t make_tree(std::vector<std::shared_ptr<std::pair<int,uint64_t>>> args);
HTree::tree_ptr_t make_tree_helper(std::vector<std::shared_ptr<std::pair<int,uint64_t>>> args,long unsigned int index = 1);
