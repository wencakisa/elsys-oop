package org.elsys.cardgame.api.operation;

import org.elsys.cardgame.api.card.CardException;
import org.elsys.cardgame.api.deck.Deck;

public abstract class SingleCardOperation extends AbstractOperation {
    public SingleCardOperation(String name, Deck deck) {
        super(name, deck);
    }

    @Override
    public void execute() {
        if (deck != null) {
            if (deck.canDeal()) {
                evaluate();
            } else {
                System.err.println("ERROR: Not enough cards in deck.");
                throw new CardException();
            }
        } else {
            System.err.println("ERROR: No deck");
        }
    }

    protected abstract void evaluate();
}
