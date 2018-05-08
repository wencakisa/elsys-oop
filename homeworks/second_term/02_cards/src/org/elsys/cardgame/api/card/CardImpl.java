package org.elsys.cardgame.api.card;

import org.elsys.cardgame.api.helper.Helper;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Map;
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
