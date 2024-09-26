#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib> //stod
#include <unistd.h> //optarg getopt

using namespace std;

double tanr(double n)
{
    double res = tan(n);
    return res;
}

double tand(double n)
{
    const float pi = 3.14;
    double res = tan(n * pi / 180);
    return res;
}

double cotr(double n)
{
    double res = 1/tan(n);
    return res;
}

double cotd(double n)
{
    const float pi = 3.14;
    double res = 1/tan(n * pi / 180);
    return res;
}

void help()
{
    cout << "Тангенс в радианах:   ./calc -o tanr <число>" << endl;
    cout << "Котангенс в радианах: ./calc -o cotr <число>" << endl;
    cout << "Тангенс в градусах:   ./calc -o tand <число>" << endl;
    cout << "Котангенс в градусах: ./calc -o cotd <число>" << endl;
    cout << "Справка:              ./calc -h" << endl;
}

int main(int argc, char **argv)
{
    int getopt(int argc, char * const argv[], const char *optstring);
    int opt;

    if(argc < 4) {
        help();
        return 0;
    }
    double x = stod(argv[3]);

    while((opt = getopt(argc, argv, "o:")) != -1) {
        switch(opt) {
        case 'o':
            string type = string(optarg);
            if (type == "tanr") {

                double result = tanr(x);
                cout << "Тангенс " << argv[3] << " рад. = " << result << endl;
                break;
            }
            if (type == "cotr") {
                double result = cotr(x);
                cout << "Котангенс " << argv[3] << " рад. = " << result << endl;
                break;
            }
            if (type == "tand") {
                double result = tand(x);
                cout << "Тангенс " << argv[3] << " град. = " << result << endl;
                break;
            }
            if (type == "cotd") {
                double result = cotd(x);
                cout << "Котангенс " << argv[3] << " град. = " << result << endl;
                break;
            }
        }
    }

    while((opt = getopt(argc, argv, "h")) != -1) {
        switch(opt) {
        case 'h':
            help();
            break;
        }
    }
    return 0;
}
