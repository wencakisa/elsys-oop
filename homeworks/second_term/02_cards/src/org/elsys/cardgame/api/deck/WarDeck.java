package org.elsys.cardgame.api.deck;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.Rank;

import java.util.Arrays;
import java.util.List;

public class WarDeck extends AbstractDeck {

    public static List<Rank> RANK_POWERS = Arrays.asList(Rank.values());

    private static final int TOTAL_CARDS = 52;

    private static final int HAND_SIZE = 26;

    public WarDeck(List<Card> cards) {
        super(cards, TOTAL_CARDS, HAND_SIZE);
    }
}
