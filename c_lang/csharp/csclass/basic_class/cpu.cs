class cpu
{
    int modelno;
    double clock;
    double frequency;
    public class cores
    {
        int performance_cores;
        int efficiency_cores;

        cores()
        {
            performance_cores = 0;
            efficiency_cores = 0;
        }

        cores(int pcores, int ecores)
        {
            pcores = performance_cores;
            ecores = efficiency_cores;
        }
    }

    public cpu()
    {
        modelno = 0;
        clock = 0;
        frequency = 0;
    }

    public void printCpuInfo()
    {
        Console.WriteLine(this.modelno);
        Console.WriteLine(this.clock);
        Console.WriteLine(this.frequency);
    }
}