package org.elsys;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
        Name n1 = new Name("Gosho", "Paveto");
        Name n2 = new Name("Miro", "Surbina");
        Name n3 = new Name("Gosho", "Paveto");

        System.out.println(n1);

        List<Name> names = new ArrayList<>();
        names.add(n1);
        names.add(n2);

        System.out.println(names.contains(n1));
        System.out.println(names.contains(n2));
        System.out.println(names.contains(n3));
        System.out.println(names.contains(new Name("Gosho", "Paveto")));

        Set<Name> namesSet = new HashSet<>();
        namesSet.add(n1);
        namesSet.add(n2);

        System.out.println(namesSet.contains(n1));
        System.out.println(namesSet.contains(n2));
        System.out.println(namesSet.contains(n3));
        System.out.println(namesSet.contains(new Name("Gosho", "Paveto")));

        System.out.println("--------------------------------------------------");
        System.out.println(namesSet.contains(n1));
        n1.setFirstName("Djeik");
        System.out.println(namesSet.contains(n1));
    }
}
