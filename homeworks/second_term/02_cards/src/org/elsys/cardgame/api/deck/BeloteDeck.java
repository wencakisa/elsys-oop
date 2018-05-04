package org.elsys.cardgame.api.deck;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.Rank;

import java.util.Arrays;
import java.util.List;

import static org.elsys.cardgame.api.Rank.*;

public class BeloteDeck extends AbstractDeck {

    public static final int DECK_SIZE = 32;

    public static final int HAND_SIZE = 8;

    public static List<Rank> RANK_POWERS = Arrays.asList(SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE);

    public BeloteDeck(List<Card> cards) {
        super(cards, DECK_SIZE, HAND_SIZE, RANK_POWERS);
    }
}
