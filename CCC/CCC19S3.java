import java.io.*;

public class S3 {
	
	public static String[][] horizontal(String[][] grid) {
		for (int i = 0; i < 3; i++) {
			if (!grid[i][0].equals("X") && !grid[i][1].equals("X")) {
				grid[i][2] = String.valueOf(Integer.parseInt(grid[i][1]) - Integer.parseInt(grid[i][0]) + Integer.parseInt(grid[i][1]));
			} else if (!grid[i][0].equals("X") && !grid[i][2].equals("X")) {
				grid[i][1] = String.valueOf((Integer.parseInt(grid[i][2]) - Integer.parseInt(grid[i][0])) / 2 + Integer.parseInt(grid[i][0]));
			} else if (!grid[i][1].equals("X") && !grid[i][2].equals("X")) {
				grid[i][0] = String.valueOf(Integer.parseInt(grid[i][1]) - (Integer.parseInt(grid[i][2]) - Integer.parseInt(grid[i][1])));
			}
		}
		return grid;
	}
	
	public static String[][] vertical(String[][] grid) {
		for (int i = 0; i < 3; i++) {
			if (!grid[0][i].equals("X") && !grid[1][i].equals("X")) {
				grid[2][i] = String.valueOf(Integer.parseInt(grid[1][i]) - Integer.parseInt(grid[0][i]) + Integer.parseInt(grid[1][i]));
			} else if (!grid[0][i].equals("X") && !grid[2][i].equals("X")) {
				grid[1][i] = String.valueOf((Integer.parseInt(grid[2][i]) - Integer.parseInt(grid[0][i])) / 2 + Integer.parseInt(grid[0][i]));
			} else if (!grid[1][i].equals("X") && !grid[2][i].equals("X")) {
				grid[0][i] = String.valueOf(Integer.parseInt(grid[1][i]) - (Integer.parseInt(grid[2][i]) - Integer.parseInt(grid[1][i])));
			} else if (!grid[0][i].equals("X")) {
				grid[1][i] = grid[0][i];
				grid[2][i] = grid[0][i];
				grid = horizontal(grid);
			} else if (!grid[2][i].equals("X")) {
				grid[0][i] = grid[1][i];
				grid[2][i] = grid[1][i];
				grid = horizontal(grid);
			} else if (!grid[2][i].equals("X")) {
				grid[0][i] = grid[2][i];
				grid[1][i] = grid[2][i];
				grid = horizontal(grid);
			}
		}
		return grid;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[][] grid = new String[3][3];
		for (int i = 0; i < 3; i++) {
			grid[i] = br.readLine().split(" ");
		}
		
		grid = horizontal(grid);
		
		grid = vertical(grid);
		
		for (int i = 0; i < 3; i++) {
			System.out.println(String.join(" ", grid[i]));
		}
	}
}
