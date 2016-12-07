#include "factorial.hh"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


SCENARIO("factorials can be count for positive numbers", "[factorial]")
{
    GIVEN("a positive number")
    {
        WHEN("it is 0")
        {
            int result = factorial(0);

            THEN("the result should be 1")
            {
                REQUIRE(result == 1);
            }
        }

        WHEN("it is 1")
        {
            int result = factorial(1);

            THEN("the result should be 1")
            {
                REQUIRE(result == 1);
            }
        }

        WHEN("it is 2")
        {
            int result = factorial(2);

            THEN("the result should be 2")
            {
                REQUIRE(result == 2);
            }
        }

        WHEN("it is 3")
        {
            int result = factorial(3);

            THEN("the result should be 6")
            {
                REQUIRE(result == 6);
            }
        }

        WHEN("it is 4")
        {
            int result = factorial(4);

            THEN("the result should be 24")
            {
                REQUIRE(result == 24);
            }
        }

        WHEN("it is 10")
        {
            int result = factorial(10);

            THEN("result should be 3 628 800")
            {
                REQUIRE(result == 3628800);
            }
        }

        WHEN("it is 12")
        {
            int result = factorial(12);

            THEN("result should be 479 001 600")
            {
                REQUIRE(result == 479001600);
            }
        }
    }
}

