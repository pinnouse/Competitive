import java.io.*;


public class S1 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String flips = br.readLine();
		boolean h = false, v = false;

		h = flips.chars().filter(ch -> ch == 'H').count() % 2 == 1;
		v = (h && flips.length() % 2 == 0) || (!h && flips.length() % 2 == 1);

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
