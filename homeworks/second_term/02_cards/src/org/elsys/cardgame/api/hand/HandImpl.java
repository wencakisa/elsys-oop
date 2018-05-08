package org.elsys.cardgame.api.hand;

import java.util.List;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.helper.Helper;

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

    @Override
    public String toString() {
        return Helper.cardListRepresentation(this.cards);
    }
}
