package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public class ShuffleOperation extends DeckOrderModifierOperation {

    public static final String NAME = "shuffle";

    public ShuffleOperation(Deck deck) {
        super(NAME, deck);
    }

    @Override
    public void evaluate() {
        deck.shuffle();
    }
}
