package org.elsys;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class MainActive {
    public static void main(String[] args) {
        try {
            Class<?> clazz = Class.forName("org.elsys.TestClass");

            System.out.println("> Class name: " + clazz.getName());

            Object p = clazz.newInstance();
            System.out.println("> Object class: " + p.getClass().getName());

            Method m = clazz.getMethod("getValue");
            Object response = m.invoke(p);
            System.out.println("> Method result: " + response);

        } catch (
                ClassNotFoundException |
                InstantiationException |
                IllegalAccessException |
                NoSuchMethodException |
                InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}
