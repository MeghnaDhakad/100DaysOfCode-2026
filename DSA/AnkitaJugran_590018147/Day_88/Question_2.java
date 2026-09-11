import java.util.Arrays;

public class Job_Sequencing {

    public static void main( String args[] ){

        int deadline[] = { 4, 1, 1, 1 };
        int profit[] = { 20, 10, 40, 30 };

        int n = profit.length;

        //each job takes one unit of time, so we can sort the jobs in decreasing order of profit
        int jobs[][] = new int[n][2];
        for (int i = 0; i < n; i++) {
            jobs[i][0] = profit[i];
            jobs[i][1] = deadline[i];
        }

        Arrays.sort(jobs, (a, b) -> b[0] - a[0]);

        int max_profit = 0;
        
        int maxdeadline = 0;

        //this will find the maximum deadline we have so we can know how many time slots we need to consider
        for( int i = 0 ; i < n ; i++ ){

            maxdeadline = Math.max(maxdeadline, jobs[i][1]);
        }

        boolean[] timeslot = new boolean[maxdeadline + 1]; //+1 beacuse indexing start from zero and we will not consider slot 0

        for( int i = 0 ; i < n ; i++ ){

            int currentjob_deadline = jobs[i][1];

            //assign the job to the last available time slot before its deadline, so that we can put other jobs in the earlier slots and maximize profit
            for( int j = currentjob_deadline ; j > 0 ; j-- ){

                //if timeslot is available, assign the job to that slot and add its profit to max_profit
                if( timeslot[j] == false ){

                    timeslot[j] = true;//now that slot is occupied, we will mark it as true
                    max_profit += jobs[i][0];//added the profit
                    break;
                }
            }
        }

        System.out.println("Deadline array: " + Arrays.toString(deadline));
        System.out.println("Profit array: " + Arrays.toString(profit));
        System.out.println("Maximum profit is: " + max_profit);

    }
    
}
