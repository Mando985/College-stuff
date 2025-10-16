import java.util.Scanner;

public class matrix {
    public static void main(String[] args) {
        Scanner scanner= new Scanner(System.in);
        System.out.println("Enter the number of rows:");
        int m= scanner.nextInt();
        System.out.println("Enter the number of columns:");
        int n= scanner.nextInt();

        int[][] resultant=new int[m][n];
        int[][] a=new int[m][n];
        int[][] b=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.printf("Enter the row %d and column %d of matrix A\n",i,j);
                a[i][j]=scanner.nextInt();

            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                System.out.printf("Enter the row %d and column %d of matrix B\n",i,j);
                b[i][j]=scanner.nextInt();

            }
        }

        System.out.print("The sum of the two matrix is\n");

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                resultant[i][j]=a[i][j]+b[i][j];
                System.out.print(resultant[i][j]+" ");
            }
            System.out.print("\n");
        }

        System.out.print("\n");

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                System.out.print(resultant[j][i]+" ");
            }
            System.out.print("\n");
        }

    }
}
