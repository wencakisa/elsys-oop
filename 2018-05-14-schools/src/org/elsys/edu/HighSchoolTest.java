package org.elsys.edu;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class HighSchoolTest extends AbstractEducationalInstitutionTest {

    @BeforeEach
    void setUp() {
        educationalInstitution = new HighSchool("ELSYS");

        super.setUp();
    }

    @Test
    public void getStudentsInCourse() {
        assertEquals(3, educationalInstitution.getStudentsInCourse(2, false).size());
    }
}
