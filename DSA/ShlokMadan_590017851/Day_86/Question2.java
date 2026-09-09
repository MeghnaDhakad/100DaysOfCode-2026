import java.util.*;
public class Question2
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] value=new int[n];
        int[] weight=new int[n];
        for(int i=0;i<n;i++)
        {
            value[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++)
        {
            weight[i]=sc.nextInt();
        }
        int capacity=sc.nextInt();
        Integer[] index=new Integer[n];
        for(int i=0;i<n;i++)
        {
            index[i]=i;
        }
        Arrays.sort(index,(a,b)->Double.compare((double)value[b]/weight[b],
                                                (double)value[a]/weight[a]));
        double ans=0;
        for(int i=0;i<n;i++)
        {
            int k=index[i];
            if(capacity>=weight[k])
            {
                ans+=value[k];
                capacity-=weight[k];
            }
            else
            {
                ans+=(double)value[k]/weight[k]*capacity;
                break;
            }
        }
        System.out.println(ans);
    }
}