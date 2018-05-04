package org.elsys.cardgame.api.card;

import org.elsys.cardgame.api.Rank;
import org.elsys.cardgame.api.Suit;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class CardImpl implements Card {

    private Suit suit;
    private Rank rank;

    public CardImpl(Suit suit, Rank rank) {
        this.suit = suit;
        this.rank = rank;
    }

    @Override
    public Suit getSuit() {
        return suit;
    }

    @Override
    public Rank getRank() {
        return rank;
    }

    @Override
    public String toString() {
        return getSuit().toString() + getRank().toString();
    }

    public static List<Card> fromDeckString(String deckString) {
        return Stream.of(deckString.split(" ")).map(s -> {
            Suit suit = Suit.getBySymbol(s.substring(0, 1));
            Rank rank = Rank.getBySymbol(s.substring(1));

            return new CardImpl(suit, rank);
        }).collect(Collectors.toList());
    }

    // Auto-generated equals() and hashCode() methods
    // from IntelliJ Idea

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        CardImpl that = (CardImpl) o;

        if (suit != that.suit) return false;
        return rank == that.rank;
    }

    @Override
    public int hashCode() {
        int result = suit != null ? suit.hashCode() : 0;
        result = 31 * result + (rank != null ? rank.hashCode() : 0);
        return result;
    }
}
