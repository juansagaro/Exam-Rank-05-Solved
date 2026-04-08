#include "set.hpp"
#include <iostream>
#include <cstddef>

set::set() : m_bag(NULL) {}

set::set(searchable_bag &b) : m_bag(&b) {}

set::set(const set &other) : m_bag(other.m_bag) {}

set &set::operator=(const set &other) {
    if (this != &other) {
        m_bag = other.m_bag;
    }
    return *this;
}

set::~set() {}

void set::insert(int item) {
    if (m_bag && !m_bag->has(item)) {
        m_bag->insert(item);
    }
}

void set::insert(int *items, int count) {
    for (int i = 0; i < count; i++) {
        this->insert(items[i]);
    }
}

void set::print() const {
    if (m_bag) m_bag->print();
}

void set::clear() {
    if (m_bag) m_bag->clear();
}

bool set::has(int item) const {
    if (m_bag) return m_bag->has(item);
    return false;
}

searchable_bag &set::get_bag() const {
    return *m_bag;
}
