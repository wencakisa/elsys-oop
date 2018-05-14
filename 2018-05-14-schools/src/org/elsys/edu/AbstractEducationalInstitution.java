package org.elsys.edu;

import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class AbstractEducationalInstitution implements EducationalInstitution {

    private String name;

    private Set<Student> students;

    public AbstractEducationalInstitution(String name) {
        this.name = name;
        this.students = new HashSet<>();
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public boolean signUpForNextYear(Student student) {
        return students.add(student);
    }

    @Override
    public boolean signOut(Student student) {
        return students.remove(student);
    }

    @Override
    public Collection<Student> getStudents() {
        return students;
    }

    @Override
    public List<Student> getStudentsInCourse(int course, boolean orderedByAverageGrade) {
        List<Student> filteredStudents = students.stream()
                .filter(student -> student.getCourse().equals(course))
                .collect(Collectors.toList());

        if (orderedByAverageGrade) {
            filteredStudents.sort(Comparator.comparingDouble(Student::getAverageGrade));
        }

        return filteredStudents;
    }

    @Override
    public List<Student> order(Comparator<Student> comparator) {
        return students.stream().sorted(comparator).collect(Collectors.toList());
    }

    @Override
    public Collection<Student> filter(Predicate<Student> predicate) {
        return students.stream().filter(predicate).collect(Collectors.toList());
    }

    @Override
    public Map<Double, List<Student>> groupStudentsByGrade() {
        return students.stream().collect(Collectors.groupingBy(Student::getAverageGrade));
    }
}
