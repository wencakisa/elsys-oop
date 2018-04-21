package org.elsys.cardgame.api;

import java.util.Arrays;
import java.util.List;

public class WarDeck extends AbstractDeck {

    public static List<Rank> RANK_POWERS = Arrays.asList(Rank.values());

    private static final int HAND_SIZE = 26;

    public WarDeck(List<Card> cards) {
        super(cards, HAND_SIZE);
    }
}
