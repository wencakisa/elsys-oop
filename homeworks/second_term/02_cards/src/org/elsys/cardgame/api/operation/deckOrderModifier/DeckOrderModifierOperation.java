package org.elsys.cardgame.api.operation.deckOrderModifier;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.operation.AbstractOperation;

public abstract class DeckOrderModifierOperation extends AbstractOperation {
    public DeckOrderModifierOperation(String name, Game game) {
        super(name, game);
    }

    @Override
    public void execute() {
        Deck deck = game.getDeck();

        evaluate(deck);
        System.out.println(deck);
    }

    protected abstract void evaluate(Deck deck);
}
