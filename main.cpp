#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int extractMap(std::vector<std::string> &map);
int displayMap(std::vector<std::string> &map);

int main() {

    std::vector<std::string> map; // The map

    if (extractMap(map) != 0) return -1;

    displayMap(map);

    return 0;
}

int extractMap(std::vector<std::string> &map) {
    if (std::ifstream fileBoard("board.txt"); fileBoard.is_open()) {
        std::string line;
        while (getline(fileBoard, line)) {
            map.push_back(line);
        }
    } else {
        std::cout << "The file \"board.txt\" is missing." << std::endl;
        return -1;
    }

    int error = 0;
    if (map.empty() || map.size() != 25) error = 1;
    for (const auto &line : map) {
        if (line.size() != 25) {
            error = 1;
        }
    }
    if (error) {
        std::cout << "The board must be 25*25 with the letter \'~\' for water and \'#\' for your ships." << std::endl;
        return -1;
    }

    return 0;
}

int displayMap(std::vector<std::string> &map) {

    std::cout << "   ABCDEFGHIJKLMNOPKRSTUVWXY" << std::endl;
    for (int i = 0; i < map.size(); i++) {
        std::cout << i+1 << " ";
        if (i < 9) std::cout << " ";
        std::cout << map.at(i) << std::endl;
    }

    return 0;
}