package org.elsys.priorityQueueTask;

import java.util.*;

class Student {
    private int id;

    private String name;

    private double gcpa;

    Student(int id, String name, double gcpa) {
        this.id = id;
        this.name = name;
        this.gcpa = gcpa;
    }

    Student(List<String> properties) {
        this.name = properties.get(0);
        this.gcpa = Double.parseDouble(properties.get(1));
        this.id = Integer.parseInt(properties.get(2));
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getGcpa() {
        return gcpa;
    }
}

enum EventType {
    ENTER, SERVED
}

class Priorities {
    private Queue<Student> queue;

    Priorities() {
        // Praise Java 8 lambdas!
        queue = new PriorityQueue<>(
                Comparator.comparing(Student::getGcpa).reversed()
                        .thenComparing(Student::getName)
                        .thenComparing(Student::getId)
        );
    }

    List<Student> getStudents(List<String> events) {
        for (String event : events) {
            List<String> currentEventSplitted = Arrays.asList(event.split(" "));

            EventType currentEventType = EventType.valueOf(currentEventSplitted.get(0).toUpperCase());

            if (currentEventType.equals(EventType.ENTER)) {
                List<String> studentProperties = currentEventSplitted.subList(1, currentEventSplitted.size());

                queue.add(new Student(studentProperties));
            } else if (currentEventType.equals(EventType.SERVED)) {
                queue.poll();
            }
        }

        List<Student> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            result.add(queue.poll());
        }

        return result;
    }
}

public class PriorityQueueSolution {
    private final static Scanner scan = new Scanner(System.in);
    private final static Priorities priorities = new Priorities();

    public static void main(String[] args) {
        int totalEvents = Integer.parseInt(scan.nextLine());
        List<String> events = new ArrayList<>();

        while (totalEvents-- != 0) {
            String event = scan.nextLine();
            events.add(event);
        }

        List<Student> students = priorities.getStudents(events);

        if (students.isEmpty()) {
            System.out.println("EMPTY");
        } else {
            for (Student st: students) {
                System.out.println(st.getName());
            }
        }
    }
}
