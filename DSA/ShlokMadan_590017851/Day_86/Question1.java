import java.util.*;
public class Question1
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        int[] freq=new int[128];
        for(int i=0;i<s.length();i++)
        {
            freq[s.charAt(i)]++;
        }
        int count=0;
        boolean odd=false;
        for(int i=0;i<128;i++)
        {
            count+=freq[i]/2*2;
            if(freq[i]%2==1)
            {
                odd=true;
            }
        }
        if(odd)
        {
            count++;
        }
        System.out.println(count);
    }
}