package org.elsys;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class Main {

    public static void main(String[] args) {
        Object o = new TestClass(1);

        Class<?> clazz = o.getClass();

        System.out.println("Class name: " + clazz.getName());
        System.out.println();

        Class<?> superClass = clazz.getSuperclass();
        System.out.println("Super class: " + superClass.getName());
        System.out.println();

        System.out.println("Interfaces: ");
        for (Class<?> i : clazz.getInterfaces()) {
            System.out.println("\t> Interface name: " + i.getName());
            System.out.println();
        }

        System.out.println("Constructors: ");
        for (Constructor<?> constructor : clazz.getDeclaredConstructors()) {
            System.out.println("\t> Constructor name: " + constructor.getName());
            System.out.println("\t> Constructor params count: " + constructor.getParameterCount());
            System.out.println();
        }

        System.out.println("Fields: ");
        for (Field field : clazz.getDeclaredFields()) {
            System.out.println("\t> Field type: " + field.getType());
            System.out.println("\t> Field name: " + field.getName());
            System.out.println("\t> Field private: " + Modifier.isPrivate(field.getModifiers()));
            System.out.println();
        }

        System.out.println();

        System.out.println("Methods: ");
        for (Method method : clazz.getDeclaredMethods()) {
            System.out.println("\t> Method name: " + method.getName());
            System.out.println("\t> Method public: " + Modifier.isPublic(method.getModifiers()));
            System.out.println("\t> Method params count: " + method.getParameterCount());

            for (Class<?> param : method.getParameterTypes()) {
                System.out.println("\t\t> Param type: " + param.getName());
            }

            System.out.println(); }
    }
}
