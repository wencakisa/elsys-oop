package org.elsys.cardgame;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.deck.WarDeck;
import org.elsys.cardgame.api.deck.BeloteDeck;
import org.elsys.cardgame.api.deck.SantaseDeck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.helper.Helper;
import org.elsys.cardgame.factory.GameFactory;

import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.print("> ");
        String deckString = in.nextLine();
        List<Card> cards = Helper.cardsFromString(deckString);

        Game game = null;

        while (true) {
            System.out.print("> ");
            String token = in.nextLine();

            if (token.equals("quit")) {
                return;
            }

            if (token.equals(WarDeck.NAME)) {
                game = GameFactory.createWarGame(cards);
            } else if (token.equals(BeloteDeck.NAME)) {
                game = GameFactory.createBeloteGame(cards);
            } else if (token.equals(SantaseDeck.NAME)) {
                game = GameFactory.createSantaseGame(cards);
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
