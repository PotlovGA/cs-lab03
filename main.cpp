
#include <iostream>
#include <vector>
#include "histogram.h"

using namespace std;

vector<double>
input_numbers(istream& in, size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        in >> result[i];
    }
    return result;
}
Input
read_input(istream& in) {
    Input data;

    cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;

    cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    cerr << "Enter column count: ";
    size_t bin_count;
    cin >> bin_count;
    data.bin_count = bin_count;
    return data;
}


int main()
{
    const auto input = read_input(cin);
    /* size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    if (!number_count)
    {
        cerr << "Error: the array can't be empty";
        return 0;
    }
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(cin, number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    */
    double stroke_width;
    double stroke_gap;
    cerr << "Enter stroke-dasharray properties: ";
    cin >> stroke_width;
    cin >> stroke_gap;
    const auto bins = make_histogram(input);
    show_histogram_svg(bins, stroke_width, stroke_gap);
    return 0;
}
