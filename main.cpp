
#include <iostream>
#include <vector>
#include "histogram.h"
#include <curl/curl.h>
using namespace std;

int main(int argc, char* argv[])
{
    curl_global_init(CURL_GLOBAL_ALL);
    if (argc > 1)
    {
        CURL *curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            if (res!=0)
            {
                cerr << curl_easy_strerror(res);
                exit(1);
            }
        }

        return 0;
    }

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
