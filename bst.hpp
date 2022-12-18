#ifndef BST_HPP
#define BST_HPP

#include <stdexcept>
#include "bstnode.hpp"

template <typename T>
class bst {
    public:
        bst() {
            this->root = nullptr;
            this->size = 0;
        }

        /**
         * @return the number of nodes in the tree
         */
        int get_size() {
            return size;
        }

        /**
         * Inserts a value into the tree.
         *
         * @param data the value to be inserted
         */
        void insert(T data) {
            if (this->root == nullptr) {
                this->root = new bstnode<T>(data, nullptr, nullptr);
            } else {
                this->root->insert(data);
            }
        }

        /**
         * @param data the value to search for 
         * @return true if value is contained in the tree, false otherwise
         */
        bool contains(T data) {
            return this->root ? this->root->contains(data) : false;
        }
        
        /**
         * Computes the depth of the tree
         *
         *@return the depth of the tree
         */
        int max_level() {
            return this->root ? this->root->max_level() : 0;
        }

        /**
         * Computes the number of left children in the tree
         * 
         * @return the number of left children in the tree
         */
        int num_left() {
            return this->root ? this->root->left->num_left() + this->root->right->num_left() : 0;
        }

    private:
        /** The root of the tree */
        bstnode<T> *root;

        /** The number of nodes in the tree */
        int size;
};

#endif