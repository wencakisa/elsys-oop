package org.elsys.edu;

import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class MainClass {

    private static final String END_TOKEN = "END";

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Subject mathsSubject = new Subject("Maths", false);
        Subject oopSubject = new Subject("Object-Oriented Programming", true);
        EducationalInstitution uni = new University("Oxford University", 1);

        while (true) {
            String input = in.nextLine();

            if (input.equals(END_TOKEN)) {
                break;
            }

            List<String> studentTokens = Arrays.asList(input.split(", "));
            Student student = new Student(
                studentTokens.get(0),
                Integer.valueOf(studentTokens.get(1)),
                Double.valueOf(studentTokens.get(2))
            );

            student.addUncompletedSubject(
                student.getCourse() % 2 == 0 ? oopSubject : mathsSubject
            );

            try {
                uni.signUpForNextYear(student);
            } catch (EducationalInstitutionException ex) {
                ex.printStackTrace();
            }
        }
    }
}
