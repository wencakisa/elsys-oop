package org.elsys.cardgame.api.operation.deckCreator;

import org.elsys.cardgame.api.deck.WarDeck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.game.GameImpl;

public class WarDeckCreatorOperation extends DeckCreatorOperation {

    public static final String NAME = "War";

    public WarDeckCreatorOperation(Game game) {
        super(NAME, game);
    }

    @Override
    protected Game evaluate() {
        return new GameImpl(new WarDeck(game.getDeck().getCards()));
    }
}
