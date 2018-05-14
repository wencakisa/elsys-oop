package org.elsys.edu;

public class University extends AbstractEducationalInstitution implements EducationalInstitution {

	private int minMandatorySubjectsTaken;

	public University(String name, int minMandatorySubjectsTaken) {
		super(name);

		this.minMandatorySubjectsTaken = minMandatorySubjectsTaken;
	}

	@Override
	public boolean signUpForNextYear(Student student) {
		long studentUncompletedMandatorySubjectsCount = student.getUncompletedSubjects()
				.stream()
				.filter(Subject::isMandatory)
				.count();

		if (studentUncompletedMandatorySubjectsCount > minMandatorySubjectsTaken) {
			throw new EducationalInstitutionException();
		}

		return super.signUpForNextYear(student);
	}

}
