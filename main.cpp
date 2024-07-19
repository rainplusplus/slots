#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

double balance = 1000000;
vector<char> slot = {'A', 'K', 'Q', 'Q', 'A', 'J', 'J', 'K', 'A'};
unordered_map<char, double> multiplier;

// inits multipliers
void make_map() {
    multiplier['J'] = 1;
    multiplier['Q'] = 2;
    multiplier['K'] = 3;
    multiplier['A'] = 5;
}

void print_homescreen() {
    std::cout << "                                                 __    __    ___  _____   __\n";
    std::cout << "        /' --;^/ ,-_\\     \\ | /                 / _\\  / /   /___\\/__   \\ / _\\\n";
    std::cout << "       / / --o\\ o-\\ \\\\   --(_)--                \\ \\  / /   //  //  / /\\ \\\\ \\ \n";
    std::cout << "      /-/-/|o|-|\\-\\\\|\\\\   / | \\    WELCOME TO   _\\ \\/ /___/ \\_//  / /  \\/_\\ \\\n";
    std::cout << "       '`  ` |-|   `` '                         \\__/\\____/\\___/   \\/     \\__/\n";
    std::cout << "             |-|\n";
    std::cout << "             |-|O                           PRESS 'ENTER' TO PLAY\n";
    std::cout << "             |-(\\, __\n";
    std::cout << "          ...|-|\\--,\\_....\n";
    std::cout << "      ,;;;;;;;;;;;;;;;;;;;;;;;;,.\n";
    std::cout << "~~,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "~;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,  ______   ---------   _____     ------\n";
}

// prints slot machine interface
void print_board() {
    std::cout << "                _\\/_                 |                _\\/_\n";
    std::cout << "                /o\\\\             \\       /            //o\\\n";
    std::cout << "                 |                 .---.                |\n";
    std::cout << "                _|_______     --  /     \\  --     ______|_\n";
    std::cout << "                        `~^~^~^~^~^~^~^~^~^~^~^~`\n";
    std::cout << "                     ____________|_______|____________\n";
    std::cout << "                    |  __    __    ___  _____   __    |  \n";
    std::cout << "                    | / _\\  / /   /___\\/__   \\ / _\\   | \n";
    std::cout << "                    | \\ \\  / /   //  //  / /\\ \\\\ \\    |  \n";
    std::cout << "                    | _\\ \\/ /___/ \\_//  / /  \\/_\\ \\ []| \n";
    std::cout << "                    | \\__/\\____/\\___/   \\/     \\__/ []|\n";
    std::cout << "                    |===_______===_______===_______===|\n";
    std::cout << "                    ||*|       |*|       |*|       |*||\n";
    std::cout << "                    ||*|       |*|       |*|       |*||\n";
    std::cout << "                    ||*|   " << slot[0] << "   |*|   " << slot[1] << "   |*|   " << slot[2] << "   |*||\n";
    std::cout << "                    ||*|       |*|       |*|       |*|| __\n";
    std::cout << "                    ||*|_______|*|_______|*|_______|*||(__)\n";
    std::cout << "                    |===_______===_______===_______===| ||\n";
    std::cout << "                    ||*|       |*|       |*|       |*|| ||\n";
    std::cout << "                    ||*|       |*|       |*|       |*|| ||\n";
    std::cout << "                    ||*|   " << slot[3] << "   |*|   " << slot[4] << "   |*|   " << slot[5] << "   |*|| ||\n";
    std::cout << "                    ||*|       |*|       |*|       |*|| ||\n";
    std::cout << "                    ||*|_______|*|_______|*|_______|*||_//\n";
    std::cout << "                    |===_______===_______===_______===|_/\n";
    std::cout << "                    ||*|       |*|       |*|       |*||\n";
    std::cout << "                    ||*|       |*|       |*|       |*||\n";
    std::cout << "                    ||*|   " << slot[6] << "   |*|   " << slot[7] << "   |*|   " << slot[8] << "   |*|| \n";
    std::cout << "                    ||*|       |*|       |*|       |*||\n";
    std::cout << "                    ||*|_______|*|_______|*|_______|*||\n";
    std::cout << "                    |===___________________________===|\n";
    std::cout << "                    |  /___________________________\\  |\n";
    std::cout << "                    |   |     'ENTER' TO SPIN      |  |\n";
    std::cout << "                   _|    \\________________________/   |_\n";
    std::cout << "                  (_____________________________________)    \n";
}

