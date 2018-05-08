package org.elsys.cardgame.api.helper;

import org.elsys.cardgame.api.card.Card;
import org.elsys.cardgame.api.card.CardImpl;
import org.elsys.cardgame.api.card.Rank;
import org.elsys.cardgame.api.card.Suit;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Helper {

    private static final Map<String, Suit> SUIT_MAPPING = enumValuesMapping(Suit.class);
    private static final Map<String, Rank> RANK_MAPPING = enumValuesMapping(Rank.class);

    private static <T extends Enum<T>> Map<String, T> enumValuesMapping(Class<T> enumType) {
        return Collections.unmodifiableMap(Arrays.stream(enumType.getEnumConstants()).collect(Collectors.toMap(T::toString, e -> e)));
    }

    public static String cardListRepresentation(List<Card> cardList) {
        return cardList.stream().map(Card::toString).collect(Collectors.joining(" "));
    }

    public static List<Card> cardsFromString(String cardString) {
        return Stream.of(cardString.split(" ")).map(s -> {
            Suit suit = SUIT_MAPPING.get(s.substring(0, 1));
            Rank rank = RANK_MAPPING.get(s.substring(1));

            return new CardImpl(suit, rank);
        }).collect(Collectors.toList());
    }

}
