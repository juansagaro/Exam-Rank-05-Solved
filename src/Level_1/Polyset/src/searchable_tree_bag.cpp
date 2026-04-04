#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag() : tree_bag(), searchable_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other) 
    : bag(), tree_bag(other), searchable_bag(other) {}

searchable_tree_bag &searchable_tree_bag::operator=(const searchable_tree_bag &other) {
    if (this != &other) {
        tree_bag::operator=(other);
    }
    return *this;
}

searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int item) const {
    node *current = tree; // 'tree' es protected en tree_bag

    while (current != nullptr) {
        if (item == current->value) {
            return true;
        } else if (item < current->value) {
            current = current->l; // Menor, nos vamos a la izquierda
        } else {
            current = current->r; // Mayor, nos vamos a la derecha
        }
    }
    return false;
}
