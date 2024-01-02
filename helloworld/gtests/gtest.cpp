#include "../lib/lib.h"

#include <gtest/gtest.h>

namespace {

TEST(some_google_test_suite, version_test)
{
    ASSERT_TRUE(version() > 0);
}

} // namespace

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
