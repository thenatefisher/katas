#include <vector>
#include <stdio.h>

using namespace std;

vector<int> F;
int solution(const vector<int> &A);
double upper(const vector<int> &A, int);

int main() {
	
	F.push_back(-7);
	F.push_back(1);
	F.push_back(5);
	F.push_back(2);
	F.push_back(-4);
	F.push_back(3);
	F.push_back(0);


	int answer = solution(F);
	printf("%i\n", answer);

}


int solution(const vector<int> &A) {

	int retval = -1;

	if (A.size() == 0) return retval;

	double lower = 0;

	for(int k = 0; k < A.size(); k++) {
		lower += A.at(k);
		if (lower == upper(A, k)) {
			retval = k;
			break;
		}
	}

	return retval;

}

double upper(const vector<int> &A, int k) {

	double sum = 0;
	for(int j = k; j < A.size(); j++) {
		sum += A.at(j);
	}
	return sum;
}