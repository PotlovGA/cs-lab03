
#include <iostream>
#include <vector>
#include "histogram.h"
#include <curl/curl.h>
using namespace std;
int main(int argc, char* argv[])
{
    if (argc > 1) {
        cerr << "argc = " << argc << "\n";
        for (int i = 0; i < argc; i++) {
            cerr << "argv[" << i << "] = " << argv[i] << "\n";
        }
        return 0;
    }
    curl_global_init(CURL_GLOBAL_ALL);
    const auto input = read_input(cin, true);
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
