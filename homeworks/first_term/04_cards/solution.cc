#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <sstream>

using namespace std;

vector<string> split_into_tokens(const string& str) {
    istringstream in(str);

    vector<string> tokens;
    string token;
    while (in >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

template <class T>
bool contains(const vector<T>& haystack, const T& needle) {
    return (
        !haystack.empty() &&
        std::find(haystack.begin(), haystack.end(), needle) != haystack.end()
    );
}

template <class T>
bool greater_index(const vector<T>& haystack, const T& a, const T&b) {
    return std::find(haystack.begin(), haystack.end(), a) > std::find(haystack.begin(), haystack.end(), b);
}

class Card {
    string suit_;
    string rank_;
public:
    Card(const string& suit, const string& rank)
    : suit_(suit), rank_(rank)
    {}

    const string& get_suit() const {
        return suit_;
    }

    const string& get_rank() const {
        return rank_;
    }

    static vector<Card> generate_vector(vector<string>& v) {
        vector<Card> result;

        for (const string& str : v) {
            string suit = str.substr(0, 1);
            string rank = str.substr(1);

            result.push_back(Card(suit, rank));
        }

        return result;
    }

    class Comparator {
        vector<string> suits_powers_;
        vector<string> ranks_powers_;
    public:
        Comparator(const vector<string>& suits_powers, const vector<string>& ranks_powers)
        : suits_powers_(suits_powers), ranks_powers_(ranks_powers)
        {}

        bool operator()(const Card& a, const Card& b) {
            return greater_cards(a, b);
        }

    private:
        bool greater_suits(const string& suit1, const string& suit2) {
            return greater_index(suits_powers_, suit1, suit2);
        }

        bool greater_ranks(const string& rank1, const string& rank2) {
            return greater_index(ranks_powers_, rank1, rank2);
        }

        bool greater_cards(const Card& a, const Card& b) {
            if (a.get_suit() == b.get_suit()) {
                return greater_ranks(a.get_rank(), b.get_rank());
            }

            return greater_suits(a.get_suit(), b.get_suit());
        }
    };
};

ostream& operator<<(ostream& out, const Card& card) {
    out << card.get_suit() << card.get_rank();
    return out;
}

ostream& operator<<(ostream& out, const vector<Card>& cards) {
    for (const Card& card : cards) {
        out << card << " ";
    }

    return out;
}

class Deck {
    vector<Card> cards_;
    
    string name_;
    
    int total_cards_;
    int cards_in_hand_;
    
    const vector<string> valid_ranks_;
    static const vector<string> VALID_SUITS_;
public:
    Deck(
        vector<Card> cards,
        const string& name,
        int total_cards,
        int cards_in_hand,
        const vector<string>& valid_ranks
    )
    : cards_(filter_cards(cards, valid_ranks)),
      name_(name),
      total_cards_(total_cards),
      cards_in_hand_(cards_in_hand),
      valid_ranks_(valid_ranks)
    {}

    const string& get_name() const {
        return name_;
    }

    vector<Card> get_cards() const {
        return cards_;
    }

    bool can_play() const {
        return total_cards_ <= size();
    }

    bool can_deal() const {
        return cards_in_hand_ <= size();
    }

    int size() const {
        return cards_.size();
    }

    Card top_card() const {
        return cards_.front();
    }

    Card bottom_card() const {
        return cards_.back();
    }

    Card draw_top_card() {
        Card result = top_card();
        cards_.erase(cards_.begin());
        return result;
    }

    Card draw_bottom_card() {
        Card result = bottom_card();
        cards_.pop_back();
        return result;
    }

    vector<Card> deal() {
        vector<Card> result(cards_.begin(), cards_.begin() + cards_in_hand_);
        cards_.erase(cards_.begin(), cards_.begin() + cards_in_hand_);
        return result;
    };

    void shuffle() {
        std::shuffle(cards_.begin(), cards_.end(), std::default_random_engine());
    }

    void sort() {
        std::sort(cards_.begin(), cards_.end(), Card::Comparator(VALID_SUITS_, valid_ranks_));
    }

private:
    static vector<Card> filter_cards(vector<Card> cards, const vector<string>& valid_ranks) {
        cards.erase(
            std::remove_if(
                cards.begin(),
                cards.end(),
                [valid_ranks](const Card& c) {
                    return !(contains(VALID_SUITS_, c.get_suit()) && contains(valid_ranks, c.get_rank()));
                }
            ),
            cards.end()
        );

        return cards;
    }
};

const vector<string> Deck::VALID_SUITS_ { "C", "D", "H", "S" };

// -----------------------------------------------------------------------------

class War : public Deck {
    static const int TOTAL_CARDS_ = 52;
    static const int CARDS_IN_HAND_ = 26;
    static const vector<string> VALID_RANKS_;
public:
    War(vector<Card> cards)
    : Deck(cards, "War", TOTAL_CARDS_, CARDS_IN_HAND_, VALID_RANKS_)
    {}
};

const vector<string> War::VALID_RANKS_ { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

// -----------------------------------------------------------------------------

class Belote : public Deck {
    static const int TOTAL_CARDS_ = 32;
    static const int CARDS_IN_HAND_ = 8;
    static const vector<string> VALID_RANKS_;
public:
    Belote(vector<Card> cards)
    : Deck(cards, "Belote", TOTAL_CARDS_, CARDS_IN_HAND_, VALID_RANKS_)
    {}
};

const vector<string> Belote::VALID_RANKS_ { "7", "8", "9", "J", "Q", "K", "10", "A" };

// -----------------------------------------------------------------------------

class Santase : public Deck {
    static const int TOTAL_CARDS_ = 24;
    static const int CARDS_IN_HAND_ = 6;
    static const vector<string> VALID_RANKS_;
public:
    Santase(vector<Card> cards)
    : Deck(cards, "Santase", TOTAL_CARDS_, CARDS_IN_HAND_, VALID_RANKS_)
    {}
};

const vector<string> Santase::VALID_RANKS_ { "9", "J", "Q", "K", "10", "A" };

// -----------------------------------------------------------------------------

class Operation {
    string name_;
public:
    Operation(const string& name)
    : name_(name)
    {}

    const string& get_name() const {
        return name_;
    }

    virtual void eval(Deck** deck) = 0;
};

// -----------------------------------------------------------------------------

class DeckCreatorOperation : public Operation {
    vector<Card> cards_;
public:
    DeckCreatorOperation(const string& name, const vector<Card>& cards)
    : Operation(name), cards_(cards)
    {}

    void eval(Deck** deck) {
        *deck = execute(cards_);

        if (!(*deck)->can_play()) {
            cout << "ERROR: Not enough cards for " << (*deck)->get_name() << endl;
        }
    }

protected:
    virtual Deck* execute(const vector<Card>& cards) const = 0;
};

class WarDeckCreatorOperation : public DeckCreatorOperation {
public:
    WarDeckCreatorOperation(const vector<Card>& cards)
    : DeckCreatorOperation("War", cards)
    {}

    Deck* execute(const vector<Card>& cards) const {
        return new War(cards);
    }
};

class BeloteDeckCreatorOperation : public DeckCreatorOperation {
public:
    BeloteDeckCreatorOperation(const vector<Card>& cards)
    : DeckCreatorOperation("Belote", cards)
    {}

    Deck* execute(const vector<Card>& cards) const {
        return new Belote(cards);
    }
};

class SantaseDeckCreatorOperation : public DeckCreatorOperation {
public:
    SantaseDeckCreatorOperation(const vector<Card>& cards)
    : DeckCreatorOperation("Santase", cards)
    {}

    Deck* execute(const vector<Card>& cards) const {
        return new Santase(cards);
    }
};

// -----------------------------------------------------------------------------

class ViewSizeOperation : public Operation {
public:
    ViewSizeOperation()
    : Operation("size")
    {}

    void eval(Deck** deck) {
        if (*deck == nullptr) {
            cout << "ERROR: No deck" << endl;
        } else {
            cout << (*deck)->size() << endl;
        }
    }
};

// -----------------------------------------------------------------------------

class CardOperation : public Operation {
public:
    CardOperation(const string& name)
    : Operation(name)
    {}

    void eval(Deck** deck) {
        if (*deck == nullptr) {
            cout << "ERROR: No deck" << endl;
        } else {
            if ((*deck)->can_deal()) {
                execute(*deck);
            } else {
                cout << "ERROR: Not enough cards in deck" << endl;
            }
        }
    }

protected:
    virtual void execute(Deck* deck) const = 0;
};

class DealCardsOperation : public CardOperation {
public:
    DealCardsOperation()
    : CardOperation("deal")
    {}

    void execute(Deck* deck) const {
        cout << deck->deal() << endl;
    }
};

class ViewTopCardOperation : public CardOperation {
public:
    ViewTopCardOperation()
    : CardOperation("top_card")
    {}

    void execute(Deck* deck) const {
        cout << deck->top_card() << endl;
    }
};

class ViewBottomCardOperation : public CardOperation {
public:
    ViewBottomCardOperation()
    : CardOperation("bottom_card")
    {}

    void execute(Deck* deck) const {
        cout << deck->bottom_card() << endl;
    }
};

class DrawTopCardOperation : public CardOperation {
public:
    DrawTopCardOperation()
    : CardOperation("draw_top_card")
    {}

    void execute(Deck* deck) const {
        cout << deck->draw_top_card() << endl;
    }
};

class DrawBottomCardOperation : public CardOperation {
public:
    DrawBottomCardOperation()
    : CardOperation("draw_bottom_card")
    {}

    void execute(Deck* deck) const {
        cout << deck->draw_bottom_card() << endl;
    }
};

// ---------------------------------------------------------------------------

class DeckOrderModifierOperation : public Operation {
public:
    DeckOrderModifierOperation(const string& name)
    : Operation(name)
    {}

    void eval(Deck** deck) {
        execute(*deck);
        cout << (*deck)->get_cards() << endl;
    }

protected:
    virtual void execute(Deck* deck) = 0;
};

class SortDeckOperation : public DeckOrderModifierOperation {
public:
    SortDeckOperation()
    : DeckOrderModifierOperation("sort")
    {}

    void execute(Deck* deck) {
        deck->sort();
    }
};

class ShuffleDeckOperation : public DeckOrderModifierOperation {
public:
    ShuffleDeckOperation()
    : DeckOrderModifierOperation("shuffle")
    {}

    void execute(Deck* deck) {
        deck->shuffle();
    }
};

// -----------------------------------------------------------------------------

class Player {
    vector<Operation*> operations_;
public:
    void add_operation(Operation* op) {
        operations_.push_back(op);
    }

    Operation* get_operation(const string& name) {
        for (const auto& operation : operations_) {
            if (operation->get_name() == name) {
                return operation;
            }
        }

        return nullptr;
    }

    void play(istream& in, ostream& out, const string& stop_word) {
        Deck* deck = nullptr;
        string token;

        while (true) {
            out << "> ";
            in >> token;

            if (token == stop_word) {
                break;
            }

            Operation* op = get_operation(token);

            if (op != nullptr) {
                op->eval(&deck);
            } else {
                out << "ERROR: Unknown operation" << endl;
            }
        }
    }
};

int main() {
    string deck_str;
    cout << "> ";
    getline(cin, deck_str);

    vector<string> splitted_deck = split_into_tokens(deck_str);
    vector<Card> cards = Card::generate_vector(splitted_deck);

    Player p;
    p.add_operation(new WarDeckCreatorOperation(cards));
    p.add_operation(new BeloteDeckCreatorOperation(cards));
    p.add_operation(new SantaseDeckCreatorOperation(cards));
    p.add_operation(new ViewSizeOperation());
    p.add_operation(new DealCardsOperation());
    p.add_operation(new ViewTopCardOperation());
    p.add_operation(new ViewBottomCardOperation());
    p.add_operation(new DrawTopCardOperation());
    p.add_operation(new DrawBottomCardOperation());
    p.add_operation(new SortDeckOperation());
    p.add_operation(new ShuffleDeckOperation());
    p.play(cin, cout, "quit");

    return 0;
}
