package org.elsys.cardgame.api;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public abstract class AbstractDeck implements Deck {

    private List<Card> cards;
    private int handSize;

    public AbstractDeck(List<Card> cards, int handSize) {
        this.cards = cards;
        this.handSize = handSize;

        this.sort();
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
    public Card drawTopCard() {
        return cards.remove(0);
    }

    @Override
    public Card topCard() {
        return cards.get(0);
    }

    @Override
    public Card drawBottomCard() {
        return cards.remove(size() - 1);
    }

    @Override
    public Card bottomCard() {
        return cards.get(size() - 1);
    }

    @Override
    public int handSize() {
        return handSize;
    }

    @Override
    public Hand deal() {
        List<Card> dealCards = new ArrayList<>(cards.subList(0, handSize));
        cards.removeAll(dealCards);

        return new HandOfCards(dealCards);
    }

    @Override
    public void sort() {
        cards.sort(Comparator.comparing(Card::getSuit).thenComparing(Card::getRank));
    }

    @Override
    public void shuffle() {
        Collections.shuffle(cards);
    }
}
