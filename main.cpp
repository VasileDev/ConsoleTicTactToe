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

                if (i == 12)
                    continue;
                std::cout << std::endl;
            }
        }

        int* getremainingChoices() {
            return remainingChoices;
        }

        void setRemainingChoices(int arr[9]) {
            for (int i = 0; i < 9; i++) {
                remainingChoices[i] = arr[i];
            }
        }

        // Will remove a number from remainingChoices when a player makes a move
        void removeOption(int chosenNumber) {

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
            std::cout << "Choose a name for Player 2: " << "\n";
            getline(std::cin, name2);
            player1.setName(name2);
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

        void makeMove(char mark) {
            
        }

        void playGame() {
            bool running = true;
            while (running) {
                std::cout << "Choose a number: ";
                int* remainingChoices = table.getremainingChoices();
                for (int i = 0; i < 9; i++) {
                    std::cout << *(remainingChoices + i) << " ";
                }
                int choice;
                // If the player inputs another things
                while (true) {
                    std::cin >> choice;
                    if (choice < 1 || choice > 9) {
                        std::cout << "Please input a number from 1-10." << "\n";
                    } else {
                        break;
                    }
                }
                if (player1.getTurn() == true) {
                    makeMove('X');
                    switchTurns();
                    table.removeOption(choice);
                } else {
                    makeMove('0');
                    switchTurns();
                    table.removeOption(choice);
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