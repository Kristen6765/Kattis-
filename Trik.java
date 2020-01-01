/**
 * https://open.kattis.com/problems/trik
 */

import java.util.Scanner;

public class Trik {
    public static void main(String[] args) {
        //creat object of scanner
        Scanner myObj = new Scanner(System.in);
        char[] steps = new char[49];
        //take input by char and store them into an array
        steps = myObj.next().toCharArray();

        //the array indicates the 3 cups, ball[0] is the left cup
        boolean[] ball = new boolean[3];
        //first cup contains a ball as the game starts
        ball[0] = true;
        char step;
        for (int i = 0; i < steps.length; i++) {
            step = steps[i];
            //read the char from steps and do the currsponding swap
            switch (step) {
                case 'A':
                    boolean temp = ball[1];
                    ball[1] = ball[0];
                    ball[0] = temp;

                    break;
                case 'B':
                    boolean temp1 = ball[2];
                    ball[2] = ball[1];
                    ball[1] = temp1;

                    break;
                case 'C':
                    boolean temp2 = ball[0];
                    ball[0] = ball[2];
                    ball[2] = temp2;

                    break;
                 //if user input an an invaild char, print this reminder
                default:
                    System.out.println("please use 'A','B','C' as input  ");

            }



        }
        //search for the ball in the 3 cups
        for(int j=0;j<ball.length;j++){
            if(ball[j])
                System.out.println(j+1);
        }

    }

}
