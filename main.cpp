
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
    return read_input(buffer, false);
}

int
main(int argc, char* argv[]) {
    Input input;
    if (argc > 1) {
        input = download(argv[1]);
    } else {
        input = read_input(cin, true);
    }
    const auto bins = make_histogram(input);
    show_histogram_svg(bins, input.stroke_width, input.stroke_gap);
    return 0;
}
