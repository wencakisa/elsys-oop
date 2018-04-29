package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public class DrawBottomCardOperation extends SingleCardOperation {

    public static final String NAME = "draw_bottom_card";

    public DrawBottomCardOperation(Deck deck) {
        super(NAME, deck);
    }

    @Override
    protected void evaluate() {
        System.out.println(deck.drawBottomCard());
    }
}
