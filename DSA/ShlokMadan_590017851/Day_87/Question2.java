import java.util.*;

public class Question2
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();
        int[] coins=new int[n];

        for(int i=0;i<n;i++)
        {
            coins[i]=sc.nextInt();
        }

        int amount=sc.nextInt();

        Arrays.sort(coins);

        int count=0;

        for(int i=n-1;i>=0;i--)
        {
            if(coins[i]<=amount)
            {
                count+=amount/coins[i];
                amount%=coins[i];
            }
        }

        if(amount!=0)
        {
            System.out.println(-1);
        }
        else
        {
            System.out.println(count);
        }
    }
}