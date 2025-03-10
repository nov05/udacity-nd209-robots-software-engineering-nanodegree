#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// double w[] = { 0.6, 1.2, 2.4, 0.6, 1.2 }; //You can also change this to a vector
vector<double> w = {0.6, 1.2, 2.4, 0.6, 1.2};

// TODO: Define a  ComputeProb function and compute the Probabilities
vector<double> ComputeProb(vector<double> w)
{
    vector<double> p;

    // Compute the sum of all elements in the vector
    double sum = accumulate(w.begin(), w.end(), 0.0);

    // Normalize each element by dividing by the sum
    for (double value : w) {
        p.push_back(value / sum);
    }

    return p;
}

int main()
{
    // TODO: Print Probabilites each on a single line:
    // P1=Value
    //:
    // P5=Value
    vector<double> p = ComputeProb(w);
    for (int i = 0; i < p.size(); ++i) {
        cout << "P" << i+1 << "=" << p[i] << endl;
    }
    return 0;
}
