package org.elsys.lambdas;

import java.util.List;
import java.util.ArrayList;

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
			if (filter.match(p)) {
				result.add(p);
			}
		}
		return result;
	}
}
