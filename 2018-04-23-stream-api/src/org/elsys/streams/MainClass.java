package org.elsys.streams;

import org.elsys.lambdas.Gender;
import org.elsys.lambdas.Person;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class MainClass {
    public static void main(String[] args) {
        List<Person> people = new ArrayList<>();

        people.add(new Person("Doncho", Gender.MALE, 27));
        people.add(new Person("Stamat", Gender.OTHER, 19));
        people.add(new Person("Kameliya", Gender.FEMALE, 20));
        people.add(new Person("Stancho", Gender.MALE, 18));
        people.add(new Person("Sisko", Gender.OTHER, 15));

        List<String> names = people.stream()
                .filter(person -> person.getAge() < 25)
                .filter(person -> person.getName().startsWith("S"))
                .sorted(Comparator.comparing(Person::getAge))
                .map(Person::getName)
                .collect(Collectors.toList());

        for (String name : names) {
            System.out.println("Name: " + name);
        }
    }
}
