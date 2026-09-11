import java.util.*;

public class Question2
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();

        int[] deadline=new int[n];
        int[] profit=new int[n];

        for(int i=0;i<n;i++)
        {
            deadline[i]=sc.nextInt();
        }

        for(int i=0;i<n;i++)
        {
            profit[i]=sc.nextInt();
        }

        Integer[] index=new Integer[n];

        for(int i=0;i<n;i++)
        {
            index[i]=i;
        }

        Arrays.sort(index,(a,b)->Long.compare(profit[b],profit[a]));

        int maxDeadline=0;

        for(int i=0;i<n;i++)
        {
            maxDeadline=Math.max(maxDeadline,deadline[i]);
        }

        boolean[] slot=new boolean[maxDeadline+1];
        long totalProfit=0;

        for(int i=0;i<n;i++)
        {
            int k=index[i];

            for(int j=deadline[k];j>=1;j--)
            {
                if(!slot[j])
                {
                    slot[j]=true;
                    totalProfit+=profit[k];
                    break;
                }
            }
        }

        System.out.println(totalProfit);
    }
}