int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time=0;

    for (int i=0;i<ticketsSize;i++)
    {
        if(i<=k)
        {
        time+=(tickets[i]<tickets[k])?tickets[i]: tickets[k];
        }
        else
        {
            int limit=tickets[k]-1;
            time+=(tickets[i]<limit)?tickets[i]: limit;
        }
    }
    return time;
}