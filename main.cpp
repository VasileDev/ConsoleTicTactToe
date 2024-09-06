#include <iostream>
#include <string>

class Player {
    private:
        std::string playerName;
        char playerMark;
        bool playerTurn;
    public:
        Player(char playerMark, bool playerTurn): playerMark(playerMark), playerName("Unknown"), playerTurn(playerTurn) {}
    
        void setName(std::string name) { playerName = name; }
        std::string getName() { return playerName; }

        void setTurn(bool turn) { playerTurn = turn; }
        bool getTurn() { return playerTurn; }
};

class Table {
    private:
        int table[13][26] =  {
            {1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1},
            {3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3},
            {3,4,4,4, 11 ,4,4,4,3,4,4,4, 12 ,4,4,4,3,4,4,4, 13 ,4,4,4,3},
            {3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3},
            {1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1},
            {3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3},
            {3,4,4,4, 14 ,4,4,4,3,4,4,4, 15 ,4,4,4,3,4,4,4, 16 ,4,4,4,3},
            {3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3},
            {1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1},
            {3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3},
            {3,4,4,4, 17 ,4,4,4,3,4,4,4, 18 ,4,4,4,3,4,4,4, 19 ,4,4,4,3},
            {3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3,4,4,4,4,4,4,4,3},
            {1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2,1}
        };
        int remainingChoices[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
        int remainingSize = 9;
    public:
        void displayTable() {
            for (int i = 0; i < 13; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (table[i][j] == 1) std::cout << "+";
                    else if (table[i][j] == 2) std::cout << "-";
                    else if (table[i][j] == 3) std::cout << "|";
                    else if (table[i][j] == 5) std::cout << "X";
                    else if (table[i][j] == 6) std::cout << "0";
                    else std::cout << " ";
                }
                std::cout << std::endl;
            }
        }

        int* getremainingChoices() {
            return remainingChoices;
        }

        // Getting the len of the remainingChoices array
        int getSizeOfRemainingChoices() {
            return remainingSize;
        }

        // Will remove a number from remainingChoices when a player makes a move
        void removeOption(int chosenNumber) {
            // remainingSize = deleteElement(remainingChoices, remainingSize, chosenNumber);
            for (int i = 0; i < remainingSize; i++) {
                if (remainingChoices[i] == chosenNumber) {
                    // Shift the remaining elements to the left
                    for (int j = i; j < remainingSize - 1; j++) {
                        remainingChoices[j] = remainingChoices[j + 1];
                    }
                    remainingSize--;  // Reduce the size after removing
                    break;
                }
            }
        }

        void drawX(int nr) {
            if (nr == 1) {
                table[2][4] = 5;
            } else if (nr == 2) {
                table[2][12] = 5;
            } else if (nr == 3) {
                table[2][20] = 5;
            } else if (nr == 4) {
                table[6][4] = 5;
            } else if (nr == 5) {
                table[6][12] = 5;
            } else if (nr == 6) {
                table[6][20] = 5;
            } else if (nr == 7) {
                table[10][4] = 5;
            } else if (nr == 8) {
                table[10][12] = 5;
            } else if (nr == 9) {
                table[10][20] = 5;
            }
        }

        void draw0(int nr) {
            if (nr == 1) {
                table[2][4] = 6;
            } else if (nr == 2) {
                table[2][12] = 6;
            } else if (nr == 3) {
                table[2][20] = 6;
            } else if (nr == 4) {
                table[6][4] = 6;
            } else if (nr == 5) {
                table[6][12] = 6;
            } else if (nr == 6) {
                table[6][20] = 6;
            } else if (nr == 7) {
                table[10][4] = 6;
            } else if (nr == 8) {
                table[10][12] = 6;
            } else if (nr == 9) {
                table[10][20] = 6;
            }
        }

        bool checkAvailability(int theChoice) {
            for (int i = 0; i < getSizeOfRemainingChoices(); i++) {
                if (theChoice == remainingChoices[i]) {
                    return true;
                }
            }
            return false;
        }

        // Print the remaining choices
        void printRemainingChoices() {
            for (int i = 0; i < remainingSize; i++) {
                std::cout << remainingChoices[i] << " ";
            }
            std::cout << std::endl;
        }

