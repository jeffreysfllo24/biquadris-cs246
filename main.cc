#include <iostream>
#include <string>

#include "biquadris.h"

using namespace std;

int main(int argc,char * argv[]) {
    bool isGraphics = true;
    int seed = 1;
    string sequence1 = "sequence1.txt";
    string sequence2 = "sequence2.txt";
    int startLevel = 0;
    for(int i = 0; i < argc; ++i){
        string input = argv[i];
        if(input == "-text"){
            isGraphics = false;
        }else if (input == "-seed"){
            seed = stoi(argv[i+1]);
        }else if (input == "-scriptfile1"){
            sequence1 = argv[i+1];
        }else if (input == "-scriptfile2"){
            sequence2 = argv[i+1];
        }else if (input == "-startlevel"){
            startLevel = stoi(argv[i + 1]);
        }
    }
    Biquadris bq(sequence1,sequence2,isGraphics);
    bq.run(isGraphics,seed,sequence1,sequence2,startLevel);
}
