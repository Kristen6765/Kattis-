/**
 * https://open.kattis.com/problems/guessthedatastructure
 */

import java.util.*;
import java.util.PriorityQueue;
import java.io.*;
public class ICanGuessTheDataStructure_260782511 {
    public static void main(String[] args) throws IOException {
        //use bufferReader to take input
        BufferedReader br= new BufferedReader (new InputStreamReader (System.in));
        String str;
        //keep looping until EOF
        while((str = br.readLine()) != null){
            //store inouts into these 3 data structure
            Stack<Integer> stack = new Stack<>();
            boolean isStack=true;
            Queue<Integer> queue= new LinkedList<>();
            boolean isQueue=true;
            PriorityQueue<Integer> priorityQueue = new PriorityQueue<>(Collections.reverseOrder());
            boolean isPriorityQueue=true;
            //lincounter is n, where is equal to the actual following linenumber
            int lineCounter=Integer.parseInt(str);

            for (int i=0; i<lineCounter;i++){
                //spreate command and input number by using nextToken
                StringTokenizer str2=new StringTokenizer(br.readLine());
                int command=Integer.parseInt(str2.nextToken());
                int num=Integer.parseInt((str2.nextToken()));
                //if command==1 add nums in
                if(command==1){
                    if(isStack)
                        stack.push(num);
                    if(isQueue)
                        queue.add(num);
                    if(isPriorityQueue)
                        priorityQueue.add(num);
                }
                //if command==2, take out num and compare with input value
                //if not equal set boolean to false
                if(command ==2) {
                    if ((stack.isEmpty() || stack.pop() != num) && isStack)
                        isStack = false;
                    if ((queue.isEmpty() || queue.poll() != num) && isQueue)
                        isQueue = false;
                    if ((priorityQueue.isEmpty() || priorityQueue.poll() != num) && isPriorityQueue)
                        isPriorityQueue = false;
                }
            }
            //if more than 1 is ture then not sure
            if ((isStack && isQueue) || (isQueue && isPriorityQueue) || (isPriorityQueue && isStack)) {
                System.out.println("not sure");
            } else if (isStack) {
                System.out.println("stack");
            } else if (isQueue) {
                System.out.println("queue");
            } else if (isPriorityQueue) {
                System.out.println("priority queue");
            } else {
                //if none of the perious case is ture, then it is impossibel to tell
                System.out.println("impossible");
            }
        }
    }
}
