package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public class DrawTopCardOperation extends SingleCardOperation {

    public static final String NAME = "draw_top_card";

    public DrawTopCardOperation(Deck deck) {
        super(NAME, deck);
    }

    @Override
    protected void evaluate() {
        System.out.println(deck.drawTopCard());
    }
}
