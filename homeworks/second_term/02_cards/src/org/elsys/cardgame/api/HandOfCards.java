package org.elsys.cardgame.api;

import java.util.List;

public class HandOfCards implements Hand {

    private List<Card> cards;

    public HandOfCards(List<Card> cards) {
        this.cards = cards;
    }

    @Override
    public List<Card> getCards() {
        return cards;
    }

    @Override
    public int size() {
        return cards.size();
    }
}
