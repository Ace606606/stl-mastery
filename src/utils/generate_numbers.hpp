#include <vector>
#include <random>
#include <type_traits>

namespace stl::utils
{

template< typename T >
typename std::enable_if_t< std::is_fundamental_v< T >, void >
generate_random_numbers(
     std::vector< T >& vec, const size_t count, const unsigned seed = 1 )
{
     std::mt19937 gen( seed );

     vec.reserve( vec.size() + count );

     if constexpr ( std::is_integral_v< T > )
     {
          std::uniform_int_distribution<T> dist(1, 100);
          for( size_t i{}; i < count; ++i )
          {
               T random_number = dist(gen);
               vec.push_back( random_number );
          }
     }
     else 
     {
          std::uniform_real_distribution<T> dist(1.0, 100.0);
          for( size_t i{}; i < count; ++i )
          {
               T random_number = dist(gen);
               vec.push_back( random_number );
          }
     }
}

} // namespace stl::utils