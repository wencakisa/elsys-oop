package org.elsys.cardgame;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.card.CardImpl;
import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.deck.SantaseDeck;
import org.elsys.cardgame.api.deck.WarDeck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.game.GameImpl;

import java.util.List;
import java.util.Scanner;

public class Main {

    // S9 SJ SQ DA H9 HJ CK SK S10 SA D9 DJ DQ DK D10 C10 CA HQ HK H10 HA C9 CJ CQ

	public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // Reading and creating deck from string
        System.out.print("> ");
        String deckString = in.nextLine();
        List<Card> cards = CardImpl.fromDeckString(deckString);

        Deck deck = new SantaseDeck(cards);
        Game game = new GameImpl(deck);

        while (true) {
            System.out.print("> ");
            String token = in.nextLine();

            if (token.equals("quit")) {
                System.out.println("The end!");
                return;
            }

            game.process(token);
        }

	}
}
