package org.elsys.manytoone.tests;

import static org.junit.Assert.*;

import org.elsys.manytoone.ManyToOneRelation;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

public class ManyToOneRelationTestCase {

    private ManyToOneRelation<String, Integer> relation;

	@Before
	public void setUp() throws Exception {
        relation = new ManyToOneRelation<>();
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void testConnect() {
        assertTrue(relation.connect("Integer1", 1));
        assertTrue(relation.connect("Integer2", 2));
	}

	@Test
	public void testContainsSource() {
	    relation.connect("Integer1", 1);

		assertTrue(relation.containsSource("Integer1"));
		assertFalse(relation.containsSource("Integer2"));
	}

	@Test
	public void testContainsTarget() {
        relation.connect("Integer1", 1);
        relation.connect("Integer2", 2);

        assertTrue(relation.containsTarget(1));
        assertTrue(relation.containsTarget(2));
        assertFalse(relation.containsTarget(3));
	}

	@Test
	public void testGetTarget() {
	    relation.connect("Integer1", 1);
	    relation.connect("Integer2", 2);

	    assertTrue(relation.getTarget("Integer1").equals(1));
	    assertTrue(relation.getTarget("Integer2").equals(2));
	    assertFalse(relation.getTarget("Integer2").equals(1));
	}

	@Test
	public void testGetSources() {
        relation.connect("Integer1", 1);
        relation.connect("Integer2", 2);

        assertTrue(relation.getSources(1).contains("Integer1"));
        assertTrue(relation.getSources(2).contains("Integer2"));
        assertFalse(relation.getSources(1).contains("Integer2"));
	}

	@Test
	public void testDisconnectSource() {
        relation.connect("Integer1", 1);
        relation.connect("Integer2", 2);
        relation.disconnectSource("Integer2");

        assertTrue(relation.containsSource("Integer1"));
        assertFalse(relation.containsSource("Integer2"));
	}

	@Test
	public void testDisconnect() {
	    relation.connect("Integer1", 1);
	    relation.connect("Integer2", 2);
	    relation.disconnect(2);

	    assertTrue(relation.containsTarget(1));
	    assertFalse(relation.containsTarget(2));
	}

	@Test
	public void testGetTargets() {
        relation.connect("Integer1", 1);
        relation.connect("Integer2", 2);

        assertTrue(relation.getTargets().contains(1));
        assertTrue(relation.getTargets().contains(2));
        assertFalse(relation.getTargets().contains(3));
	}

}
