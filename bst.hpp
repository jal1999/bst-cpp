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
            return level_helper(root);
        }

        /**
         * Computes the number of left children in the tree
         * 
         * @return the number of left children in the tree
         */
        int num_left() {
            return this->root ? this->root->left->num_left() + this->root->right->num_left() : 0;
        }

        bool is_balanced() {
            return is_balanced_helper(root);
        }

        // TODO: IMPLEMENT is_valid()

    private:
        /** The root of the tree */
        bstnode<T> *root;

        /** The number of nodes in the tree */
        int size;

	bool balanced_helper(bstnode *n) {
		if (!n) {
			return true;
		} else if (!balanced_helper(n->left) || !balanced_helper(n->right)) {
			return false;
		} else {
			return abs(n->left->max_level() - n->right->max_level()) <= 1;
		}
	}

    int level_helper(bstnode *node) {
        if (!node) {
            return 0;
        } else if (node->left && node->right) {
            return 1 + std::max(level_helper(node->left), level_helper(node->right));
        } else {
            if (node->left) {
                return 1 + level_helper(node->left);
            } else {
                return 1 + level_helper(node->right);
            }
        }
    }
};

#endif
