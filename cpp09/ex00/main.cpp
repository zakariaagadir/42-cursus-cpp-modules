#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib> // for exit()
#include <iomanip> // for setprecision

bool isValidDate(const std::string& date) {
    if (date.size() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    for (size_t i = 0; i < date.size(); i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }
    return true;
}

bool stringToFloat(const std::string& str, float &value) {
    std::stringstream ss(str);
    ss >> value;
    if (ss.fail() || !ss.eof()) return false;
    return true;
}

std::map<std::string, float> loadDatabase(const std::string& filename) {
    std::map<std::string, float> db;
    std::ifstream file;

    file.open(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string date, price_str;
        std::stringstream ss(line);

        if (!std::getline(ss, date, ',')) continue;
        if (!std::getline(ss, price_str)) continue;

        float price;
        if (!stringToFloat(price_str, price))
            continue;

        db[date] = price;
    }
    return db;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream infile;
    infile.open(argv[1]);
    if (!infile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, float> btc_prices = loadDatabase("data.csv");

    std::string line;
    while (std::getline(infile, line)) {
        if (line.empty())
            continue;

        size_t sep = line.find('|');
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string value_str = line.substr(sep + 1);

        while (date.size() && isspace(date[0])) date.erase(0, 1);
        while (date.size() && isspace(date[date.size()-1])) date.erase(date.size()-1);

        while (value_str.size() && isspace(value_str[0])) value_str.erase(0, 1);
        while (value_str.size() && isspace(value_str[value_str.size()-1])) value_str.erase(value_str.size()-1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        if (!stringToFloat(value_str, value)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value <= 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        if (btc_prices.find(date) == btc_prices.end()) {
            std::cerr << "Error: date not found => " << date << std::endl;
            continue;
        }

        float result = value * btc_prices[date];

        std::cout << date << " => " << value
                  << " = "
                  << result << std::endl;
    }

    return (0);
}
