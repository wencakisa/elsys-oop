package org.elsys.cardgame;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.card.CardImpl;
import org.elsys.cardgame.api.deck.WarDeck;
import org.elsys.cardgame.api.deck.BeloteDeck;
import org.elsys.cardgame.api.deck.SantaseDeck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.game.GameImpl;

import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("> ");
        String deckString = in.nextLine();
        List<Card> cards = CardImpl.fromDeckString(deckString);

        Game game = null;

        while (true) {
            System.out.print("> ");
            String token = in.nextLine();

            if (token.equals("quit")) {
                return;
            }

            if (token.equals(WarDeck.NAME)) {
                game = new GameImpl(new WarDeck(cards));
            } else if (token.equals(BeloteDeck.NAME)) {
                game = new GameImpl(new BeloteDeck(cards));
            } else if (token.equals(SantaseDeck.NAME)) {
                game = new GameImpl(new SantaseDeck(cards));
            } else {
                if (game != null) {
                    game.process(token);
                } else {
                    System.err.println("ERROR: No deck");
                }
            }
        }

	}
}
