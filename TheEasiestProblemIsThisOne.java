/**
 * https://open.kattis.com/problems/easiest
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class TheEasiestProblemIsThisOne{

    public static void main(String[] args) {
        ArrayList<Integer> Ns = new ArrayList<Integer>();
        //creat object of scanner
        Scanner scanner = new Scanner(System.in);
        try {
            while (scanner.hasNextLine()) {
                int N = Integer.valueOf(scanner.nextLine());
                if (N != 0) {
                    Ns.add(N);
                } else {
                    scanner.close();
                }

            }

        }catch ( java.lang.IllegalStateException e){
            //System.out.println("catched");
            //System.out.println("the array contians " + Ns);
        }


        int size=Ns.size();
        for(int i=0; i<size;i++){
            int N=Ns.get(i);

            if((N>=1)&&(N<+100000)){
               result(N);
            }

        }


    }
    public static void result (int num){

        int N=num;
        int Nd=sumOfDigit(N);
        //g>10
        int g=11;
        //if the sums are not euqal then g++
        while(sumOfDigit((g*N))!=Nd){
            g++;

        }
        //System.out.println("g: "+g);
        System.out.println(g);

    }


    public static int sumOfDigit(int num){
        int sum=0;
         while(num>0){
             sum=sum+num%10;
             num=num/10;
         }
       // System.out.println(" sum of digit is : " + sum);
        return sum;
    }





}
