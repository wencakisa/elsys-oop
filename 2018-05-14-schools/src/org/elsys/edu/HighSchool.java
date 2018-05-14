package org.elsys.edu;

public class HighSchool extends AbstractEducationalInstitution implements EducationalInstitution {
	public HighSchool(String name) {
		super(name);
	}

	@Override
	public boolean signUpForNextYear(Student student) {
		if (student.getUncompletedSubjects().size() == 0) {
			Integer studentCourse = student.getCourse();
			student.setCourse((studentCourse != null) ? studentCourse + 1 : 1);
		}

		return super.signUpForNextYear(student);
	}

}
