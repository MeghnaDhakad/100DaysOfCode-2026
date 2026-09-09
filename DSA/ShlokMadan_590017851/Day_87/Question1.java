import java.util.*;

public class Question1
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);

        int n=sc.nextInt();
        int five=0;
        int ten=0;
        boolean possible=true;

        for(int i=0;i<n;i++)
        {
            int bill=sc.nextInt();

            if(bill==5)
            {
                five++;
            }
            else if(bill==10)
            {
                if(five==0)
                {
                    possible=false;
                    break;
                }

                five--;
                ten++;
            }
            else
            {
                if(ten>0&&five>0)
                {
                    ten--;
                    five--;
                }
                else if(five>=3)
                {
                    five-=3;
                }
                else
                {
                    possible=false;
                    break;
                }
            }
        }

        System.out.println(possible);
    }
}