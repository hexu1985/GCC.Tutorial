#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define NLOOP_FOR_ESTIMATION 1000000000UL
#define NSECS_PER_MSEC 1000000UL
#define NSECS_PER_SEC 1000000000UL

static unsigned long nloop_per_resol;
static struct timespec start;

static inline long diff_nsec(struct timespec before, struct timespec after)
{
    return ((after.tv_sec * NSECS_PER_SEC + after.tv_nsec)
            - (before.tv_sec * NSECS_PER_SEC + before.tv_nsec));

}

static unsigned long estimate_loops_per_msec()
{
    struct timespec before, after;
    clock_gettime(CLOCK_MONOTONIC, &before);

    unsigned long i;
    for (i = 0; i < NLOOP_FOR_ESTIMATION; i++)
        ;

    clock_gettime(CLOCK_MONOTONIC, &after);

    return  NLOOP_FOR_ESTIMATION * NSECS_PER_MSEC / diff_nsec(before, after);
}

static inline void load(void)
{
    unsigned long i;
    for (i = 0; i < nloop_per_resol; i++)
        ;
}

static void child_fn(int id, struct timespec *buf, int nrecord)
{
    int i;
    for (i = 0; i < nrecord; i++) {
        struct timespec ts;

        load();
        clock_gettime(CLOCK_MONOTONIC, &ts);
        buf[i] = ts;
    }
    for (i = 0; i < nrecord; i++) {
        printf("%d\t%ld\t%d\n", id, diff_nsec(start, buf[i]) / NSECS_PER_MSEC, (i + 1) * 100 / nrecord);
    }
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "usage: %s <total[ms]> <resolution[ms]>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int total = atoi(argv[1]);
    int resol = atoi(argv[2]);

    if (total < 1) {
        fprintf(stderr, "<total>(%d) should be >= 1\n", total);
        exit(EXIT_FAILURE);
    }

    if (resol < 1) {
        fprintf(stderr, "<resol>(%d) should be >= 1\n", resol);
        exit(EXIT_FAILURE);
    }

    if (total % resol) {
        fprintf(stderr, "<total>(%d) should be multiple of <resolution>(%d)\n", total, resol);
        exit(EXIT_FAILURE);
    }
    int nrecord = total / resol;

    struct timespec *logbuf = malloc(nrecord * sizeof(struct timespec));
    if (!logbuf)
        err(EXIT_FAILURE, "failed to allocate log buffer");

    puts("estimating the workload which takes just one milli-second...");
    nloop_per_resol = estimate_loops_per_msec() * resol;
    puts("end estimation");
    fflush(stdout);

    clock_gettime(CLOCK_MONOTONIC, &start);

    child_fn(1, logbuf, nrecord);

    return 0;
}
