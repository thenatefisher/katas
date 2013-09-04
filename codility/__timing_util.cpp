#include <vector>
#include <algorithm>

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <sys/time.h>
#include <ctime>

using namespace std;

typedef unsigned long long uint64;

uint64 GetTimeMs64();
int test();
void resetInput();
vector<int> F;
const int INPUT_SIZE = (int)pow(10,7);

struct myclass {
  bool operator() (int i, int j) { return (i < j); }
} myobject;

int main () {

    uint64 start;
    int i, runs, avg, diff, total; 
    runs = 20; total = 0;
    
    for (i = 1; i <= runs; i++) {
    
        resetInput();
        
        start = GetTimeMs64();
        
        test(); // run test code
        
        diff = (GetTimeMs64() - start);
        
        printf("Run %i time: \t %i \n", i, diff);
        
        total += diff;
    
    }    
    
    avg = total / runs;
    
    printf("===============================\n");
    printf("AVERAGE TIME: \t %i \n\n", avg);
    
    return 0;

}

void resetInput() {

    F.clear();

    for(double i = 0; i < INPUT_SIZE; i++) {
    
      int iSecret;

      /* initialize random seed: */
      srand (time(NULL));

      /* generate secret number between 1 and 100000: */
      iSecret = rand() % 100000 + 1;
  
      F.push_back(iSecret);
        
    }
    
}

int test() {

    vector<int> observed;
    
    for(vector<int>::iterator i = F.begin(); i != F.end(); ++i) {
        
        if (find(observed.begin(), observed.end(), *i) != observed.end()) {

            observed.push_back(*i);
            
        }
    
    }
    
    return observed.size();

}

uint64 GetTimeMs64() {

    struct timeval tv;

    gettimeofday(&tv, NULL);

    uint64 ret = tv.tv_usec;
    
    /* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
    ret /= 1000;

    /* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
    ret += (tv.tv_sec * 1000);

    return ret;

}
