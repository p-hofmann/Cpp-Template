/**
 * Created by Peter Hofmann on 07.01.19.
 */

#define CATCH_CONFIG_MAIN  // Tells Catch to provide a main()
#define CHECK_MESSAGE(cond, msg) do { INFO(msg); CHECK(cond); } while((void)0, 0)
#define REQUIRE_MESSAGE(cond, msg) do { INFO(msg); REQUIRE(cond); } while((void)0, 0)

#include <string>
#include "catch.hpp"
#include "dummymain.h"
#include "filesystem.h"

using namespace dummy;
using namespace std;

/*!
 * Testing getClassName
 */
TEST_CASE("Test getClassName", "[DummyMain]")
{
    string testValue = "DummyMain";
    DummyMain dummy;
    REQUIRE_MESSAGE(dummy.getClassName() == testValue, "Bad class name");
}

TEST_CASE("Test OS", "[DummyMain]")
{
    DummyMain dummy;
    REQUIRE_MESSAGE(dummy.getOS() != UNKNOWN, "Bad OS");
}

TEST_CASE("Test filesystem", "[filesystem]")
{
    filesystem::path cwd = filesystem::current_path();
    INFO(cwd);
}

TEST_CASE("Test toString", "[DummyMain]")
{
    DummyMain dummy;
    string testValue = dummy.toString();
    REQUIRE_MESSAGE(testValue.empty(), "toString returned empty string" << testValue);
    INFO(testValue);
}
