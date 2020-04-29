#include "histogram.h"
#include <iostream>
using namespace std;
void
find_minmax(vector<double> numbers, double& min, double& max)
{
    if (numbers.size()) {
    min = numbers[0];
    max = numbers[0];
    for (double number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
    }
    }
}
vector<size_t> make_histogram(vector<double> numbers, size_t bin_count)
{
    double min = numbers[0];
    double max = numbers[0];
    find_minmax(numbers, min, max);
    vector<size_t> bins(bin_count);
    for (double number : numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * bin_count);
        if (bin == bin_count)
        {
            bin--;
        }
        bins[bin]++;
    }
    return bins;
}

void
svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end()
{
    cout << "</svg>\n";
}
void
svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'> " << text << " </text>";
}
void svg_rect(double x, double y, double width, double height, string stroke = "black", string fill = "black")
{
    cout << "<rect x = '"<< x << "' y = '" << y << "' width = '" << width << " ' height = '" << height << "' stroke = '" << stroke << "' fill = ' " << fill << "'/>";
}
void
show_histogram_svg(const vector<size_t>& bins)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    const auto MAX_WIDTH = IMAGE_WIDTH - TEXT_WIDTH;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    size_t max_width = BLOCK_WIDTH*bins[0];
    for (size_t bin : bins) {
        if (BLOCK_WIDTH*bin > max_width) {
        max_width = BLOCK_WIDTH*bin;
        }
    }
    if (max_width > MAX_WIDTH) {
    const double scaling_factor = (double)MAX_WIDTH / max_width;
    for (size_t bin : bins)
        {
        const double bin_width = BLOCK_WIDTH * bin * scaling_factor;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "blue", "#aaffaa");
        top += BIN_HEIGHT;
    }
    }
    else {
    for (size_t bin : bins)
    {
        const double bin_width = BLOCK_WIDTH * bin;
        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "blue", "#aaffaa");
        top += BIN_HEIGHT;
    }
    }
    svg_end();
}
