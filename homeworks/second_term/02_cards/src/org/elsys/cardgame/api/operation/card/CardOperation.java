package org.elsys.cardgame.api.operation.card;

import org.elsys.cardgame.api.operation.AbstractOperation;
import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.card.CardException;

public abstract class CardOperation extends AbstractOperation {

    public CardOperation(String name, Game game) {
        super(name, game);
    }

    @Override
    public void execute() {
        Deck deck = game.getDeck();

        if (deck != null) {
            if (deck.canDeal()) {
                evaluate(deck);
            } else {
                System.err.println("ERROR: Not enough cards in deck.");
                throw new CardException();
            }
        } else {
            System.err.println("ERROR: No deck");
        }
    }

    protected abstract void evaluate(Deck deck);
}
