// XI 2012
// http://blog.codility.com/2012/02/xi-2012-codility-programming.html
// Solution is currently 40% (missing timing requirements)

#include <string>
#include <bitset>
#include <limits>
#include <iostream>
#include <vector>

using namespace std;

int solution(const string &S, const string &T, int K);
void test1();
void test2();
void test3();

int main() {

    test1();
    test3();
    test2();
    
    return 0;
    
}

int solution(const string &S, const string &T, int K) {
    
    unsigned long start = bitset<numeric_limits<unsigned long>::digits>((string)S).to_ulong();
    unsigned long end = bitset<numeric_limits<unsigned long>::digits>((string)T).to_ulong();
    
    int sparseCount = 0;
    for (int j = (int)start; j <= (int)end; j++) {
    
        bitset<numeric_limits<unsigned long>::digits> binNumber (j);
        string bitString = binNumber.to_string<char,char_traits<char>,allocator<char> >();

        int maxZeroes = 0;
        if (j < 4) {maxZeroes = 1;}
        if (j < 8) {maxZeroes = 2;}
        if (j < 16) {maxZeroes = 3;}
        if (j < 32) {maxZeroes = 4;}
        if (j < 64) {maxZeroes = 5;}
        if (j < 128) {maxZeroes = 6;}
        if (j < 256) {maxZeroes = 7;}
        if (j < 512) {maxZeroes = 8;}
        if (j < 1024) {maxZeroes = 9;}
        if (j < 2048) {maxZeroes = 10;}
        if (j < 4096) {maxZeroes = 11;}
        if (j < 8192) {maxZeroes = 12;}
        if (j < 16384) {maxZeroes = 13;}
        if (j < 32768) {maxZeroes = 14;}
        if (j < 65536) {maxZeroes = 15;}
        if (j < 131072) {maxZeroes = 16;}
        if (j < 262144) {maxZeroes = 17;}
        if (j < 524288) {maxZeroes = 18;}
  
        int zeroCount = 0;
        bool padEnd = false;
        
        for(string::iterator m = bitString.begin(); m != bitString.end(); ++m) {

        const char* one = "1";
        const char* zero = "0";
        const char digit = *m;
        
        // start on left, move right 
            if (digit == *one) {
              if (!padEnd) { padEnd = true; }
              else {
                if (zeroCount < maxZeroes) {
                  maxZeroes = zeroCount;
                }
                zeroCount = 0;
              }
            } else if ((digit == *zero) && padEnd) { 
                zeroCount++;
            }
        }
        
        if (maxZeroes >= K) {sparseCount++;}
        
    }
    
    return sparseCount;
    
}

void test1() {
    int answer = solution("101","1111",2);
    printf("test1 should be 2, got: %i\n", answer);
}

void test2() {
    int answer = solution("101","1111",2);
    //printf("test1 should be 2, got: %i\n", answer);
}

void test3() {
    int answer = solution("101","1111",2);
    //printf("test1 should be 2, got: %i\n", answer);
}