// shuffles slot + prints updated board
void spin() {
    for (int i = 0; i < 9; ++i) {
        // creates random num 1-4 representing A-J for each tile
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 4);
        int x = dis(gen);

        switch (x) {
            case 1: 
                slot[i] = 'J';
                break;
            case 2: 
                slot[i] = 'Q';
                break;
            case 3: 
                slot[i] = 'K';
                break;
            case 4: 
                slot[i] = 'A';
                break;
        }
    }
    print_board();
}

void calculate_win() {
    double current_mult = 1;
    double win = 0;
    // straight across
    if (slot[0] == slot[1] && slot[1] == slot[2]) {
        win += 5000;
        current_mult *= multiplier[slot[0]];
    }
    if (slot[3] == slot[4] && slot[4] == slot[5]) {
        win += 5000;
        current_mult *= multiplier[slot[3]];
    }
    if (slot[6] == slot[7] && slot[7] == slot[8]) {
        win += 5000;
        current_mult *= multiplier[slot[6]];
    }

    // diags
    if (slot[0] == slot[4] && slot[4] == slot[8]) {
        win += 5000;
        current_mult *= multiplier[slot[0]];
    }
    if (slot[2] == slot[4] && slot[4] == slot[6]) {
        win += 5000;
        current_mult *= multiplier[slot[2]];
    }

    win *= current_mult;
    cout << "You win: $" << win << "!" << endl;
    balance += win; 
    cout << "Balance: $" << balance << endl;
    
}

void play() {
    while (balance >= 10000) {
        string in;
        getline(cin, in);
        if (in == "q" || in == "quit") {
            cout << "Exiting the game. Goodbye!" << endl;
            break;
        }
        if (in.empty()) {
            balance -= 10000;
            spin();
            calculate_win();
        }
    }
    
}

int main() {
    print_homescreen();
    make_map();

    string in;
    getline(cin, in);

    if (in.empty()) {
        print_board();
        play();
    }
    else {
        return 0;
    }



    return 0;
}

/*

                _\/_                 |                _\/_
                /o\\             \       /            //o\
                 |                 .---.                |
                _|_______     --  /     \  --     ______|__
                        `~^~^~^~^~^~^~^~^~^~^~^~`
                     ____________|_______|____________
                    |  __    __    ___  _____   __    |  
                    | / _\  / /   /___\/__   \ / _\   | 
                    | \ \  / /   //  //  / /\ \\ \    |  
                    | _\ \/ /___/ \_//  / /  \/_\ \ []| 
                    | \__/\____/\___/   \/     \__/ []|
                    |===_______===_______===_______===|
                    ||*|       |*|       |*|       |*||
                    ||*|       |*|       |*|       |*||
                    ||*|   A   |*|   K   |*|   Q   |*||
                    ||*|       |*|       |*|       |*|| __
                    ||*|_______|*|_______|*|_______|*||(__)
                    |===_______===_______===_______===| ||
                    ||*|       |*|       |*|       |*|| ||
                    ||*|       |*|       |*|       |*|| ||
                    ||*|   Q   |*|   A   |*|   J   |*|| ||
                    ||*|       |*|       |*|       |*|| ||
                    ||*|_______|*|_______|*|_______|*||_//
                    |===_______===_______===_______===|_/
                    ||*|       |*|       |*|       |*||
                    ||*|       |*|       |*|       |*||
                    ||*|   J   |*|   K   |*|   A   |*|| 
                    ||*|       |*|       |*|       |*||
                    ||*|_______|*|_______|*|_______|*||
                    |===___________________________===|
                    |  /___________________________\  |
                    |   |     'ENTER' TO SPIN      |  |
                   _|    \________________________/   |_
                  (_____________________________________)   

                                                  
                                                  __    __    ___  _____   __
        "/' --;^/ ,-_\     \ | /                 / _\  / /   /___\/__   \ / _\"
       / / --o\ o-\ \\   --(_)--                \ \  / /   //  //  / /\ \\ \ 
      /-/-/|o|-|\-\\|\\   / | \    WELCOME TO   _\ \/ /___/ \_//  / /  \/_\ \
       '`  ` |-|   `` '                         \__/\____/\___/   \/     \__/
             |-|
             |-|O                           PRESS 'ENTER' TO PLAY
             |-(\,__
          ...|-|\--,\_....
      ,;;;;;;;;;;;;;;;;;;;;;;;;,.
~~,;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;,  ______   ---------   _____     ------
*/