#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <algorithm>

using namespace std;

const string default_suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
const string default_ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

class Card {
    string suit_;
    string rank_;
public:
    Card(string suit, string rank) : suit_(suit), rank_(rank) {}

    friend ostream& operator<< (ostream& stream, const Card& card) {
        stream << card.suit_[0] << card.rank_[0];
        return stream;
    }
};

class Game {
    list<Card> deck_;
    list<string> commands_;
public:
    Game() {}
    Game(list<string> commands) {
        deck_ = generate_deck();
        commands_ = commands;
    }

    static list<Card> generate_deck() {
        list<Card> deck;

        for (size_t i = 0; i < sizeof(default_ranks) / sizeof(string); ++i) {
            for (size_t j = 0; j < sizeof(default_suits) / sizeof(string); ++j) {
                Card card(default_suits[j], default_ranks[i]);
                deck.push_back(card);
            }
        }

        return deck;
    }

    size_t size() const {
        return deck_.size();
    }

    Card top_card() const {
        return deck_.back();
    }

    Card bottom_card() const {
        return deck_.front();
    }

    Card draw_top_card() {
        Card result = top_card();
        deck_.pop_back();
        return result;
    }

    Card draw_bottom_card() {
        Card result = bottom_card();
        deck_.pop_front();
        return result;
    }

    void shuffle() {
        // TODO: Needs to implement iterator for Card
        // random_shuffle(deck_.begin(), deck_.end());
    }
};

class War : public Game {
public:
    War(list<string> commands) : Game(commands) {}
};

list<string> split_string(string str, const char delimiter) {
    istringstream stream(str);
    list<string> commands;
    string current_command;

    while (getline(stream, current_command, delimiter)) {
        commands.push_back(current_command);
    }

    return commands;
}

int main(int argc, char const *argv[]) {
    list<string> commands = split_string(argv[1], '.');

    string game_type = commands.front();
    Game game;

    if (game_type == "War") {
        cout << "War" << endl;
        game = War(commands);
    } else if (game_type == "Belote") {
        cout << "Belote" << endl;
    } else if (game_type == "Santase") {
        cout << "Santase" << endl;
    } else {
        cout << "Unknown game!" << endl;
    }

    return 0;
}
