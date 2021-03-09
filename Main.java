/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author jinat
 */
public class Main {

    //static block
    //executes even before main method
    //output: static block 1 -> static block 2 -> main method 
    static {
        System.out.println("Hello from Static Block 1");
    }

    public static void main(String[] args) {

        // "==" operator , compares objects
        Circle circleObj1 = new Circle();
        Circle circleObj2 = new Circle();
        Circle circleObj3;
        circleObj1.radius = 5;
        circleObj2.radius = 5;
        System.out.println(circleObj1 == circleObj2); //false
        circleObj3 = circleObj1;
        System.out.println(circleObj1 == circleObj3); //true

        //string
        String string1 = "I" + "like" + "Java";
        System.out.println(string1); // IlikeJava

        System.out.println('j' + 'a' + 'v' + 'a');  //418
        //character literals has been used instead of string literals
        //an addition of each equivalent ASCII(Unicode) value of the character will be obtained.
        //Hence the output is 106 + 97 + 118 + 97 = 418

        //String Pool
        String s1 = "UK"; //string literal
        String s2 = "UK";
        String s3 = "UK";
        String s4 = new String(s3); //[will be in heap, not in string pool]

        System.out.println(s3.compareTo(s4));// 0 true //It compares strings on the basis of Unicode value of each character in the strings.
        System.out.println(s3 == s4); //false
        System.out.println(s1 == s2); //true 

        s1.concat(" USA");
        System.out.println(s1); //UK
        System.out.println(s2); //UK
        s2 = "BANGLADESH";
        System.out.println(s2); //BANGLADESH
        System.out.println(s3); //UK 

        System.out.println(s4); //UK 

        //Static variable
        Circle circleObj4 = new Circle();
        Circle circleObj5 = new Circle();

        circleObj4.colorOpacity = 10;
        System.out.println(circleObj4.colorOpacity); //10
        System.out.println(circleObj5.colorOpacity); //10

        circleObj5.colorOpacity = 20;

        System.out.println(circleObj4.colorOpacity); //20
        System.out.println(circleObj5.colorOpacity); //20

        //static method
        //without creating obj, static method can be called
        Circle.print(); // output: "Hello from static method"

        //static class
        //only inner class can be static, outer class can't be static
        // static inner class instantiated without instantiating its outer class
        Circle.innerClassStatic innerClassObj1 = new Circle.innerClassStatic();
        innerClassObj1.display();
    }

    //static block
    //executes even before main method 
    static {
        System.out.println("Hello from Static Block 2");
    }

}

class Circle {

    public int radius;
    public static int colorOpacity;
    public static double pi = 3.1416;

    //static method
    public static void print() {
        //radius = 5; // error
        pi = 3.14159265; //static method can access  static variable
        int variableInsideStaticMethod = 5; // static method can access  variableInsideStaticMethod
        System.out.println("Hello from Static method");

    }

    public static class innerClassStatic {

        //only inner class can be static, outer class can't be static
        public void display() {
            System.out.println("Hello from Static class[inner class]");

        }
    }

}

