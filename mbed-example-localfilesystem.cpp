
#include <mbed.h>

LocalFileSystem local("local"); // Create the local filesystem under the name "local"

// Workaround for errata on LPC1768:
// If the RTOS idle thread runs, it sends the MCU to sleep, which breaks the semihosting
// connection, which breaks LocalFileSystem.
// See here: https://github.com/mbed-ce/mbed-os/wiki/MCU-Info-Page:-LPC1768
[[noreturn]] void sleeplessIdleFunc()
{
	while(true) {}
}

int main()
{
#ifdef MBED_CONF_RTOS_API_PRESENT
    Thread sleeplessIdleThread(osPriorityLow, OS_STACK_SIZE, nullptr, "Sleepless Idle Thread");
    sleeplessIdleThread.start(&sleeplessIdleFunc);
#endif

    printf(">> mbed-example-localfilesystem start!\n");

    printf(">> Appending an additional line to out.txt.\n");

    // Open "out.txt" on the local file system for appending
    FILE *fp = fopen("/local/out.txt", "a");
    fprintf(fp, "Hello World!\n");
    fclose(fp);

    // Read current contents of out.txt
    printf(">> out.txt contains: \n");
    fp = fopen("/local/out.txt", "r");

    const size_t lineBufferSize = 128;
    char lineBuffer[lineBufferSize];
    while(fgets(lineBuffer, lineBufferSize, fp) != nullptr)
    {
        printf("%s", lineBuffer);
    }
    fclose(fp);

    // Opens the root directory of the local file system
    DIR *d = opendir("/local");

    // Print the names of the files in the local file system to stdout.
    struct dirent *p;
    printf(">> Contents of the LocalFileSystem:\n");
    while((p = readdir(d)) != nullptr)
    {
      printf(" - %s\n", p->d_name);
    }
    closedir(d);

    while(true)
    {}
}