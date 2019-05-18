#include <list>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <iostream>
# include <iterator> // std :: ostream_iterator <>

int main (int argc , char * argv [])
{
  std::list<unsigned int> int_list = {};
  for (int i = 0; i < 100; ++i) {
    int_list.push_back(rand() % 100);
  }

  // Store each present value once (duplicates not allowed)
  std::set<unsigned int> int_set;
  for (auto i : int_set) {
    // Since key and value in a set are the same, and the keys may not be repeated, values that occur multiple times in int_list will only be saved once in int_set.
    int_set.insert(i); 
  }
  std::cout << "There are " << int_set.size() << " different values in the list." << std::endl;


  for (int i = 0; i < 100; ++i) {
    if (int_set.find(i) == int_set.end() ) {
      std::cout << i << std::endl;
    }
  }

  // 3.3 
  // A map is an associative container, which allows us to assign a value to any type of key (this case, unsigned int);
  // A fixed sized array could also been used, but here we don't need to allocate memory for int that don't occur. We only save those in an int that exist.
  
  std::map<unsigned int, int> int_occurrences;
  for (auto i : int_list) {
    auto int_iterator = int_occurrences.find(i);

    // If the int is already in the map, take the times its there, else it is present until here 0 times.
    auto int_times = int_iterator != int_occurrences.end() ?
      int_iterator->second
      : 0;

    // If its there, change it, else, insert it 
    int_occurrences.insert_or_assign(i, ++int_times); 
  }


  for (int i = 0; i < 100; ++i) {
    auto int_iterator = int_occurrences.find(i);
    auto times = int_iterator != int_occurrences.end() ? int_iterator->second : 0;

    std::cout << i << " : " << times << std::endl;
  }

  // 3.10
  std::vector<unsigned int> copied_vector(int_list.size());
  std::copy(int_list.begin(), int_list.end(), copied_vector.begin());

  std::cout << "-----------------" << std::endl;
  
  for (auto el : copied_vector) {
     std::cout << el << " \t" << int_list.front() << std::endl;
     int_list.pop_front();
  }

  return 0;
}
