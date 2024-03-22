#include <iostream>
#include <fstream>
#include <iomanip>

double function_map(double value)
{
    double min_start = 1;
    double min_end = -1;
    double max_start = 5;
    double max_end = 2;

    double fract = (max_end - min_end) / (max_start - min_start);

    double res = min_end + (value - min_start) * fract;

    return res;
}


int main()
{
    std::string fileName = "data.csv";
    std::ifstream ifstr(fileName);
    std::string fileOutput = "result.csv";
    std::ofstream ofstr(fileOutput);

    if(ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    if(ofstr.fail())
    {
        std::cerr << "Impossible to open the file" << std::endl;
        return 2;
    }

    ofstr << "# N Mean" << std::endl;

    double val = 0;
    int countVal = 0;
    double sumValue = 0;

    while(ifstr >> val)
    {
        double mapValue = function_map(val);
        countVal++;
        sumValue += mapValue;
        double mean = sumValue / countVal;
        ofstr << std::scientific << std::setprecision(16) <<  countVal << " " << mean << "\n";
    }

    ifstr.close();
    ofstr.close();

    return 0;
}
