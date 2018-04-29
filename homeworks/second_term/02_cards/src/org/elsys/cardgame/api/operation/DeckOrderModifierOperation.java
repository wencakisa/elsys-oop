package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.deck.Deck;

public abstract class DeckOrderModifierOperation extends AbstractOperation {
    public DeckOrderModifierOperation(String name, Deck deck) {
        super(name, deck);
    }

    @Override
    public void execute() {
        this.evaluate();
        this.deck.getCards().forEach(card -> System.out.print(card + " "));
        System.out.println();
    }

    protected abstract void evaluate();
}
