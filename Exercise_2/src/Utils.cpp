#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportData(const string& inputFileName,
                size_t& n,
                double& S,
                double*& w,
                double*& r)
{
    //Open file
    ifstream file;
    file.open(inputFileName);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    //get S (invested sum) and n (number of assets)
    string line;
    while (!file.eof())
    {
        getline(file, line);
        if (line[0] == 'S')
        {
            istringstream convertS(line.substr(2));
            convertS >> S;
        }
        else if (line[0] == 'n')
        {
            istringstream convertN(line.substr(2));
            convertN >> n;
            break;
        }
    }

    //ignore line w;r
    getline(file, line);

    //allocation new memory
    w = new double[n];
    r = new double[n];

    //get vectors
    for (unsigned int i=0; i<n; i++)
    {
        istringstream ConvertW;
        istringstream ConvertR;
        getline(file, line, ';');
        ConvertW.str(line);
        ConvertW >> w[i];
        getline(file, line);
        ConvertR.str(line);
        ConvertR >> r[i];
    }

    //Close File
    file.close();

    return true;
}

string DataToString(const size_t& n,
                    const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";

    toString << "]";

    return toString.str();
}

double RateOfReturn(const size_t& n,
                    const double* const& v1,
                    const double* const& v2)
{
    double RateOfReturn = 0;
    double sum=0;

    //weighted average is the dot product between w and r
    // the sum of the w(i)=1
    //v1 = r and v2 = w
    for (unsigned int i = 0; i < n; i++)
    {
        RateOfReturn += v1[i] * v2[i];
        sum += v2[i];
    }
    RateOfReturn = RateOfReturn/sum;

    return RateOfReturn;
}

bool ExportResult(const std::string& outputFileName,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn,
                  const double& finalValue)
{
    // Open File
    ofstream file;
    file.open(outputFileName);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << fixed << setprecision(2) << "S = " << S << ", n = " << n << endl;
    file << "w = [ ";
    for (unsigned int i = 0; i < n; i++)
        file << w[i] << " ";
    file << "]" << endl;

    file << "r = [ ";
    for (unsigned int i = 0; i < n; i++)
        file << r[i] << " ";
    file << "]" << endl;

    file << fixed << setprecision(4) << "Rate of return of the portfolio: " << rateOfReturn << endl;

    file << fixed << setprecision(2) << "V: " << finalValue << endl;

    // Close file
    file.close();

    return true;
}
