public class ArraySpiralOrder {
    public static void take(int arr[][], int n, int m){
        Scanner sc = new Scanner(System.in);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = sc.nextInt();
            }
        }
    }

    public static void SpiralTraversal(int n, int m, int arr[][]){
        int startCol = 0;
        int startRow = 0;
        int endCol = m-1;
        int endRow = n-1;
        while (startCol <= endCol && startRow <= endRow){
            for(int i=startCol;i<=endCol;i++){
                System.out.print(arr[startRow][i]);
            }
            startRow++;
            for(int i=startRow;i<=endRow;i++){
                System.out.print(arr[i][endCol]);
            }
            endCol--;
            if(startRow <= endRow){
                for(int i=endCol;i>=startCol;i--){
                    System.out.print(arr[endRow][i]);
                }
                endRow--;
            }
            if(startCol <= endCol){
                for(int i=endRow;i>=startRow;i--){
                    System.out.print(arr[i][startCol]);
                }
                startCol++;
            }
    
        }
        
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        int [][] numbers = new int[n][m];

        take(numbers,n,m);
        SpiralTraversal(n,m,numbers);

    }
}