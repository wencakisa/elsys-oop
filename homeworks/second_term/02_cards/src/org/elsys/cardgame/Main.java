package org.elsys.cardgame;

import org.elsys.cardgame.api.deck.Deck;
import org.elsys.cardgame.api.game.Game;
import org.elsys.cardgame.api.operation.*;
import org.elsys.cardgame.factory.DeckFactory;
import org.elsys.cardgame.factory.GameFactory;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
        Deck deck = DeckFactory.defaultWarDeck();

		Game game = GameFactory.createWarGame(deck.getCards());
		game.addOperation(new SizeOperation(game.getDeck()));
		game.addOperation(new DrawTopCardOperation(game.getDeck()));
		game.addOperation(new DrawBottomCardOperation(game.getDeck()));
		game.addOperation(new TopCardOperation(game.getDeck()));
		game.addOperation(new BottomCardOperation(game.getDeck()));
		game.addOperation(new ShuffleOperation(game.getDeck()));
		game.addOperation(new SortOperation(game.getDeck()));
		game.addOperation(new DealOperation(game.getDeck()));

        Scanner in = new Scanner(System.in);
		while (true) {
            System.out.print("> ");
		    String token = in.next();

		    game.process(token);
        }
	}
}
