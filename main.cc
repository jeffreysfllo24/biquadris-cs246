#include <iostream>
#include <string>

#include "biquadris.h"

using namespace std;

int main() {
    Biquadris bq;

    std::string s;
    while(cin >> s) {
        bq.interpretCommand(s);
    }
}