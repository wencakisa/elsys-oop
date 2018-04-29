package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public abstract class AbstractOperation implements Operation {

    private String name;

    protected Deck deck;

    public AbstractOperation(String name, Deck deck) {
        this.name = name;
        this.deck = deck;
    }

    @Override
    public String getName() {
        return name;
    }
}
