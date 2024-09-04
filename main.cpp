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

        void makeMove(int playableSpot) {            
        
        }
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
    public:
    void displayTable() {
        for (int i = 0; i < 13; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (table[i][j] == 1) std::cout << "+";
                else if (table[i][j] == 2) std::cout << "-";
                else if (table[i][j] == 3) std::cout << "|";
                else std::cout << " ";
            }

            if (i == 12)
                continue;
            std::cout << std::endl;
        }
    }
};

class Game {
    private:
        Player player1;
        Player player2;
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

        void startGame() {  
            setNames();
            chooseStarter();
        }
};

int main() {
    Table table;
    table.displayTable();
    Game game;
    game.startGame();

    return 0;
}