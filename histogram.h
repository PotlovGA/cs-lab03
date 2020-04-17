#pragma once
#include <vector>
#include <string>
using namespace std;
void find_minmax(vector<double> numbers, double& min, double& max);
vector<size_t> make_histogram(vector<double> numbers, size_t bin_count);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
void svg_rect(double x, double y, double width, double height, string stroke, string fill);
void show_histogram_svg(const vector<size_t>& bins);
