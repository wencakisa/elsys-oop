package org.elsys.cardgame.api;

import java.util.List;

public class HandImpl implements Hand {

    private List<Card> cards;

    public HandImpl(List<Card> cards) {
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
