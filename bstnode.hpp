#include <cstdlib>

template <typename T>
class bstnode {
            public:
                /** The value contained in the node */
                T data;

                /** The left child of the node */
                bstnode<T> *left;

                /** The right child of the node*/
                bstnode<T> *right;

                bstnode(T data, bstnode *left, bstnode *right) {
                    this->data = data;
                    this->left = left;
                    this->right = right;
                }

                /** 
                 * Either inserts a new value into the tree as a child of the node or
                 * recuses onto its proper child.
                 *
                 * @param data the value being inserted into the tree
                 */
                void insert(T data) {
                    if (data < this->data) {
                        if (this->left == nullptr) {
                            this->left = new bstnode(data, nullptr, nullptr);
                        } else {
                            left->insert(data);
                        }
                    } else {
                        if (this->right == nullptr) {
                            this->right = new bstnode(data, nullptr, nullptr);
                        } else {
                            right->insert(data);
                        }
                    }
                }

                /**
                 * Determines if the current node contains the given value.
                 * 
                 * @param data the value being looked for
                 * @return true if the node contains the value, false otherwise 
                 */
                bool contains(T data) {
                    if (this->data == data) {
                        return true;
                    } else if (data < this->data) {
                        if (this->left) {
                            return this->left->contains(data);
                        } else {
                            return false;
                        }
                    } else {
                        if (this->right) {
                            return this->right->contains(data);
                        } else {
                            return false;
                        }
                    }
                }

                /**
                 * Computes the depth of the tree.
                 * 
                 * @param curr_level the level of the calling node
                 * @return depth of the tree
                 */
                int max_level(int curr_level=0) {
                    int best_level = 1;
                    if (this->left || this->right) {
                        if (this->left) {
                            int left = this->left->max_level(curr_level + 1);
                            best_level += left;
                        }
                        else {
                            int right = this->right->max_level(curr_level + 1);
                            best_level += right;
                        }
                    }
                    return best_level;
                }

                /**
                 * Computes how many left descendents this node has.
                 * 
                 * @return number of left descendents
                 */
                int num_left() {
                    return 1 + this->left ? this->left->num_left() : 0;
                }

                int num_right() {
                    return 1 + this->right ? this->right->num_right() : 0;
                }
            }; 