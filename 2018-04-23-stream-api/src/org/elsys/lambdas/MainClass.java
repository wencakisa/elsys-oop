package org.elsys.lambdas;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

import static org.elsys.lambdas.Person.filter;

public class MainClass {
    public static void main(String[] argv) {
        List<Person> people = Arrays.asList(new Person("Ivanka", Gender.FEMALE, 18),
                new Person("Penka", Gender.FEMALE, 38),
                new Person("Gancho", Gender.MALE, 17),
                new Person("Goshko", Gender.MALE, 48),
                new Person("Pencho", Gender.OTHER, 33));

        List<Person> under35 = filter(people, new Filter() {

            @Override
            public boolean match(Person p) {
                return p.getAge() < 35;
            }

        });
        System.out.println("under 35: " + under35.size());

        List<Person> under35notMale = filter(people, new Filter() {

            @Override
            public boolean match(Person p) {
                return p.getAge() < 35 && p.getGender() != Gender.MALE;
            }

        });
        System.out.println("under 35 not male: " + under35notMale.size());

        under35 = filter(people, p -> p.getAge() < 35);
        System.out.println("under 35: " + under35.size());
        under35notMale = filter(people,
                p -> p.getAge() < 35 && p.getGender() != Gender.MALE);
        System.out.println("under 35 not male: " + under35notMale.size());

        people.sort(new Comparator<Person>() {

            @Override
            public int compare(Person p1, Person p2) {
                return p1.getAge() - p2.getAge();
            }

        });

        people.sort(Comparator.comparingInt(Person::getAge));
        people.forEach(p -> {
            System.out.println("age: " + p.getAge() + "; name: " + p.getName());
        });

        people.sort(Comparator.comparing(Person::getGender));
        people.forEach(p -> {
            System.out.println(
                    "gender: " + p.getGender() +
                            "; age: " + p.getAge() + "; name: " + p.getName());
        });
    }
}
