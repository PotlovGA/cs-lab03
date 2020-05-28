#pragma once
#include <vector>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;
vector<double>input_numbers(size_t count);
string make_info_text();
void find_minmax(vector<double> numbers, double& min, double& max);
vector<size_t> make_histogram(vector<double> numbers, size_t bin_count);
void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text);
int scaling_needed(const vector<size_t>& bins, const auto BLOCK_WIDTH, const auto MAX_WIDTH);
double max_width (const vector<size_t>&bins, const auto BLOCK_WIDTH);
void svg_rect(double x, double y, double width, double height, string stroke, string fill);
void svg_line(double x2,  double y, double stroke_width, double stroke_gap);
void show_histogram_svg(const vector<size_t>& bins, const double stroke_width, const double stroke_gap);
