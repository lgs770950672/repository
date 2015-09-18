#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef WIN32
	#include <windows.h>
	typedef __int64 int64_t;
	#define sleep(t) Sleep(t*1000)
	#define usleep(t) Sleep((t)/1000)
#else
	#include <sys/time.h>
#endif

#ifdef WIN32
int gettimeofday(struct timeval *tp, void *tzp)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;
	GetLocalTime(&wtm);
	tm.tm_year     = wtm.wYear - 1900;
	tm.tm_mon     = wtm.wMonth - 1;
	tm.tm_mday     = wtm.wDay;
	tm.tm_hour     = wtm.wHour;
	tm.tm_min     = wtm.wMinute;
	tm.tm_sec     = wtm.wSecond;
	tm. tm_isdst    = -1;
	clock = mktime(&tm);
	tp->tv_sec = clock;
	tp->tv_usec = wtm.wMilliseconds * 1000;
	return (0);
}
#endif

int64_t av_gettime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (int64_t)tv.tv_sec * 1000000 + tv.tv_usec;
}

int main(void)
{
	int64_t end_time = 0;
	int64_t start_time = av_gettime();
	int64_t t = 3000000;
	int i = 10;
	while (i)
	{
  	sleep(2);
  	end_time = av_gettime();
  	if ((end_time-start_time) < t)
	  {
    	//printf("%lld\n", t-(end_time - start_time));
    	usleep( t- (end_time - start_time) );			
		}

		start_time = av_gettime();
		i--;
	}
	system("pause");
	return 0;
}
