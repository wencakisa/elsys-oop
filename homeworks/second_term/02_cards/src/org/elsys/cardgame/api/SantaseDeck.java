package org.elsys.cardgame.api;

import java.util.Arrays;
import java.util.List;

import static org.elsys.cardgame.api.Rank.*;

public class SantaseDeck extends AbstractDeck {

    public static List<Rank> RANK_POWERS = Arrays.asList(NINE, JACK, QUEEN, KING, TEN, ACE);

    private static final int HAND_SIZE = 6;

    public SantaseDeck(List<Card> cards) {
        super(cards, HAND_SIZE);
    }
}
