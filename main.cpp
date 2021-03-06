
#include <iostream>
#include <vector>
#include "histogram.h"

using namespace std;
vector<double>
input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}


int main()
{
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    if (!number_count) {
        cerr << "Error: the array can't be empty";
        return 0;
    }
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    double stroke_width;
    double stroke_gap;
    cerr << "Enter stroke-dasharray properties: ";
    cin >> stroke_width;
    cin >> stroke_gap;
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg(bins, stroke_width, stroke_gap);
    return 0;
}
