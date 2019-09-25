//
// Created by Zachary Kurmas on 2019-09-25.
//

#include "catch.hpp"
#include "Polynomial.hpp"

using namespace cis263;

TEST_CASE("Max degree linear") {
  Polynomial<int> p("[4 1] [7 0]");
  REQUIRE(1 == p.maxDegree());
}

TEST_CASE("Max degree linear (backward)") {
  Polynomial<int> p("[7 0] [4 1]");
  REQUIRE(1 == p.maxDegree());
}

TEST_CASE("Are equal (identical)") {
  Polynomial<int> p1("[17 2] [31 1] [30 0]");
  Polynomial<int> p2("[17 2] [31 1] [30 0]");
  REQUIRE(p1 == p2);
  REQUIRE(!(p1 != p2));
}

TEST_CASE("evaluate linear") {
  Polynomial<int> p1("[3 1] [2 0]");

  SECTION("f(-10)") {
    REQUIRE(-28 == p1(-10));
  }

  SECTION("f(-1)") {
    REQUIRE(-1 == p1(-1));
  }

  SECTION("f(0)") {
    REQUIRE(2 == p1(0));
  }

  SECTION("f(1)") {
    REQUIRE(5 == p1(1));
  }

  SECTION("f(10)") {
    REQUIRE(32 == p1(10));
  }
}

TEST_CASE("Slow multiply x*x") {
  Polynomial<int> p1("[3 1]");
  Polynomial<int> p2("[2 1]");
  Polynomial<int> expected("[6 2]");

  SECTION("forward") {
    REQUIRE(expected == p1.slowMultiply(p2));
  }

  SECTION("backward") {
    REQUIRE(expected == p2.slowMultiply(p1));
  }
}

TEST_CASE("Fast multiply x*x") {
  Polynomial<int> p1("[3 1]");
  Polynomial<int> p2("[2 1]");
  Polynomial<int> expected("[6 2]");

  SECTION("forward") {
    REQUIRE(expected == p1 * p2);
  }

  SECTION("backward") {
    REQUIRE(expected == p2 * p1);
  }
}
