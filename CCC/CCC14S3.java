import java.io.*;
import java.util.*;
public class Main {
    public static Stack<Integer> mountain = new Stack<Integer>();
    public static Stack<Integer> branch = new Stack<Integer>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int runs = Integer.parseInt(br.readLine());
        boolean possible;
        int lake;
        int numCarts;
        for (int i = 0; i < runs; i++){
            mountain.clear(); //Empty the stacks
            branch.clear(); //Empty the stacks
            possible = true; //Possible or not? Return 'Y' vs 'N'
            lake = 0; //Keeps track of the last cart in the lake

            numCarts = Integer.parseInt(br.readLine());
            for (int cart = 0; cart < numCarts; cart++){
                mountain.push(Integer.parseInt(br.readLine()));
                //System.out.println(mountain.peek());
            }

            while (possible && !mountain.empty()) {
                if (lake == mountain.peek() - 1)
                    lake = mountain.pop();
                else if (!branch.empty() && lake == branch.peek() - 1)
                    lake = branch.pop();
                else {
                    //Can we push the cart in? If we do, will it be less than the current one inside?
                    if (branch.empty() || mountain.peek() < branch.peek())
                        branch.push(mountain.pop());
                    else
                        possible = false; //Can't push a cart into branch; therefore, when it comes down to lake, the rest cannot enter
                }
            }
            System.out.print(possible ? "Y\n" : "N\n");
        }
    }
}
