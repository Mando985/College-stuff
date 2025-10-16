import java.util.Scanner;

public class attendance
{
    public static void main(String[] args)
    {
        Scanner scanner= new Scanner(System.in);
        System.out.println("Enter the number of students present: ");
        int num= scanner.nextInt();

        int[] roll= new int[num];

        for(int i=0; i<num; i++)
        {
            System.out.println("Enter the roll number of student "+(i+1));
            int buffer=scanner.nextInt();
            char f='a';
            if(buffer<=0)
            {
                System.out.println("Invalid Roll number !");
            }
            else if(buffer>0)
            {
                for(int j=0;j<num;j++)
                {
                    if(roll[j]==buffer)
                    {
                        System.out.println("Invalid! Duplicates arent allowed!");
                        i--;
                        f='b';
                        break;
                    }

                }
                if (f=='a')
                {
                    roll[i]=buffer;
                    System.out.println("added");
                }
            }
        }


        for(int i=0; i<num; i++)
        {
            for(int j=i+1; j<num;j++)
            {
                int buffer=0;
                if(roll[j]<roll[i])
                {
                    buffer=roll[i];
                    roll[i]=roll[j];
                    roll[j]=buffer;
                }
            }
        }



        System.out.println("students present: ");
        for(int i=0; i<num; i++)
        {
            System.out.print(roll[i]+" ");
        }


        char flag='f';
        while(flag=='f')
        {
            System.out.println("\nEnter the roll number of the student to see if they are present or not. Enter 0 to exit");
            int opt=scanner.nextInt();
            if(opt==0)
            {
                flag='t';
                System.out.println("Exiting.....");
            }
            else
            {
                char flag2='n';
                for(int i=0;i<num;i++)
                {
                    if(roll[i]==opt)
                    {
                        System.out.println("Yes the student is present");
                        flag2='y';

                    }
                    else if(i==num-1 &&flag2=='n')
                    {
                        System.out.println("Student is absent");
                        break;
                    }
                }
            }
        }
    }
}
