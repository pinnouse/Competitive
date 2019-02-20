import java.io.*;


public class S1 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] flips = br.readLine().split("");
		boolean h = false, v = false;
		for (int i = 0; i < flips.length; i++) {
			if (flips[i].equalsIgnoreCase("h")) h = !h;
			else if (flips[i].equalsIgnoreCase("v")) v = !v;
		}
		if (!v && !h) {
			System.out.println("1 2");
			System.out.println("3 4");
		}
		
		else if (v && !h) {
			System.out.println("2 1");
			System.out.println("4 3");
		}
		
		else if (v && h) {
			System.out.println("4 3");
			System.out.println("2 1");
		}
		
		else if (!v && h) {
			System.out.println("3 4");
			System.out.println("1 2");
		}
	}

}
