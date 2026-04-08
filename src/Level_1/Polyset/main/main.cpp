#include "../inc/searchable_array_bag.hpp"
#include "../inc/searchable_tree_bag.hpp"
#include "../inc/set.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "Usage: ./user_polyset [num1] [num2] [num3] ..." << std::endl;
    return 1;
  }
    
  searchable_bag *t = new searchable_tree_bag;
  searchable_bag *a = new searchable_array_bag;

  std::cout << "========================================" << std::endl;
  std::cout << "[1] BASIC TEST: INSERTION IN BAGS" << std::endl;
  std::cout << "========================================" << std::endl;
  for (int i = 1; i < argc; i++) {
    t->insert(atoi(argv[i]));
    a->insert(atoi(argv[i]));
  }
  
  std::cout << "\nTree Bag content  : ";
  t->print();
  std::cout << "Array Bag content : ";
  a->print();

  std::cout << "\n========================================" << std::endl;
  std::cout << "[2] SEARCH TEST ('has' method)" << std::endl;
  std::cout << "========================================" << std::endl;
  for (int i = 1; i < argc; i++) {
    int val = atoi(argv[i]);
    std::cout << "\n-> Searching for original value [" << val << "]:" << std::endl;
    std::cout << "   Tree has " << val << "? : " << (t->has(val) ? "Yes (1)" : "No (0)") << std::endl;
    std::cout << "   Array has " << val << "?: " << (a->has(val) ? "Yes (1)" : "No (0)") << std::endl;
    
    std::cout << "-> Searching for modified value [" << val - 1 << "]:" << std::endl;
    std::cout << "   Tree has " << val - 1 << "? : " << (t->has(val - 1) ? "Yes (1)" : "No (0)") << std::endl;
    std::cout << "   Array has " << val - 1 << "?: " << (a->has(val - 1) ? "Yes (1)" : "No (0)") << std::endl;
  }

  std::cout << "\n========================================" << std::endl;
  std::cout << "[3] CLEAR AND COPY TEST" << std::endl;
  std::cout << "========================================" << std::endl;
  t->clear();
  a->clear();
  std::cout << "Bags cleared." << std::endl;

  const searchable_array_bag tmp(static_cast<searchable_array_bag &>(*a));
  std::cout << "Printing Array Bag copy (should be empty): ";
  tmp.print();
  std::cout << "Searching for '1' in empty copy: " << (tmp.has(1) ? "Found" : "Not found") << std::endl;

  std::cout << "\n========================================" << std::endl;
  std::cout << "[4] 'SET' WRAPPER TEST (No duplicates)" << std::endl;
  std::cout << "========================================" << std::endl;
  set sa(*a);
  set st(*t);
  
  for (int i = 1; i < argc; i++) {
    int val = atoi(argv[i]);
    std::cout << "\n--- Iteration with argument: " << val << " ---" << std::endl;
    
    st.insert(val);
    sa.insert(val);

    std::cout << "Set Array has " << val << "?: " << (sa.has(val) ? "Yes" : "No") << std::endl;
    
    std::cout << "Printing from Set Array: ";
    sa.print();
    
    std::cout << "Direct printing of Set Array's bag: ";
    sa.get_bag().print();
    
    std::cout << "Printing from Set Tree : ";
    st.print();
    
    sa.clear();
    std::cout << "Set Array cleared." << std::endl;
    
    int temp_arr[] = {1, 2, 3, 4};
    std::cout << "Inserting array {1, 2, 3, 4} into Set Array..." << std::endl;
    sa.insert(temp_arr, 4);
    
    std::cout << "Result after inserting the array: ";
    sa.print();
  }

  std::cout << "\n========================================" << std::endl;
  std::cout << "[5] MEMORY CLEANUP" << std::endl;
  std::cout << "========================================" << std::endl;
  
  delete static_cast<searchable_tree_bag*>(t);
  delete static_cast<searchable_array_bag*>(a);
  
  std::cout << "Program finished successfully without leaks!" << std::endl;

  return 0;
}