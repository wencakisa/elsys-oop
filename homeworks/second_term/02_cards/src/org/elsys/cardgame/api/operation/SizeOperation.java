package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public class SizeOperation extends AbstractOperation {

    public static final String NAME = "size";

    public SizeOperation(Deck deck) {
        super(NAME, deck);
    }

    @Override
    public void execute() {
        System.out.println(deck.size());
    }
}
