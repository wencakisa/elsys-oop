package org.elsys.edu;

import java.util.ArrayList;
import java.util.List;

public class Student {

	private String name;

	private int course;

	private double averageGrade;

	private List<Subject> uncompletedSubjects;

	public Student(String name, int course, double averageGrade) {
		this.name = name;
		this.course = course;
		this.averageGrade = averageGrade;
		this.uncompletedSubjects = new ArrayList<>();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Integer getCourse() {
		return course;
	}

	public void setCourse(Integer course) {
		this.course = course;
	}

	public double getAverageGrade() {
		return averageGrade;
	}

	public void setAverageGrade(double averageGrade) {
		this.averageGrade = averageGrade;
	}


	public List<Subject> getUncompletedSubjects() {
		return uncompletedSubjects;
	}

	public boolean addUncompletedSubject(Subject subject) {
		return uncompletedSubjects.add(subject);
	}

	public boolean removeUncompletedSubject(Subject subject) {
		return uncompletedSubjects.remove(subject);
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Student student = (Student) o;

		if (course != student.course) return false;
		if (Double.compare(student.averageGrade, averageGrade) != 0) return false;
		if (name != null ? !name.equals(student.name) : student.name != null) return false;
		return uncompletedSubjects != null ? uncompletedSubjects.equals(student.uncompletedSubjects) : student.uncompletedSubjects == null;
	}

	@Override
	public int hashCode() {
		int result;
		long temp;
		result = name != null ? name.hashCode() : 0;
		result = 31 * result + course;
		temp = Double.doubleToLongBits(averageGrade);
		result = 31 * result + (int) (temp ^ (temp >>> 32));
		result = 31 * result + (uncompletedSubjects != null ? uncompletedSubjects.hashCode() : 0);
		return result;
	}
}
