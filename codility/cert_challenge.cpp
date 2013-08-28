// you can also use includes, for example:
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int findInsideAngle(int, int, int);

struct AngleCount {
    string angleString;
    int count;
};

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int solution(const vector< vector<int> > &A, int P) {
    
    vector<AngleCount>  insideAngles; // [angle, count]
    int total_pairs = 0;
    
    for(vector< vector<int> >::const_iterator i = A.begin(); i != A.end(); ++i) {

        int hands[(*i).size()];
        ostringstream c;
        int hindex = 0;
        string handsString = "";
        vector<int> hvec (*i); 
        int handSum = 0;
        
        sort (hvec.begin(), hvec.end(), myobject);

        int lastHand;
        for(vector<int>::const_iterator j = hvec.begin(); j != hvec.end(); ++j) {
            
            if (j != hvec.begin()) {
                hands[hindex] = findInsideAngle(lastHand, *j, P);
                handSum += hands[hindex];
                hindex++;
            }
            lastHand = *j;
        }

        // add the last section
        hands[hindex] = P - handSum;
        
        // sort hands
        vector<int> myvector (hands, hands + sizeof(hands) / sizeof(int)); 
        if (hvec.size() > 2) {
            sort (myvector.begin(), myvector.begin()+4);  
        }
        
        for(vector<int>::iterator k = myvector.begin(); k != myvector.end(); ++k) {
            c << *k;
            handsString += c.str();
            //printf("%i ", *k);
        }
        //printf("\n");

        bool inlist = false;
        for(vector<AngleCount>::iterator m = insideAngles.begin(); m != insideAngles.end(); m++) {
            if ((*m).angleString == handsString) {
                (*m).count++;
                inlist = true;
                break;
            }
        }

        if (!inlist) {
            AngleCount a;
            a.angleString = handsString;
            a.count = 1;
            insideAngles.push_back(a);
        }


    }

    for(vector<AngleCount>::iterator i = insideAngles.begin(); i != insideAngles.end(); i++) {
            if ((*i).count > 1) {
                total_pairs += ((*i).count * ((*i).count-1)) /2;
            }
    }
    
    return total_pairs;
}

int findInsideAngle(int a, int b, int p) {

    /*int angle;

    
    if ((float)(abs(a-b)) <= (float)(p/2.0)) {
    	angle = abs(a-b);
    } else {
    	angle = p - abs(a-b);
    }
    

    return angle;*/

    return b-a;
}

void test1();
void test2();

int main() {

    test1();
    test2();

}

void test1() {

    int p = 24;

    vector< vector<int> > vec;

    int myints[] = {7, 16, 20, 24};
    vector<int> myhands (myints, myints + sizeof(myints) / sizeof(int) );
    vec.push_back(myhands);

    int myints2[] = {5, 14, 18, 22};
    vector<int> myhands2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );
    vec.push_back(myhands2);

    int myints3[] = {6, 7, 10, 15};
    vector<int> myhands3 (myints3, myints3 + sizeof(myints3) / sizeof(int) );
    vec.push_back(myhands3);

    int myints4[] = {6, 7, 10, 15};
    vector<int> myhands4 (myints4, myints4 + sizeof(myints4) / sizeof(int) );
    vec.push_back(myhands4);        

    int myints5[] = {3, 7, 11, 18};
    vector<int> myhands5 (myints5, myints5 + sizeof(myints5) / sizeof(int) );
    vec.push_back(myhands5);   

    int myints6[] = {4, 8, 12, 19};
    vector<int> myhands6 (myints6, myints6 + sizeof(myints6) / sizeof(int) );
    vec.push_back(myhands6);   

    printf("solution should be 7, got: %i\n", solution(vec, p));

}

void test2() {
    int p = 27;

    vector< vector<int> > vec;

    int myints[] = {7, 9, 10, 17};
    vector<int> myhands (myints, myints + sizeof(myints) / sizeof(int) );
    vec.push_back(myhands);

    int myints2[] = {13, 18, 19, 26};
    vector<int> myhands2 (myints2, myints2 + sizeof(myints2) / sizeof(int) );
    vec.push_back(myhands2);

    int myints3[] = {13, 15, 16, 23};
    vector<int> myhands3 (myints3, myints3 + sizeof(myints3) / sizeof(int) );
    vec.push_back(myhands3);

    int myints4[] = {10, 15, 16, 23};
    vector<int> myhands4 (myints4, myints4 + sizeof(myints4) / sizeof(int) );
    vec.push_back(myhands4);        

    int myints5[] = {2, 16, 21, 22};
    vector<int> myhands5 (myints5, myints5 + sizeof(myints5) / sizeof(int) );
    vec.push_back(myhands5);   

    int myints6[] = {11, 13, 14, 21};
    vector<int> myhands6 (myints6, myints6 + sizeof(myints6) / sizeof(int) );
    vec.push_back(myhands6);   

    printf("solution should be 6, got: %i\n", solution(vec, p));

}