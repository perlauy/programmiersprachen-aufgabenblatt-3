# include <cstdlib> // std :: rand ()
# include <vector> // std :: vector <>
# include <list> // std :: list <>
# include <iostream> // std :: cout
# include <iterator> // std :: ostream_iterator <>
# include <algorithm> // std :: reverse , std :: generate


int main () {

  std::vector<int> v_0(10);
  
  for (auto& v : v_0) {
    v = std::rand();
  }
  
  // template< class InputIt, class OutputIt >
  // OutputIt copy( InputIt first, InputIt last, OutputIt d_first )
  std::copy(std::cbegin(v_0), std::cend(v_0),
    std::ostream_iterator<int>( std::cout , "\n"));
  
  // template< class InputIt >
  // list( InputIt first, InputIt last, const Allocator& alloc = Allocator() );
  std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));
  std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));

  // template< class BidirIt >
  // void reverse( BidirIt first, BidirIt last );
  std::reverse(std::begin(l_1), std::end(l_1));
  std::copy(std::cbegin(l_1), std::cend(l_1),
    std::ostream_iterator<int>(std::cout , "\n"));

  l_1.sort();
  std::copy(l_1.cbegin (), l_1.cend(),
    std::ostream_iterator<int>( std::cout, "\n"));

  // template< class ForwardIt, class Generator >
  // void generate( ForwardIt first, ForwardIt last, Generator g );
  std::generate(std::begin(v_0), std::end(v_0), std::rand);
  std::copy(v_0.crbegin(), v_0.crend(),
    std::ostream_iterator<int>(std::cout, "\n"));

  return 0;
}