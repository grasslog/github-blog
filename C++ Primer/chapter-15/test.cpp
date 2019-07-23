#include <vector>
#include <iostream>
#include <algorithm>
#include "Quote.h"

int main(int argc, char **argv) 
{
    Quote b1("LOLI",128);
    bulk_quote b2(string("LOLII"), 128.0, 10, 0.7);
    print_total(cout, b1, 10);
    print_total(cout, b2, 10);

    return 0;
}