        int checkRows() {
            if (table[2][4] == table[2][12] && table[2][12] == table[2][20]) {
                return table[2][4];
            }
            if (table[6][4] == table[6][12] && table[6][12] == table[6][20]) {
                return table[6][4];
            }
            if (table[10][4] == table[10][12] && table[10][12] == table[10][20]) {
                return table[10][4];
            }
            return 55;
        }

        int checkColumns() {
            if (table[2][4] == table[6][4] && table[6][4] == table[10][4]) {
                return table[2][4];
            }
            if (table[2][12] == table[6][12] && table[6][12] == table[10][12]) {
                return table[6][4];
            }
            if (table[2][20] == table[6][20] && table[6][20] == table[10][20]) {
                return table[10][4];
            }
            return 56;
        }

        int checkDiagonals() {
            if (table[2][4] == table[6][12] && table[6][12] == table[10][20]) {
                return table[2][4];
            }
            if (table[2][20] == table[6][12] && table[6][12] == table[10][4]) {
                return table[2][4];
            }
            return 57;
        }

        int checkWinner() {
            if (checkRows() == 55) {

            } else {
                if (checkRows() == 5) {
                    return 5;
                } else return 6;
            }

            if (checkColumns() == 56) {

            } else {
                if (checkColumns() == 5) {
                    return 5;
                } else return 6;
            }

            if (checkDiagonals() == 57) {

            } else {
                if (checkDiagonals() == 5) {
                    return 5;
                } else return 6;
            }
        }
};

class Game {
    private:
        Player player1;
        Player player2;
        Table table;
    public:
        Game() : player1('x', true), player2('0', true) {}

        void setNames() {
            std::string name1;
            std::cout << "Choose player 1 name: ";
            getline(std::cin, name1);
            player1.setName(name1);

            std::string name2;
            std::cout << "Choose a name for Player 2: ";
            getline(std::cin, name2);
            player2.setName(name2);
        }

        void chooseStarter() {
            std::cout << "You can choose who will start. (input 1 for Player1 or 2 for Player2)" << "\n";
            int choice;
            while (true) {
                std::cin >> choice;
                if (choice == 1) {
                    player1.setTurn(true);
                    player2.setTurn(false);
                    break;
                } else if (choice == 2) {
                    player1.setTurn(false);
                    player2.setTurn(true);
                    break;
                } else {
                    if (choice != 1 || choice != 2) {
                        std::cout << "Enter either 1 or 2." << "\n"; 
                    }
                }
            } 
        }

        void switchTurns() {
            player1.setTurn(!player1.getTurn());
            player2.setTurn(!player2.getTurn());
        }

        void makeMove(char mark, int choice) {
            if (mark == 'X') {
                table.drawX(choice);
            } else {
                table.draw0(choice);
            }
        }

        void playGame() {
            bool running = true;
            while (running) {
                table.printRemainingChoices();
                std::cout << "Choose a number from above: ";
                int choice;
                // If the player inputs another things
                while (true) {
                    std::cin >> choice;
                    
                    if ((choice >= 1 && choice <= 9) && (table.checkAvailability(choice))) {
                        break;
                    } else {
                        std::cout << "Please input a number from the available choices." << "\n";
                    }
                }
                if (player1.getTurn() == true) {
                    makeMove('X', choice);
                    switchTurns();
                    table.removeOption(choice);
                    table.displayTable();
                } else {
                    makeMove('0', choice);
                    switchTurns();
                    table.removeOption(choice);
                    table.displayTable();
                    table.checkWinner();
                }
                if (table.checkWinner() == 5) {
                    std::cout << player1.getName() << " won!" << "\n";
                    running = false;
                }
                if (table.checkWinner() == 6) {
                    std::cout << player2.getName() << " won!" << "\n";
                    running = false;
                }
                if (table.getSizeOfRemainingChoices() == 0) {
                    std::cout << "Nobody won this game!" << "\n";
                    running = false;
                }
            }
        }

        void startGame() {  
            setNames();
            chooseStarter();
            playGame();
        }
};

int main() {
    Game game;
    game.startGame();

    return 0;
}