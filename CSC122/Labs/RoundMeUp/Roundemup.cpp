#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

typedef vector<short>::size_type vecSst;

vector<short> input(void);
void print(vector<short> vec);
short vecsum(vector<short> vec);
void lowtohighsort(vector<short>& vec);
double standardDeviation(vector<short> vec);
vector<short> fInput(void);

int main(void)
{
    vector<short> nums;
    ifstream data_file;
    string fname;
    short sum = 0,
        min,
        max,
        count;
    double  avg,
        sd;


    nums = fInput();
    sum = vecsum(nums);
    lowtohighsort(nums);
    min = nums.front();
    max = nums.back();
    count = nums.size();
    avg = static_cast<double>(sum) / static_cast<double>(count);
    sd = standardDeviation(nums);
    print(nums);


    cout << "\nSum:\t" << sum << "\nMin:\t"
        << min << "\nMax:\t" << max << "\nCount:\t"
        << count << "\nAvg:\t" << avg
        << "\nSD:\t" << sd << endl;

    return 0;
}

vector<short> input(void)
{
    vector<short> nums;
    short num;

    cin >> num;
    while (!cin.fail())
    {
        nums.push_back(num);
        cin >> num;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return nums;
}

vector<short> fInput(void)
{
    ifstream data_file;
    string fname;
    vector<short> nums;
    short num;
    //put this in main
    cout << "What is the name of the file?\t";
    getline(cin, fname);
    data_file.open(fname);

    while (data_file.fail())
    {
        cerr << "Not a vaild file name! Please try again!\n";
        getline(cin, fname);
        data_file.open(fname);
    }

    data_file >> num;
    while (!data_file.fail())
    {
        nums.push_back(num);
        data_file >> num;
    }
    data_file.clear();
    data_file.ignore(numeric_limits<streamsize>::max(), '\n');

    data_file.close();
    data_file.clear();

    return nums;

}

void print(vector<short> vec)
{
    for (vecSst i = 0; i != vec.size(); ++i)
    {
        cout << vec[i] << (i % 20 == 19 ? '\n' : ' ');
    }
    cout << endl;
}

short vecsum(vector<short> vec)
{
    short tot = 0;
    for (vecSst i = 0; i != vec.size(); ++i)
    {
        tot += vec[i];
    }

    return tot;
}

void lowtohighsort(vector<short>& vec)
{
    for (vecSst i = 0; i != vec.size() - 1; ++i)
    {
        for (vecSst i = 0; i != vec.size() - 1; ++i)
        {
           // print(vec);
            if (vec[i] >= vec[i + 1])
            {
                swap(vec[i], vec[i + 1]);
            }
        }
    }
}

short min(vector<short> vec)
{
    short min = vec[0];

    for (vecSst i = 0; i != vec.size(); ++i)
    {
        if (vec[i] < min)
        {
            min = vec[i];
        }
    }
    return min;
}

double standardDeviation(vector<short> vec)
{
    short total = 0;
    short count;
    long sqr;
    long totalsqr = 0;
    double variance;
    double placeholder;
    double avg;
    double sd;

    for (vecSst i = 0; i != vec.size(); ++i)
    {
        total += vec[i];
        sqr = pow(vec[i], 2);
        totalsqr += sqr;
        //cout << "\ni:\t" << i << "\nTotal:\t" << total << "\nSqr:\t" 
        //     << sqr << "\nTotalsqr:" << totalsqr << endl;
    }
    count = vec.size();
    avg = static_cast<double>(total) / static_cast<double>(count);
    cout << "avg:\t" << avg << endl;
    placeholder = pow(avg, 2);
    placeholder *= count;
    variance = (totalsqr - (pow(avg,2) * count)) 
               / (static_cast<double>(count) - 1);
    cout << "v:\t" << variance << endl;
    sd = sqrt(variance);
    cout << "sd:\t" << sd << endl;
    return sd;


}
