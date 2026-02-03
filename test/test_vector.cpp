#include <gtest/gtest.h>
#include <vector>
#include "utils/generate_numbers.hpp"

using namespace stl::utils;

TEST( GenerateNumberTest, CorrectSizeAfterGeneration )
{
     std::vector< int > vec;
     const size_t count = 10;

     generate_random_numbers( vec, count );

     EXPECT_EQ( vec.size(), count );
}

TEST( GenerateNumberTest, DeterministicResultWithSameSeed )
{
     std::vector< int > vec1;
     std::vector< int > vec2;
     const size_t count = 5;
     const unsigned seed = 42;

     generate_random_numbers( vec1, count, seed );
     generate_random_numbers( vec2, count, seed );

     EXPECT_EQ( vec1, vec2 );
}

TEST( GenerateNumbersTest, SupportsDoubleTypes )
{
     std::vector< double > vec;
     const size_t count = 5;
     const unsigned seed = 1;
     generate_random_numbers( vec, count, seed );

     ASSERT_EQ( vec.size(), 5 );
     for( const auto& val : vec )
     {
          EXPECT_GE( val, 1.0 );
          EXPECT_LE( val, 100.0 );
     }
}