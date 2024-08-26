#include <iostream>
#include <fstream>

class Table {
    private:
        
    public:

};

int main() {
    // Open the table file
    std::ifstream tableFile("table.txt");

    // Check if the table file is successfully opened
    if (!tableFile.is_open()) {
        std::cout << "Failed to open the file" << "\n";
        return 1;
    }

    // Max char count of a line
    const size_t MAX_LINE_LENGHT = 25; // size_t: unsignet integer type used for indexing

    // Create a char array for reading a line
    char line[MAX_LINE_LENGHT + 1];

    std::cout << "Content of the file" << "\n";

    int lineChecker = 0;
    int rowChecker = 0;

    while (tableFile.getline(line, sizeof(line))) {
        for (int i = 0; i < (sizeof(line) / sizeof(char)); i++) {
            
        }
    }


    return 0;
}