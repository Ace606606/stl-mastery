#include "utils/generate_numbers.hpp"

#include <new>
#include <iostream>
#include <vector>

using namespace stl::utils;

int main()
{
     std::vector< int > vec;
     std::cout << "Size = " << vec.size() << " Capacity = " << vec.capacity() << '\n';
     vec.reserve( 3 );
     vec.push_back( 1 );
     vec.emplace_back( 2 );
     std::cout << "Size = " << vec.size() << " Capacity = " << vec.capacity() << '\n';

     try
     {
          generate_random_numbers< int >( vec, 5, 1 );
          std::cout << "After generate_random_numbers:\t" << "Size = " << vec.size() << " Capacity = " << vec.capacity()
                    << '\n';

          std::cout << "Items vector:" << '\n';
          for( const auto& item : vec )
          {
               std::cout << item << '\n';
          }
     }
     catch( std::bad_alloc& e )
     {
          std::cerr << "Error: allocation memory for vector";
     }
     return 0;
}
