package org.elsys.cardgame.api.helper;

import org.elsys.cardgame.api.card.Card;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Helper {
    public static String cardListRepresentation(List<Card> cardList) {
        return cardList.stream().map(Card::toString).collect(Collectors.joining(" "));
    }

    public static <T extends Enum<T>> Map<String, T> enumValuesMapping(Class<T> enumType) {
        return Collections.unmodifiableMap(Arrays.stream(enumType.getEnumConstants()).collect(Collectors.toMap(T::toString, e -> e)));
    }

}
