package org.elsys;

import java.util.*;

class Student {
    private int id;
    private String fname;
    private double cgpa;

    Student(int id, String fname, double cgpa) {
        this.id = id;
        this.fname = fname;
        this.cgpa = cgpa;
    }

    public int getId() {
        return id;
    }

    public String getFname() {
        return fname;
    }

    public double getCgpa() {
        return cgpa;
    }
}

class StudentComparator<T> implements Comparator<T> {
    @Override
    public int compare(T o1, T o2) {
        Student s1 = (Student) o1;
        Student s2 = (Student) o2;

        int gcpaDifference = Double.compare(s2.getCgpa(), s1.getCgpa());

        if (gcpaDifference == 0) {
            int namesDifference = s1.getFname().compareTo(s2.getFname());

            if (namesDifference == 0) {
                return s1.getId() - s2.getId();
            }

            return namesDifference;
        }

        return gcpaDifference;
    }
}

public class StudentsSolution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = Integer.parseInt(in.nextLine());

        List<Student> studentList = new ArrayList<>();
        while(testCases > 0){
            int id = in.nextInt();
            String fname = in.next();
            double cgpa = in.nextDouble();

            Student st = new Student(id, fname, cgpa);
            studentList.add(st);

            testCases--;
        }

        studentList.sort(new StudentComparator<>());

        for(Student st : studentList) {
            System.out.println(st.getFname());
        }
    }
}
