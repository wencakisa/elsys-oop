package org.elsys.cardgame.api.deck;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.card.Rank;

import java.util.Arrays;
import java.util.List;

import static org.elsys.cardgame.api.card.Rank.*;

public class SantaseDeck extends AbstractDeck {

    public static final int DECK_SIZE = 24;

    public static final int HAND_SIZE = 6;

    public static List<Rank> RANK_POWERS = Arrays.asList(NINE, JACK, QUEEN, KING, TEN, ACE);

    public SantaseDeck(List<Card> cards) {
        super(cards, DECK_SIZE, HAND_SIZE, RANK_POWERS);
    }
}
