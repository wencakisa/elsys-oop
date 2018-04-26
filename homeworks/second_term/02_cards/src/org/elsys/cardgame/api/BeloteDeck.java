package org.elsys.cardgame.api;

import java.util.Arrays;
import java.util.List;

import static org.elsys.cardgame.api.Rank.*;

public class BeloteDeck extends AbstractDeck {

    public static List<Rank> RANK_POWERS = Arrays.asList(SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE);

    private static final int HAND_SIZE = 8;

    public BeloteDeck(List<Card> cards) {
        super(cards, HAND_SIZE);
    }
}