package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public class TopCardOperation extends CardOperation {

    public static final String NAME = "top_card";

    public TopCardOperation(Deck deck) {
        super(NAME, deck);
    }

    @Override
    protected void evaluate() {
        System.out.println(deck.topCard());
    }
}
