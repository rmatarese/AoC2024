#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

void parseFile(const std::string& filename, std::vector<int>& col1, std::vector<int>& col2) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int num1, num2;
        if (iss >> num1 >> num2) {
            col1.push_back(num1);
            col2.push_back(num2);
        }
    }

    file.close();
}

int main() {
    std::vector<int> col1;
    std::vector<int> col2;




    std::string filename = "../input.txt";
    try {
        parseFile(filename, col1, col2);
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }


    //ceci étant fait, on peut commencer à s'amuser

    std::sort(col1.begin(), col1.end());
    std::sort(col2.begin(), col2.end());
    int totDist=0;
    for (const auto& num : col1) {
        int appearInC2=0;
        for (const auto& num2 : col2) {
            if (num == num2) {
                appearInC2++;
            }
        }
        totDist += appearInC2*num;
    }
    std::cout << totDist << "\n";

    return 0;
}