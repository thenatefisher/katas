// Kappa 2011
#include <vector>
#include <stdio.h>

using namespace std;
double fac(int);
int solution(const vector<int> &T, const vector<int> &D);
vector<int> F;

int main() {

    vector<int> t;
    vector<int> d;
    
    t.push_back(600);
    t.push_back(200);
    t.push_back(300);
    
    d.push_back(60);
    d.push_back(20);
    d.push_back(10);

    int answer = solution(t, d);
    printf("%i\n", answer);

}

int solution(const vector<int> &T, const vector<int> &D) {
    
    F.push_back(1);
    unsigned long total = 1;
    
    for(int p = 0; p < T.size(); p++) {
        int n = T.at(p);
        int k = D.at(p);
        total *= (fac(n) / (fac(k) * fac(n-k)));
    }
    
    if (total > 1410000016) {
        return (int)(total % 1410000017);
    } else {
        return (int)total;
    }
    
}

double fac(int k) {

    if (k == 0)
        return 1;

    int cache_index = F.size();
    
    while (cache_index <= k) {
        F.push_back( cache_index * fac(cache_index-1) );
        cache_index++;
    }

    return F.at(k);

}

