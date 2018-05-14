package org.elsys.edu;

import org.junit.jupiter.api.BeforeEach;

public abstract class AbstractEducationalInstitutionTest {

    protected EducationalInstitution educationalInstitution;

    @BeforeEach
    void setUp() {
        this.educationalInstitution.signUpForNextYear(new Student("Emil", 1, 5.63));
        this.educationalInstitution.signUpForNextYear(new Student("Sisko", 1, 4.25));
        this.educationalInstitution.signUpForNextYear(new Student("Georgi", 2, 5.02));
        this.educationalInstitution.signUpForNextYear(new Student("Emil", 1, 3.65));
    }

    public abstract void getStudentsInCourse();
}
