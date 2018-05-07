package org.elsys.cardgame.api.deck;

import org.elsys.cardgame.api.card.Rank;
import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.hand.Hand;
import org.elsys.cardgame.api.hand.HandImpl;
import org.elsys.cardgame.api.helper.Helper;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public abstract class AbstractDeck implements Deck {

    private String name;

    private List<Card> cards;

    private int deckSize;

    private int handSize;

    private List<Rank> rankPowers;

    protected AbstractDeck(String name, List<Card> cards, int deckSize, int handSize, List<Rank> rankPowers) {
        this.name = name;
        this.cards = cards;
        this.deckSize = deckSize;
        this.handSize = handSize;
        this.rankPowers = rankPowers;
    }

    @Override
    public boolean canPlay() {
        return deckSize <= size();
    }

    @Override
    public boolean canDeal() {
        return handSize() <= size();
    }

    @Override
    public String getName() {
        return name;
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

        return new HandImpl(dealCards);
    }

    @Override
    public void sort() {
        cards.sort(Comparator.comparing(Card::getSuit).thenComparing(card -> rankPowers.indexOf(card.getRank())));
    }

    @Override
    public void shuffle() {
        Collections.shuffle(cards);
    }

    @Override
    public String toString() {
        return Helper.cardListRepresentation(this.cards);
    }
}
