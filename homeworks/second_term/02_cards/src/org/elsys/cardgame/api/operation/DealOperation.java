package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public class DealOperation extends AbstractOperation {

    public static final String NAME = "deal";

    public DealOperation(Deck deck) {
        super(NAME, deck);
    }

    @Override
    public void execute() {
        deck.deal();
    }
}
