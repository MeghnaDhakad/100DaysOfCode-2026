int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) 
{
    int zeros=0, ones=0;

    for (int i=0; i<studentsSize; i++)
    {
        if (students[i] == 0)
        {
            zeros++;
        }

        else
            ones++; 
    }

    for (int i=0; i< sandwichesSize; i++)
    {
        if (sandwiches[i] == 0)
        {
            if (zeros == 0)
                return ones + zeros;
            zeros--;
        }

        else   //sandwiches=1
        {
                if (ones == 0)
                    return ones+zeros;
                ones--;
        }
    }
    return 0;
}