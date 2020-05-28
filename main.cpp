#include <windows.h>
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
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;
    DWORD mask_major = 0x0000ff;
    if ((info & 0x80000000) == 0) {
        DWORD version_major = version & mask_major;
        DWORD version_minor = version >> 8;
        DWORD build = platform;
        printf("Windows v%u.%u (build %u)\n", version_major, version_minor, build);
    }
    TCHAR  computer_name[MAX_COMPUTERNAME_LENGTH+1];
    DWORD  nSize = MAX_COMPUTERNAME_LENGTH+1;
    GetComputerName( computer_name, &nSize );
    cout << computer_name;
    return 0;
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
