import java.util.*;
public class Question1
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] flowerbed=new int[n];
        for(int i=0;i<n;i++)
        {
            flowerbed[i]=sc.nextInt();
        }
        int flowers=sc.nextInt();
        for(int i=0;i<n&&flowers>0;i++)
        {
            if(flowerbed[i]==0)
            {
                boolean left=i==0||flowerbed[i-1]==0;
                boolean right=i==n-1||flowerbed[i+1]==0;
                if(left&&right)
                {
                    flowerbed[i]=1;
                    flowers--;
                }
            }
        }
        System.out.println(flowers==0);
    }
}