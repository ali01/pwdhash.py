#include <stdio.h>
#include <openssl/md5.h>

int main() {
  MD5_CTX    ctx,ctx1;

  unsigned char final[MD5_DIGEST_LENGTH];
  MD5_Init(&ctx);

         //input: one hundred char array, each char has the letter 'A'
  char pw[100];
  for( int i=0; i<100; i++)
      pw[i] = 'A';

  MD5_Update(&ctx, (char *)pw, 100);
  MD5_Final(final, &ctx);

  int count = 0;
  for( int i=0; i<MD5_DIGEST_LENGTH; i++)
  {
      printf( "%x", final[i] );
      if( (++count)%2 == 0 )
          printf( " " );
  }

  return 0;
}
