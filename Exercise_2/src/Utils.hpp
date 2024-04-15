#pragma once
#include "iostream"

/*ImportData reads the input data from file inputFileName
 * n: number of assets
 * S:invested sum
 * w: vector where the component w(i) is the fraction of S in the i-th asset
 * r: vector where the component r(i) is the rate of return of the i-th asset
 * return the result of the reading, true is success, false is error
*/
bool ImportData(const std::string& inputFileName,
                size_t& n,
                double& S,
                double*& w,
                double*& r);

/*export a vector in a string
 * n: size of the vector
 * v: vector
 * return a string
 */
std::string DataToString(const size_t& n,
                      const double* const& v);

/* RateOfReturn computes the rate of return of the portfolio (weighted average)
 * n: size of the vectors
 * v1: the first vector
 * v2: the second vector
 * return the weighted average
 */

double RateOfReturn(const size_t& n,
                    const double* const& v1,
                    const double* const& v2);

/* ExportResult export the result obtained in file
 * outputFilePath: path name of the output file
 * n: number of assets
 * S:invested sum
 * w: vector where the component w(i) is the fraction of S in the i-th asset
 * r: vector where the component r(i) is the rate of return of the i-th asset
 * rateOfReturn: Rate of return of the portfolio
 * FinalValue: the final value of the whole portfolio
 * return the result of the export, true is success, false is error
 */

bool ExportResult(const std::string& outputFileName,
                  const double& S,
                  const size_t& n,
                  const double* const& w,
                  const double* const& r,
                  const double& rateOfReturn,
                  const double& finalValue);

