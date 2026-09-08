import java.util.*;

public class Question2
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();

        int[] start=new int[n];
        int[] end=new int[n];

        for(int i=0;i<n;i++)
        {
            start[i]=sc.nextInt();
        }

        for(int i=0;i<n;i++)
        {
            end[i]=sc.nextInt();
        }

        Integer[] index=new Integer[n];

        for(int i=0;i<n;i++)
        {
            index[i]=i;
        }

        Arrays.sort(index,(a,b)->Integer.compare(end[a],end[b]));

        int count=0;
        int lastEnd=-1;

        for(int i=0;i<n;i++)
        {
            int k=index[i];

            if(start[k]>=lastEnd)
            {
                count++;
                lastEnd=end[k];
            }
        }

        System.out.println(count);
    }
}