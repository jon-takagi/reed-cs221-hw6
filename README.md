# Contents
1. Headers
2. Implementations
3. Tests
4. Compile instructions

## Headers
There are two header files included in this repository: `htree.hh` and `hforest.hh`
### HTree.hh
`htree.hh` contains the header for HTree, a class representing a single node of a binary tree.
It has been updated from hw5 to use implementation hiding by setting member variables to private to require the use of
the getter functions also declared in this file.

Also, `tree_ptr_t` is a shared pointer to a constant HTree, so no setter methods are possible.
In addition to the methods described in the assignment, two other methods are declared. `direction_to_string` allows for
easier printing of a `path_t`, which I used for testing the `path_to` method.
`make_tree` allows me to create a complex tree by passing a vector containing pointers to key/value pairs which are initialized as a heap.
This method was somewhat complicated to write and debug, but can create non-full trees.

### HForest.hh
This file represents a collection of trees, stored in a heap. There are 3 public methods, as described in the assignment details.
In addition to these methods, I defined a helper method `heapify` in accordance with the DRY principle. This method calls `std::make_heap` on my internal vector structure.
To be able to use the builtin `make_heap` I also defined a comparator on HTrees which compares two HTrees by the value of their root nodes.

## Implementations
There are two relevant implementation files: `htree.cpp` and `hforest.cpp`
### HTree.cpp
The first few methods are fairly self explanatory: the declaration assigns each argument to the member variables, and the getter methods return the values they say they do.
The destructor does nothing because it doesn't have to - everything is a smart pointer.
`path_to` is a recursive method that uses an inorder traversal to search for the value, since in the last assignment, we were instructed to use inorder traversal, and I didn't feel like changing it.
`contains_key` is also recursive, but this uses a preorder traversal. I chose preorder arbitrarily.
`make_tree` is a wrapper for `make_tree_helper`, since `make_tree_helper` requires an index that should always start at 1. This way, implementation of the index argument is hidden from the user.
`make_tree_helper` checks to see if the node should have either a left or right child, creates any children, then creates the node with its children attached.
If the node is `nullptr`, then it skips it and continues. This is done to ensure it does not return the first non `nullptr` child twice.

### HForest.cpp
The constructor takes a vector containing the initial elements, then `heapify`'s the elements.
The destructor does nothing because it doesn't have to - everything is a smart pointer.
`heapify` uses `std::make_heap` because we were told to do so in the assignment. Therefore, the compare_trees method is not a member of HForest or HTree and takes 2 HTree objects.
The `size` of a heap is the size of the vector containing it. Because I used std::vector, it can resize when trees are added or removed.
Adding a tree is easy because the vector has a method `push_back` which automatically enlarges the vector. After an element is added, the vector is then heapified to ensure it is still a heap.
`pop_tree` is given as an example on the C++ reference site describing how make_heap works.

## Tests
The two tests were created before the implementations, in accordance with test driven development.
### htree-test
There's a lot of extra code in this one related to debugging the make_tree and make_tree_helper methods. There are two tree traversal methods that allow me to print trees to confirm they were created correctly.
I create the same tree from hw5, shown below
            126
           /   \
          /     \
        -5       12
        / \     /
     -12   6    3
          /
         9
Using assertions, I confirm that the `get_child` method works on this tree. Then, I test the `path_to` method by comparing the actual and expected results, and asserting that they're equal.

### hforest-test
This program tests the HForest methods by creating a forest from a list of single node trees, and from an empty list.
I then add two trees to the empty tree and test that its size is 2.
I test the pop tree method by popping off the larger tree and asserting that I get the expected value back.
After removing trees from the forest, I also assert that its size has decreased.
