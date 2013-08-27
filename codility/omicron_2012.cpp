// Omicron 2012
// http://blog.codility.com/2012/03/omicron-2012-codility-programming.html
// currently scores a 10 (fails timing and large inputs)

/*
    The Fibonacci sequence is defined by the following recursive formula:
    F(0) = 0 
    F(1) = 1 
    F(N) = F(N-1) + F(N-2) for N = 2 

    Write a function:
    int solution(int N, int M);
    that, given two non-negative integers N and M, returns a remainder of F(N^M) modulo 10,000,103. 
    
    Note: 10,000,103 is a prime number.
    
    For example, given N = 2 and M = 3, the function should return 21, since 2^3 = 8 and F(8) = 21.
    Assume that: N and M are integers within the range [0..10,000,000].
    
    Complexity:
    expected worst-case time complexity is O(log(N*M));
    expected worst-case space complexity is O(1).
    
*/

#include <stdio.h>
#include <math.h>

using namespace std;

int solution(int, int);
int fib(int);
void test1();
void ftest();

int main() {
    test1();
    ftest();
}
int P = 10000103;
int solution(int N, int M) {
    int arg = (int)pow(N,M);
    int fres = fib(arg);
    return fres%P;
}

int fib(int K) {

    if (K == 0)
        return 0;
        
    if (K == 1)
        return 1;
        
    return fib(K-1) + fib(K-2);
    
}

void ftest() {
    int answer = fib(0);
    printf("ftest1: Answer is %i and should be 0\n", answer);
    int answer2 = fib(1);
    printf("ftest1: Answer is %i and should be 1\n", answer2);
    int answer3 = fib(2);
    printf("ftest1: Answer is %i and should be 3\n", answer3);
    int answer4 = fib(5);
    printf("ftest1: Answer is %i and should be 15\n", answer4);
    int answer5 = fib(8);
    printf("ftest1: Answer is %i and should be 21\n", answer5);
}



void test1() {
    int answer = solution(2,3);
    printf("test1: Answer is %i and should be 21\n", answer);
}
