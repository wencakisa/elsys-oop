package org.elsys.cardgame.api.deck;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.Rank;

import java.util.Arrays;
import java.util.List;

public class WarDeck extends AbstractDeck {

    public static final int DECK_SIZE = 52;

    public static final int HAND_SIZE = 26;

    public static List<Rank> RANK_POWERS = Arrays.asList(Rank.values());

    public WarDeck(List<Card> cards) {
        super(cards, DECK_SIZE, HAND_SIZE, RANK_POWERS);
    }
}
