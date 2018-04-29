package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public class SortOperation extends DeckOrderModifierOperation {

    public static final String NAME = "sort";

    public SortOperation(Deck deck) {
        super(NAME, deck);
    }

    @Override
    public void evaluate() {
        deck.sort();
    }
}
