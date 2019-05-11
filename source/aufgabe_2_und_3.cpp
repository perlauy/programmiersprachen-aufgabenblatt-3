#include <list>
#include <set>
#include <cmath>
#include <iostream>

int main (int argc , char * argv [])
{
  std::list<unsigned int> int_list = {};
  for (int i = 0; i < 100; ++i) {
    int_list.push_back(rand() % 100);
  }

  // Store each present value once (duplicates not allowed)
  std::set<unsigned int> int_set;
  for (auto i = int_list.begin(); i != int_list.end(); ++i) {
    int_set.insert(*i); 
  }
  std::cout << "There are " << int_set.size() << " different values in the list." << std::endl;


  for (int i = 0; i < 100; ++i) {
    if (int_set.find(i) == int_set.end() ) {
      std::cout << i << std::endl;
    }
  }

  return 0;
}
