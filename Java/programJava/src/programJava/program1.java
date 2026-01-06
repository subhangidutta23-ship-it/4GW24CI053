package programJava;
import java.util.Scanner;
public class program1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// Input for matrix size N
		System.out.println("Enter the order N of the matrices:");
		int n = sc.nextInt();
		int[][] matrix1 = new int[n][n];
		int[][] matrix2 = new int[n][n];
		int[][] result = new int[n][n];
		// Input for first matrix 
		System.out.println("Enter the elements of Matrix 1:");
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				System.out.println("Element [" + i + "][" + j + "]:");
				matrix1[i][j] = sc.nextInt();
			}
		}
		// Input for second matrix
		System.out.println("Enter the elements of Matrix 2:");
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				System.out.println("Element [" + i + "][" + j + "]:");
				matrix2[i][j] = sc.nextInt();
			}
		}
		// Adding the matrices
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				result[i][j] = matrix1[i][j] + matrix2[i][j];
			}
		}
		// Displaying the result
		System.out.println("\n Resultant Matrix after Addition:");
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				System.out.print(result[i][j] + "\t");
			}
			System.out.println();
		}
		sc.close();
	}
}
