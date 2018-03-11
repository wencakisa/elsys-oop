package org.elsys;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class CompanyTest {

    @Test
    public void addEmployee() {
        Company company = new Company();

        company.addEmployee(new Employee(1, "Vencislav Tashev", 100));

        assertTrue(company.isEmployed(new Employee(1, "Vencislav Tashev", 100)));
        assertFalse(company.isEmployed(new Employee(2, "Gosho ot Pochivka", 359)));
    }

    @Test
    public void getEmployeesBySalary() {
        Company company = new Company();

        company.addEmployee(new Employee(1, "Vencislav Tashev", 100));
        company.addEmployee(new Employee(2, "Jake Tyson", 31400));
        company.addEmployee(new Employee(3, "Piponio", 123123));
    }
}