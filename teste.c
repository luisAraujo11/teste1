#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
int main(){
   int ret;
   struct tm info;
   char buffer[80];

   info.tm_year = 2005-1900;
   info.tm_mon = 3;
   info.tm_mday = 7;
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 0;
   info.tm_isdst = -1;

   ret = mktime(&info);
   if( ret == -1 ) {
      printf("Error: unable to make time using mktime\n");
   } else {

      //strftime(buffer, sizeof(buffer), "%c", &info );
      printf("%d\n",ret);
   }
    /*
    char *string,*final;

    string = strdup("ola;adeus;boa;tarde");

    while( (final = strsep(&string,";")) != NULL )
        printf("%s\n",final);

    return(0);
}
*/
/*
#include <stdio.h>
#include <time.h>

int main () {
   time_t rawtime;
   struct tm *info;
   char buffer[80];

   time( &rawtime );

   info = localtime( &rawtime );

   strftime(buffer,80,"%x - %I:%M%p", info);
   printf("Formatted date & time : %s\n", buffer );
  
   return(0);
}
*/
/*
int main() {
  time_t date1, date2;
   struct tm info;
   char buffer[80];

   info.tm_year = 2001 - 1900;
   info.tm_mon = 0;
   info.tm_mday = 1;
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 0;
   info.tm_isdst = -1;

   date1 = mktime(&info);
   printf("%ld",date1);

  double seconds = difftime(date1, date2);
  if (seconds > 0) {
    printf("Date1 > Date2\n");
  }

  return 0;
}
*/

int main(){

    int r=1;
    time_t date1, date2;
    struct tm my_tm;
    char buffer[80] ="1000000000 17:43:51";
    //char out_buffer[80];

    /* Convert the string to a struct tm. */
    memset (&my_tm, 0, sizeof(struct tm)); // memset(void *str, int c, size_t n) => copies the character c to the first n characters of the string pointed to, by the argument str.
    //printf("%d\n",&my_tm);
    strptime(buffer, "%Y-%b-%d %T", &my_tm); //2017-10-02 17:43:51
    printf("%s\n",buffer);

    /* Convert the struct tm to a time_t (to fill in the missing fields). */
    //printf("%s",buffer);
    date1 = mktime (&my_tm);
     printf("%ld\n",date1);
    //printf("%ld",date1);

  // char buffer[80];
   struct tm info;

   info.tm_year = 2005 - 1900;
   info.tm_mon = 3;
   info.tm_mday = 7;
   info.tm_hour = 0;
   info.tm_min = 0;
   info.tm_sec = 0;
   info.tm_isdst = -1;

   date2 = mktime(&info);
   //printf("%ld",date1);

  double seconds = difftime(date1, date2);
  //printf("%ld",date1);
  printf("%f\n",seconds);
  if (seconds < 0){
    r=0;
    //printf("Date1 > Date2\n");
  }
  printf("%d\n",r);
    return r;
}