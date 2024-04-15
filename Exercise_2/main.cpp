#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"

using namespace std;

int main()
{
    std::string inputFileName = "data.csv";
    size_t n=0;
    double S=0;
    double* w= nullptr;
    double* r= nullptr;

    if (!ImportData(inputFileName, n, S, w, r))
    {
        cerr<< "error: import failed"<< endl;
        return -1;
    }
    else
        cout << "Import successful: S= " << S<< ", n= " << n << ", w= "<< DataToString(n, w) << ", r=" << DataToString(n, w) << endl;

    double rateOfReturn = RateOfReturn(n, r, w);
    double FinalValue = (1+rateOfReturn)*S;

    cout << "Rate of return of the portfolio: " << rateOfReturn << endl;
    cout << "V: " << FinalValue << endl;
    cout << "outputFileName" << endl;

    string outputFileName = "./result.txt";
    if (!ExportResult(outputFileName, S, n, w, r, rateOfReturn, FinalValue))
    {
        cerr<< "error: import failed" << endl;
        return -1;
    }
    else
        cout<< "Export successful"<< endl;

    delete[] w;
    delete[] r;

    return 0;
}

