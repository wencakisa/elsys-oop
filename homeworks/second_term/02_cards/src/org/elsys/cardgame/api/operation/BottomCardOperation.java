package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public class BottomCardOperation extends SingleCardOperation {

    public static final String NAME = "bottom_card";

    public BottomCardOperation(Deck deck) {
        super(NAME, deck);
    }

    @Override
    protected void evaluate() {
        System.out.println(deck.bottomCard());
    }
}
