package org.elsys;

import java.util.ArrayList;
import java.util.List;
import java.util.logging.Filter;

public class Person {

    private String name;
    private Gender gender;
    private int age;

    public Person(String name, Gender gender, int age) {
        this.name = name;
        this.gender = gender;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public Gender getGender() {
        return gender;
    }

    public int getAge() {
        return age;
    }

    public static List<Person> filter(List<Person> people, Filter filter) {
        List<Person> result = new ArrayList<>();

        for (Person p : people) {
        }

        people.sort((p1, p2) -> p1.getName().compareTo(p2.getName()));
        people.sort((p1, p2) -> p1.getGender().compareTo(p2.getGender()));

        return result;
    }

    public static void main(String[] args) {

    }

}
