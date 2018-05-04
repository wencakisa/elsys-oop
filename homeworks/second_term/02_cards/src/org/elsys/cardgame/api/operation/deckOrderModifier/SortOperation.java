package org.elsys.cardgame.api.operation.deckOrderModifier;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;

public class SortOperation extends DeckOrderModifierOperation {

    public static final String NAME = "sort";

    public SortOperation(Game game) {
        super(NAME, game);
    }

    @Override
    protected void evaluate(Deck deck) {
        deck.sort();
    }
}
