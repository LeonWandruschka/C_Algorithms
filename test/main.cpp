#include <catch2/catch_test_macros.hpp>

#include "recursiveFib.h"
#include "dynamicFib.h"
#include "patternSearch.h"
#include "stack.h"
#include "queue.h"
#include "doublyLinkedList.h"


TEST_CASE( "Sample test", "[sample_test]" )
{
    REQUIRE( 1 == 1 );
    REQUIRE( 2 == 2 );
    REQUIRE( 6 == 6 );
}


TEST_CASE( "Recursive Fibonacci", "[recursive_fibonacci]" )
{
  REQUIRE(RecFib(0) == 1);
  REQUIRE(RecFib(1) == 1);
  REQUIRE(RecFib(5) == 5);
  REQUIRE(RecFib(9) == 34);
}


TEST_CASE( "Dynamic Fibonacci", "[dynamic_fibonacci]" )
{
  REQUIRE(DynFib(0) == 1);
  REQUIRE(DynFib(1) == 1);
  REQUIRE(DynFib(5) == 5);
  REQUIRE(DynFib(9) == 34);
}
