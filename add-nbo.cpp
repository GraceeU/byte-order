#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

uint32_t htonl(uint32_t n);

int main(void){
	FILE *rfp, *rfp1, *wfp,*wfp1;
	char buf[257]={0,}, buf1[257]={0,};
	int len, len1;

	if((rfp = fopen("thousand.bin","r"))==NULL){
		perror("fopen: thousand.bin");
		exit(1);
	}

	if((wfp = fopen("aa.bin","w"))==NULL){
                perror("fopen: aa.bin");
                exit(1);
        }


	while((len=fread(buf,1,256,rfp))>0){
                buf[len] = '\0';
                fwrite(buf,1,len,wfp);
                printf("%s\n",buf);
        }
        
	
	if((rfp1= fopen("five.bin","r"))==NULL){
		perror("fopen: five.bin");
		exit(1);
	}

	

	

	if((wfp1 = fopen("bb.bin","w"))== NULL){
		perror("fopen: bb.bin");
		exit(1);
	}
	
	
	
	while((len1=fread(buf1,1,256,rfp1))>0){
                buf1[len1] = '\0';
                fwrite(buf1,1,len1,wfp1);
		printf("%s\n",buf1);
        }
	

	uint32_t* p = reinterpret_cast<uint32_t*>(buf);
	uint32_t* p1 = reinterpret_cast<uint32_t*>(buf1);
	
	uint32_t n = htonl(*p);
	uint32_t n1= htonl(*p1);
	printf("%d(0x%x)+%d(0x%x) = %d (0x%x)\n ", n,n,n1 ,n1,n+n1, n+n1);


	fclose(rfp);
	fclose(wfp);
	fclose(rfp1);
	fclose(wfp1);
}



uint32_t htonl(uint32_t n){
        return (n & 0xFF000000) >>24 | (n & 0x00FF0000) >>8 |(n & 0x0000FF00) << 8 | (n & 0x000000FF) >> 24 ;
}

