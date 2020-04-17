#include "../histogram.h"

#include <cassert>
const double MAX = 0;
const double MIN = 0;

void
test_positive() {
    double min = MIN;
    double max = MAX;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}
void test_negative() {
    double min = MIN;
    double max = MAX;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}
void test_equal() {
    double min = MIN;
    double max = MAX;
    find_minmax({1, 1, 1}, min, max);
    assert (min == 1);
    assert (max == 1);
}
void test_sole() {
    double min = MIN;
    double max = MAX;
    find_minmax({1}, min, max);
    assert (min == 1);
    assert (max == 1);
}
void test_null() {
    double min = MIN;
    double max = MAX;
    find_minmax({}, min, max);
    assert (min == MIN);
    assert (max == MAX);
}
int
main() {
    test_positive();
    test_negative();
    test_equal();
    test_sole();
    test_null();
}
