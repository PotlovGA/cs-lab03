
#include <iostream>
#include <vector>
#include "histogram.h"
#include <curl/curl.h>
#include <sstream>
#include <string>
using namespace std;
size_t
write_data(void* item, size_t item_size, size_t item_count, void* ctx) {
    size_t data_size;
    data_size = item_count * item_size;
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    const char* items = reinterpret_cast<const char*>(item);
    buffer->write(items, data_size);
    return data_size;
}
Input
download(const string& address) {
    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
        if(curl)
        {
            CURLcode res;
            curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
            res = curl_easy_perform(curl);

            if (res!=0)
            {
                cerr << curl_easy_strerror(res);
                exit(1);
            }
        }
     curl_easy_cleanup(curl);
    return read_input(buffer, true);
}

int
main(int argc, char* argv[]) {
    Input input;
    if (argc > 1) {
        input = download(argv[1]);
    } else {
        input = read_input(cin, true);
    }


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
