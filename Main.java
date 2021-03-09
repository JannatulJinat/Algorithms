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

    }
}
class Circle {

    public int radius;
}